#! /usr/bin/env python
import rospy
import math
import re
import sys
import os
import subprocess
import threading
import time
import statistics

from sensor_msgs.msg import NavSatFix
from geometry_msgs.msg import Twist
from std_msgs.msg import Float32
from std_msgs.msg import Int32
from std_msgs.msg import Bool
from sensor_msgs.msg import Joy

# Counter for goal waypoints
goal_index = 0

# Wheel speed scaling
r_wheel_scale = 0
l_wheel_scale = 0

# Get array of waypoints
fName = sys.argv[1]
waypoints = []

# Get GPS data
curr_lat = 0
curr_long = 0

# Get compass heading
heading = 0

# Stop vehicle variables
pause_button = 7
stop_vehicle = False
pause_button_pressed = False

# Switch mode variables
counter = 0
mode_button = 8
manual_mode = True
switch_mode = False
recent_change = False

# Get current goal index
current_goal_index = 0

# Format file to read waypoints
with open( fName, 'r' ) as fp:
	lines = fp.read().split( '\n' )

for n in range(1, len(lines)-1):
	coords = lines[n].split('\t')
	waypoints.append([float(coords[8]), float(coords[9])])

fp.close()

#Get GPS data
def GPS_callback(msg):
	global curr_lat, curr_long, goal_lat, goal_long, goal_index
	curr_lat = msg.latitude
	curr_long = msg.longitude

	# Debug Info
	#print("Goal Latitude: %f" % waypoints[goal_index][0])
	#print("Goal Longitude: %f" % waypoints[goal_index][1])
	#print("Current Latitude: %f" % curr_lat)
	#print("Current Longitude: %f" % curr_long)
	#print("\n")


# Get compass data
def compass_callback(msg):
	global heading
	heading = msg.data


# Get controller data
def joy_callback(msg):
	global pause_button_pressed, stop_vehicle, switch_mode, manual_mode, counter, pause_button
	global mode_button, recent_change

	# Pause button pressed
	if(msg.buttons[pause_button] and not(pause_button_pressed)):
		pause_button_pressed = True
		if(stop_vehicle):
			stop_vehicle = False
		else:
			stop_vehicle = True

	# Pause button released, this is used to debounce the pause button
	if(not(msg.buttons[pause_button]) and pause_button_pressed):
		pause_button_pressed = False

	# Mode button released, recent_change makes it so the vehicle won't keep switching modes if mode swtich button is held
	if(not(msg.buttons[mode_button])):
		recent_change = False
		counter = 0

	# Mode button is being pressed
	if(msg.buttons[mode_button] and not(manual_mode) and not(recent_change)):
		counter = counter + 1

	# If mode button has been held for 3+ seconds, switch modes
	if(counter >= 15):
		counter = 0
		activate_manual()


# See if vehicle is in manual mode
def manual_callback(msg):
	global manual_mode, counter

	manual_mode = msg.data
	if(not(manual_mode)):
		counter = 0
		activate_autonomous()


# Switch vehicle mode to manual mode
def activate_manual():
	autonomous_mode.data = False
	pub2.publish(autonomous_mode)


# Switch vehicle to autonomous mode
def activate_autonomous():
	global recent_change

	recent_change = True
	autonomous_mode.data = True
	pub2.publish(autonomous_mode)


# Take current lat/long and goal lat/long,
# calculate distance (meters) and theta (rads)
def goalVector(curr_lat, curr_long, goal_lat, goal_long):

	# Get vector components
	vec_x = goal_lat - curr_lat
	vec_y = goal_long - curr_long

	# Calculate distance from goal and theta
	quadrant = 1
	if(vec_x < 0 and vec_y < 0):
		quadrant = 3
	elif(vec_x < 0):
		quadrant = 2
	elif(vec_y < 0):
		quadrant = 4

	# Convert latitude and logitude values to radian
	curr_lat_rad = (math.pi / 180) * curr_lat
	curr_long_rad = (math.pi / 180) * curr_long
	goal_lat_rad = (math.pi / 180) * goal_lat
	goal_long_rad = (math.pi / 180) * goal_long

	vec_x = goal_lat_rad - curr_lat_rad
	vec_y = goal_long_rad - curr_long_rad

	# Haversine Formula to calculate distance given two sets of GPS coordinates
	distance = ((math.sin(vec_x / 2)) ** 2) + math.cos(curr_lat_rad) * math.cos(goal_lat_rad) * ((math.sin(vec_y / 2)) ** 2)

	distance = 2 * math.asin(math.sqrt(distance))

	# Convert distance to (m)
	distance = (distance * 6371) * 1000

	theta = math.atan(vec_y/vec_x)

	# Add degree according to quadrant
	if(quadrant == 2 or quadrant == 3):
		theta = theta + math.pi
	elif(quadrant == 4):
		theta = theta + (2 * math.pi)

	# Convert to degrees
	theta = math.degrees(theta)

	return [distance, theta]

# return angle difference
# Diff < 0 == CW, else CCW
def getError(curr_dir, goal_dir):
	diff = goal_dir - curr_dir

	if(abs(diff) > 180):
		if(diff > 0):
			diff = goal_dir - (curr_dir + 360)
		else:
			diff = (goal_dir + 360) - curr_dir

	return diff

# Run Autonomous
def main():

	# Variables
	global goal_index, waypoints, heading, curr_lat, curr_long, stop_vehicle, manual_mode

	goal_radius = 1.5 # if vehicle is within 1.5 (m) of waypoint, proceed to next waypoint
	max_speed = .78

	# PID constant values
	Kp = 0.00555556
<<<<<<< HEAD
	Ki = 0.00008
	Kd = 0.0004
=======
	Ki = 0.0001
	Kd = 0.0008
