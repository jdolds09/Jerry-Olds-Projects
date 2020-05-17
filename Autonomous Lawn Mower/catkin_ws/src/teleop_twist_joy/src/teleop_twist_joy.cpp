/**
Software License Agreement (BSD)
\authors   Mike Purvis <mpurvis@clearpathrobotics.com>
\copyright Copyright (c) 2014, Clearpath Robotics, Inc., All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that
the following conditions are met:
 * Redistributions of source code must retain the above copyright notice, this list of conditions and the
   following disclaimer.
 * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the
   following disclaimer in the documentation and/or other materials provided with the distribution.
 * Neither the name of Clearpath Robotics nor the names of its contributors may be used to endorse or promote
   products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WAR-
RANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, IN-
DIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT
OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "geometry_msgs/Twist.h"
#include "ros/ros.h"
#include "sensor_msgs/Joy.h"
#include "teleop_twist_joy/teleop_twist_joy.h"
#include "std_msgs/Bool.h"

#include <map>
#include <string>
#include <chrono>
#include <thread>


namespace teleop_twist_joy
{

/**
 * Internal members of class. This is the pimpl idiom, and allows more flexibility in adding
 * parameters later without breaking ABI compatibility, for robots which link TeleopTwistJoy
 * directly into base nodes.
 */
struct TeleopTwistJoy::Impl
{
  // Callback function for joy data
  void joyCallback(const sensor_msgs::Joy::ConstPtr& joy);
  // Callback function for autonomous mode data
  void autoCallback(const std_msgs::Bool::ConstPtr& auto_msg);
  // Function to switch vehicle back to manual mode
  void switch_mode();

  ros::Subscriber joy_sub; // Joy subscriber
  ros::Subscriber auto_sub; // Autonomous mode subscriber
  ros::Publisher cmd_vel_pub; // Manual mode speed values publisher
  ros::Publisher manual_pub; // Manual mode data publisher
  ros::Publisher blade_pub; // Publish status of lawn mower blade [OFF, ON]

  int enable_button; // Pause button
  int blade_button;
  int counter = 0; // Counter used to see how long mode switch button has been pressed
  bool enable_button_enabled = false; // If pause button is being pressed, used for debouncing
  bool blade_button_enabled = false; // If blade button is being pressed, used for debouncing
  bool system_paused = false; // Set to true if pause button is pressed
  bool blades_on = false; // Set to true if lawn mower blades have been turned on
  bool mode_switch = false; // Set to true if mode switch button is held for 3+ seconds
  bool auto_mode = false; // Vehicle starts in manual mode, set to true if vehicle is switched to autonomous mode
  bool recent_change = false; // If vehicle has recently changed modes,
							  // used to prevent vehicle from constantly switching modes if button is held

  std::map<std::string, int> axis_linear_map_l; // Set left wheel button on controller
  std::map<std::string, int> axis_linear_map_r; // Set right wheel button on controller
  std::map<std::string, double> scale_linear_map; // Set scaling value for speed based on position of analog stick

  bool sent_disable_msg;
};

/**
 * Constructs TeleopTwistJoy.
 * \param nh NodeHandle to use for setting up the publisher and subscriber.
 * \param nh_param NodeHandle to use for searching for configuration parameters.
 */
TeleopTwistJoy::TeleopTwistJoy(ros::NodeHandle* nh, ros::NodeHandle* nh_param)
{
  pimpl_ = new Impl;

  // Initialize publishers and subscribers
  pimpl_->cmd_vel_pub = nh->advertise<geometry_msgs::Twist>("cmd_vel", 1, true);
  pimpl_->manual_pub = nh->advertise<std_msgs::Bool>("manual_mode", 1, true);
  pimpl_->joy_sub = nh->subscribe<sensor_msgs::Joy>("joy", 1, &TeleopTwistJoy::Impl::joyCallback, pimpl_);
  pimpl_->auto_sub = nh->subscribe<std_msgs::Bool>("autonomous_mode", 1, &TeleopTwistJoy::Impl::autoCallback, pimpl_);
  pimpl_->blade_pub = nh->advertise<std_msgs::Bool>("blades", 1, true);

  // Set enable_button to pause button on xbox controller
  nh_param->param<int>("enable_button", pimpl_->enable_button, 7);
  // Set lawn mower blade button to 'X' button on xbox controller
  nh_param->param<int>("blade_button", pimpl_->blade_button, 2);

  if (nh_param->getParam("axis_linear", pimpl_->axis_linear_map_l))
  {
    nh_param->getParam("axis_linear", pimpl_->axis_linear_map_l);
    nh_param->getParam("scale_linear", pimpl_->scale_linear_map);
  }
  else
  {
	// Set left wheel speed to left analog stick on xbox controller
    nh_param->param<int>("axis_linear", pimpl_->axis_linear_map_l["x"], 1);
    nh_param->param<double>("scale_linear", pimpl_->scale_linear_map["x"], 1);
  }
  
  if (nh_param->getParam("axis_linear", pimpl_->axis_linear_map_r))
  {
    nh_param->getParam("axis_linear", pimpl_->axis_linear_map_r);
    nh_param->getParam("scale_linear", pimpl_->scale_linear_map);
  }
  else
  {
	// Set right wheel speed to right analog stick on xbox controller
    nh_param->param<int>("axis_linear", pimpl_->axis_linear_map_r["x"], 4);
    nh_param->param<double>("scale_linear", pimpl_->scale_linear_map["x"], 1);
  }

  // Debug info
  ROS_INFO_NAMED("TeleopTwistJoy", "Teleop enable button %i.", pimpl_->enable_button);
  ROS_INFO_NAMED("TeleopTwistJoy", "Teleop blade button %i.", pimpl_->blade_button);

  for (std::map<std::string, int>::iterator it = pimpl_->axis_linear_map_l.begin();
      it != pimpl_->axis_linear_map_l.end(); ++it)
  {
    ROS_INFO_NAMED("TeleopTwistJoy", "Linear axis %s on %i at scale %f.",
    it->first.c_str(), it->second, pimpl_->scale_linear_map[it->first]);
  }
  
  for (std::map<std::string, int>::iterator it = pimpl_->axis_linear_map_r.begin();
      it != pimpl_->axis_linear_map_r.end(); ++it)
  {
    ROS_INFO_NAMED("TeleopTwistJoy", "Linear axis %s on %i at scale %f.",
    it->first.c_str(), it->second, pimpl_->scale_linear_map[it->first]);
  }

  pimpl_->sent_disable_msg;

  
}

