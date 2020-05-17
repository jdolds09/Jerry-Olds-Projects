#include <Adafruit_ADXL343.h>

#include <Adafruit_I2CRegister.h>
#include <Adafruit_SPIDevice.h>
#include <Adafruit_I2CDevice.h>
#include <Adafruit_BusIO_Register.h>


#include <Adafruit_LSM303.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>
#include <ros.h>
#include <std_msgs/Float32.h>
#include <geometry_msgs/Twist.h>
#include <std_msgs/Bool.h>
#include <timer.h>

// SERIAL COMMUNICATION
#define ROS_SERIAL_BAUD_RATE 115200

// MOTORS
#define E1 3   // Enable Pin for motor 1 left or right to be determined 
#define E2 6    // Enable Pin for motor 2 left or fight to be determined 
#define I1 1    // Control pin 1 for motor 1 to go forward 
#define I2 2    // Control pin 2 for motor 1 to go reverse
#define I3 7    // Control pin 1 for motor 2 to go forward 
#define I4 5   // Control pin 2 for motor 2 to go reverse

// *** TODO: Assign pins for blade control here ***


/* Assign a unique ID to this sensor at the same time */
Adafruit_LSM303_Mag_Unified mag = Adafruit_LSM303_Mag_Unified(12345);

ros::NodeHandle nh;

// Variable to store speed values
geometry_msgs::Twist twist_msg;
// Variable to store compass heading value
std_msgs::Float32 compass_heading;
// Variable to store blade status
std_msgs::Bool blade_status;

// The PWM values we are going to use
double lspeed = 0;
double rspeed = 0;
//setting up timer
auto timer = timer_create_default();
int off=1;

// See if going forward
bool lforward = false;
bool rforward = false;

// Stop vehicle function
void shut_down()
{
  analogWrite(E1, 0);  // Set left motor speed
  analogWrite(E2, 0);  // Set right motor speed
  off=0;
  timer = timer_create_default();
}

void MotorSpeeds(float left, float right) {

  // Raise values -0.5 - +0.5 with a factor of 255
  // So that we can have useful PWM values (0-255)
  // Perhaps, we could do a map() here instead.
  
  lspeed = left*255;
  rspeed = right*255;
  
  analogWrite(E1, (abs(rspeed)*.5)+127);  // Set left motor speed, *.5 + 127 for scaling
  analogWrite(E2, (abs(lspeed)*.5)+127);  // Set right motor speed, *.5 + 127 for scaling

  // Motor direction is determined based on the sign of the left,right values
  // Set direction of the motors based on the sign of the speed
  if ( left >= 0 ) {
    digitalWrite(I1, HIGH);
    digitalWrite(I2, LOW);
  } else {
    digitalWrite(I1, LOW);
    digitalWrite(I2, HIGH);
  }
  if ( right >= 0 ) {
    digitalWrite(I3, HIGH);
    digitalWrite(I4, LOW);
  } else {
    digitalWrite(I3, LOW);
    digitalWrite(I4, HIGH);
  }

}

////////////////////////////////////////////////////////////
// Motor drive
// cmd_x  : linear x velocity (forward velocity) m/s
// cmd_th : angular z velocity (rotation of heading) rad/s
void diff_drive(float cmd_x_l, float cmd_x_r) {
  
  char log_msg[200];
  // dtostrf(floatVar, minStringWidthIncDecimalPoint, numVarsAfterDecimal, charBuf);
  dtostrf(cmd_x_l*255, 1, 4, log_msg);
  nh.loginfo(log_msg);

  dtostrf(cmd_x_r*255, 1, 4, log_msg);
  nh.loginfo(log_msg);

  // Calculate speed to send to the motors.
  MotorSpeeds(cmd_x_l*off, cmd_x_r*off);
}

// The callback function
void cmd_vel_callback(const geometry_msgs::Twist& twist_msg) {
  //nh.loginfo("callback running\n");
  timer = timer_create_default();
  off=1;

  diff_drive(twist_msg.linear.x, twist_msg.linear.y);
}

void blade_callback(const std_msgs::Bool& blade_status)
{
  // *** TODO: Assign values to pins to make blades spin or turn off
  //           based on value of blade_status (false, true) ***
}

// Subscribe to vehicle speed values
ros::Subscriber<geometry_msgs::Twist> cmd_vel_topic("safe_vel", &cmd_vel_callback);
// Publish compass data
ros::Publisher publish_heading("compass_heading", &compass_heading);
// Subscribe to blade control
ros::Subscriber<std_msgs::Bool> blade_control("blades", &blade_callback);

// Setup the pin numbers.
// *** TODO: Setup blade pins ***
void setupPins() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(E1, OUTPUT);
  pinMode(E2, OUTPUT);
  pinMode(I1, OUTPUT);
  pinMode(I2, OUTPUT);
  pinMode(I3, OUTPUT);
  pinMode(I4, OUTPUT);
}

void setup() {
// Compass setup
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
  Serial.begin(115200);
  Serial.println("Magnetometer Test"); Serial.println("");

  nh.getHardware()->setBaud(ROS_SERIAL_BAUD_RATE);
  nh.initNode();
  nh.subscribe(cmd_vel_topic); // Subscribe to speed values
  nh.advertise(publish_heading); // Publish compass data
  nh.loginfo("Serial setup complete");
  
  setupPins();
  nh.loginfo("Pins setup complete");

  /* Enable auto-gain */
  mag.enableAutoRange(true);

  // Wait until compass is working
  if(!mag.begin())
  {
    while(1);
  }

  // If ROS node disconnects
  while(!nh.connected())
  {
    nh.spinOnce();
  }
  
  
  //timer.every(500,shut_down);
}


void loop() {
  sensors_event_t event;
  mag.getEvent(&event);
 
  float Pi = 3.14159;
  
  // Calculate the angle of the vector y,x
  float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;

  // Normalize to 0-360
  if (heading < 0)
  {
    heading = 360 + heading;
  }

  // Store and publish compass data
  compass_heading.data = heading;
  publish_heading.publish(&compass_heading);
  
  timer.tick();
  if(off == 1)
  {
    nh.spinOnce();
    timer.in(1000,shut_down);
  }
  if(off == 0)
  {
    timer.every(1000, nh.spinOnce());
  }
}