>>>>>>> 1aa79307b62c2871a87ebea81505005db3d81155

	errorList = [0] * 5 	# Running window of last 5 diffs for Kd
	se = 0 					# Running sum of errors for Ki

	# While vehicle has not reached all waypoints
	while(goal_index < len(waypoints)):

		# Get goal latitude and longitude
		goal_lat = float(waypoints[goal_index][0])
		goal_long = float(waypoints[goal_index][1])

		# Don't make GPS calculations if GPS hasn't booted up yet
		while(curr_lat == 0 and curr_long == 0):
			time.sleep(.1)

		# calculate distance and theta to goal
		[gdistance, gtheta] = goalVector(curr_lat, curr_long, goal_lat, goal_long)
		# Calculate theta and direction to turn
		diff = getError(heading, gtheta)

################## TURN PHASE (turn while difference of gtheta and heading are > 3 deg) #################################
		while(not(heading <= (gtheta + 3) and heading >= (gtheta - 3))):

			[gdistance, gtheta] = goalVector(curr_lat, curr_long, goal_lat, goal_long)
			diff = getError(heading, gtheta)

			# If pause button is pressed, stop vehicle
			while(stop_vehicle):
				auto_vel.linear.x = 0
				auto_vel.linear.y = 0
				pub.publish(auto_vel)
				time.sleep(.1)

			# Print goal and current headings and distance from goal
			print("Heading: %f" % heading)
			print("Goal Distance: %f" % gdistance)
			print("Goal Theta: %f" % gtheta)
			print("Theta Difference: %f" % diff)
			print("Turn: %s" % "Clockwise" if (diff < 0) else "Counter-Clockwise")
			print("\n")

			# Keep a list of headings of size 5 to calculate derivative
			errorList.append(diff)
			errorList.pop(0)

			# Derivative of diff
			de = statistics.median(errorList)

			# Integral of diff (running sum)
			if(not(manual_mode)):
				se = se + diff

			#apply PID Formula
			U = (Kp*diff) + (Ki*se) + (Kd*de)

			if(U > 0.763):
				U = 0.763

			if(U < -0.763):
				U = -0.763

			# Create speed value
			speed = abs(U)

			# Send speed value to Arduino
			if(U > 0):
				auto_vel.linear.x = speed
				auto_vel.linear.y = -speed
			else:
				auto_vel.linear.x = -speed
				auto_vel.linear.y = speed

			pub.publish(auto_vel)
			time.sleep(0.05) # Sleep .05 second so that Arduino isn't overflowed with messages

		# Vehicle is facing waypoint, stop vehicle for 3 seconds before proceeding to waypoint
		auto_vel.linear.x = 0
		auto_vel.linear.y = 0
		errorList = [0] * 5
		se = 0
		de = 0
		for i in range(30):
			time.sleep(.1)
			pub.publish(auto_vel)

################################ MOVE PHASE ##################################################
		while(gdistance > goal_radius):

			print("Distance: %f" % gdistance)

			# If pause button is pressed, stop vehicle
			while(stop_vehicle):
				auto_vel.linear.x = 0
				auto_vel.linear.y = 0
				pub.publish(auto_vel)
				time.sleep(.1)

			[gdistance, gtheta] = goalVector(curr_lat, curr_long, goal_lat, goal_long)
			diff = getError(heading, gtheta)

			# Keep a list of headings of size 5 to calculate derivative
			errorList.append(diff)
			errorList.pop(0)

			print("Diff: %f" % diff)

			# Derivative of diff
			de = statistics.median(errorList)

			# Integral of diff (running sum)
			if(not(manual_mode)):
				se = se + diff

			# PID Formula
			U = (Kp*diff)+(Ki*se)+(Kd*de)

			if(manual_mode):
				U = 0

			if(abs(U) > 100):
				se = 0

			print ("U: %f" % U)

			if(U > 1):
				U = 1

			if(U < -1):
				U = -1

			# Get lower speed for turning
			if(U > 0):
				low_speed = (1 - U) * max_speed
			else:
				low_speed = (1 + U) * max_speed

			# U < 0 == CW, else CCW
			if (U > 0.05):
				auto_vel.linear.x = max_speed
				auto_vel.linear.y = low_speed
			elif(U < -0.05):
				auto_vel.linear.x = low_speed
				auto_vel.linear.y = max_speed
			else:
				auto_vel.linear.x = max_speed
				auto_vel.linear.y = max_speed

			pub.publish(auto_vel)
			time.sleep(.05) # Sleep vehicle for .1 seconds so that Arduino isn't overflowed with messages

		# Vehicle reached desired waypoint, stop vehicle for 3 seconds before turning towards next waypoint
		auto_vel.linear.x = 0
		auto_vel.linear.y = 0
		errorList = [0] * 5
		se = 0
		de = 0

		for i in range(30):
			time.sleep(.1)
			pub.publish(auto_vel)

		# Load next goal
		goal_index = goal_index + 1

# Create waypoint ROS node
rospy.init_node('follow_waypoints')
# Subscribe to GPS data
sub = rospy.Subscriber('ublox_gps/fix', NavSatFix, GPS_callback)
# Subscribe to compass data
sub2 = rospy.Subscriber('compass_heading', Float32, compass_callback)
# Subcsribe to controller data
sub3 = rospy.Subscriber('joy', Joy, joy_callback)
# Subscribe to manual mode data to see if vehicle is in manual mode
sub4 = rospy.Subscriber('manual_mode', Bool, manual_callback)
# Publish autonomous speeds
pub = rospy.Publisher('auto_vel', Twist, queue_size=10)
# Publish autonomous mode data
pub2 = rospy.Publisher('autonomous_mode', Bool, queue_size=10)

auto_vel = Twist()
autonomous_mode = Bool()
current_goal_index = Int32()
main()
rospy.spin()