// Check if vehicle mode has been switched from autonomous mode to manual mode
void TeleopTwistJoy::Impl::autoCallback(const std_msgs::Bool::ConstPtr& auto_msg)
{
	auto_mode = auto_msg->data;
	if(!auto_mode)
	{
		counter = 0;
		switch_mode();
    }
}


// Switch mode back to manual mode
void TeleopTwistJoy::Impl::switch_mode()
{
	std_msgs::Bool manual_mode;

	manual_mode.data = true;
	recent_change = true;

	manual_pub.publish(manual_mode);
}


void TeleopTwistJoy::Impl::joyCallback(const sensor_msgs::Joy::ConstPtr& joy_msg)
{ 
  // Initializes with zeros by default.
  geometry_msgs::Twist cmd_vel_msg;
  std_msgs::Bool manual_mode;
  std_msgs::Bool blades;

  // Change state of blades if blade button is pressed.
  if(joy_msg->buttons[blade_button] && !blade_button_enabled)
  {
    blade_button_enabled = true;
    if(blades_on)
        blades_on = false;
    else
        blades_on = true;
 
    blades.data = blades_on;   
    blade_pub.publish(blades);
  }

  // If blade button is released, used for debouncing
  if(!joy_msg->buttons[enable_button] && enable_button_enabled)
	blade_button_enabled = false;
  
  // Change state of pause if pause button is pressed.
  if(joy_msg->buttons[enable_button] && !enable_button_enabled)
  {
    enable_button_enabled = true;
    if(system_paused)
  		system_paused = false;
    else
		system_paused = true;
  }

  // If pause button is released, used for debouncing
  if(!joy_msg->buttons[enable_button] && enable_button_enabled)
	enable_button_enabled = false;

  // If mode button is released, this will prevent vehicle from switching modes
  // if mode switch button is held for less than 3 seconds and also will prevent
  // vehicle from constantly switching modes if button is constantly held
  if(!joy_msg->buttons[8])
  {
	counter = 0;
	recent_change = false;
  }

  // If mode switch button is being pressed 
  if(joy_msg->buttons[8] && !auto_mode && !recent_change)
  	counter++;

  // If mode button has been held for 3+ seconds, being to switch to autonomous mode
  if(counter >= 15)
  {
	counter = 0;
	mode_switch = true;
  }

  // If mode has been switched from manual to autonomous
  if(mode_switch)
  {
    mode_switch = false;
	cmd_vel_msg.linear.x = 0;
    cmd_vel_msg.linear.y = 0;
    manual_mode.data = false;
    cmd_vel_pub.publish(cmd_vel_msg);
    manual_pub.publish(manual_mode);
	auto_mode = true;
  }

  // If vehicle is not paused and vehicle is in manual mode, publish speed values
  if (!system_paused && auto_mode == false)
  {
    if  (axis_linear_map_l.find("x") != axis_linear_map_l.end())
    {
      cmd_vel_msg.linear.x = joy_msg->axes[axis_linear_map_l["x"]] * scale_linear_map["x"];
    }
    if  (axis_linear_map_r.find("x") != axis_linear_map_r.end())
    {
      cmd_vel_msg.linear.y = joy_msg->axes[axis_linear_map_r["x"]] * scale_linear_map["x"];
    }
	
    cmd_vel_pub.publish(cmd_vel_msg);
    sent_disable_msg = false;
  }
  
  // Vehicle is paused, publish speed values = 0
  else if (system_paused && auto_mode == false)
  {
    // If system is paused, send empty messages to Arduino
    if (!sent_disable_msg)
    {
      cmd_vel_pub.publish(cmd_vel_msg);
      sent_disable_msg = true;
	  //manual_pub.publish(manual_mode);
    }
  }

  // Vehicle is in autonomous mode, publish speed values = 0
  else
  { 
      cmd_vel_pub.publish(cmd_vel_msg);
	  //manual_pub.publish(manual_mode);
  }
}

}  // namespace teleop_twist_joy
