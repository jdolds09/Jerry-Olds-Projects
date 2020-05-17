#! /usr/bin/env python

import rospy
import math
import time

from sensor_msgs.msg import LaserScan
from geometry_msgs.msg import Twist
from std_msgs.msg import Bool

# Set distance for each wall of box
right_wall = 0.35
front_wall = 0.5
left_wall = 0.35

# Get angle increment for each LIDAR ray (radians)
angle_inc = 0.00871450919658
# Initial angle
init_angle = -3.12413907051

# Create list of minimum ranges to compare to
min_range = []

# Run first time setup for lidar
setup = False

# Stop vehicle if ture
unsafe = False

# Timers
tic = 0
toc = 0

# Vehicle mode
manual_mode = True

# Get LIDAR data and determine if it is safe for vehicle to continue
def LIDAR_callback(msg):
	global unsafe, tic, right_wall, front_wall, left_wall, angle_inc, init_angle, angle_min, angle_max, min_range, setup

	# Start clock, this is used to detect if LIDAR stops working. If LIDAR stops working the vehicle will stop
	tic = time.clock()

	# Calculate minimum distances that objects can be from the vehicle
	if(setup != True):

		# Create list of min_range
		for i in range(len(msg.ranges)):

			# Find angle of current LIDAR ray
			angle = init_angle + (i * angle_inc)

			# RPLidar S1 starts north at -PI and goes 360 to PI counterclockwise
			# Transpose to old lidar range (start at north, 0 to pi)
			# 0 out any readings greater than the 180 angle
			if(angle <= -(math.pi / 2)):
				angle = angle + ((3*math.pi)/2)
			elif(angle <= (math.pi / 2)):
				angle = 0
				min_range.append(0)
				continue
			else:
				angle = angle + -(math.pi / 2)

			# Calculate distance to each wall, from right to left
			if(angle == math.pi / 2):
				left_dist = front_wall*10
				right_dist = front_wall*10
				front_dist = front_wall
			elif(angle < math.pi / 2):
				right_dist = math.sqrt((right_wall * math.tan(angle))**2 + right_wall**2)

				if(front_wall * math.tan(angle) != 0):
					front_dist = math.sqrt(front_wall * (1/(math.tan(angle)))**2 + front_wall**2)
				else:
					front_dist = front_wall*10

				left_dist = front_wall*10
			else:
				angle = (math.pi-angle)

				right_dist = front_wall*10

				if(front_wall * math.tan(angle) != 0):
					front_dist = math.sqrt(front_wall * (1/(math.tan(angle)))**2 + front_wall**2)
				else:
					front_dist = front_wall*10

				left_dist = math.sqrt((left_wall * math.tan(math.pi-angle))**2 + left_wall**2)

			# Append the smallest range
			min_range.append(min(right_dist, front_dist, left_dist))

		# Print out ranges
		#print(min_range)
		# print(max(min_ranges))

		# End setup
		setup = True

	stop_vehicle = False
	counter = 0

	# If an object violates minimum distance from LIDAR, stop the vehicle
	for i in range(len(msg.ranges)):
		print ("[",i,"] ", msg.ranges[i])
		print ("[",i,"] ", min_range[i])
		if msg.ranges[i] < min_range[i]:
			counter = counter + 1
			if counter >= 3:
				stop_vehicle = True
		else:
			counter = 0

	unsafe = stop_vehicle


# Get the mode of the vehicle, manual_mode == True when in manual mode and False when in autonomous mode
def mode_callback(msg):
	global manual_mode

	manual_mode = msg.data

# Send manual speed values to move_vehicle when in manual mode
def manual_callback(msg):
	global manual_mode

	if(manual_mode):
		move_vehicle(msg.linear.x, msg.linear.y)


# Send autonomous speed values to move_vehicle when in autonomous mode
def auto_callback(msg):
	global manual_mode

	if(not(manual_mode)):
		move_vehicle(msg.linear.x, msg.linear.y)


# Publish speed values to Arduino if LIDAR is not violated
def move_vehicle(left_wheel_speed, right_wheel_speed):
	global unsafe, tic, toc

	#Stop running if lidar node has not responded
	toc = time.clock()
	#print("tic: %f" % tic)
	#print("toc: %f" % toc)
	#print("tictoc: %f" % (toc-tic))

	# LIDAR not responding, stop vehicle
	if(toc - tic >= 0.3):
		safe_vel.linear.x = 0
		safe_vel.linear.y = 0
	
	# LIDAR is not violated, send speed values to Arduino
	elif(not unsafe):
		safe_vel.linear.x = left_wheel_speed
		safe_vel.linear.y = right_wheel_speed

	# LIDAR is violated, only acceptable movement is straight backwards
	else:
		lforward = left_wheel_speed >= 0
		rforward = right_wheel_speed >= 0

		if(not(not lforward and not rforward)):
			safe_vel.linear.x = 0
			safe_vel.linear.y = 0
		else:
			backspeed = min(left_wheel_speed, right_wheel_speed)
			safe_vel.linear.x = backspeed
			safe_vel.linear.y = backspeed

	#print(unsafe)
	#print(safe_vel.linear.x)
	#print(safe_vel.linear.y)
	pub.publish(safe_vel)


# Create safety node
rospy.init_node('safety')
# Subscribe to LIDAR data
sub = rospy.Subscriber('/scan', LaserScan, LIDAR_callback)
# Subscribe to manual mode speed values
sub2 = rospy.Subscriber('/cmd_vel', Twist, manual_callback)
# Subscribe to autonomous mode speed values
sub3 = rospy.Subscriber('/auto_vel', Twist, auto_callback)
# Subscribe to manual mode data to see what mode the vehicle is in
sub4 = rospy.Subscriber('manual_mode', Bool, mode_callback)
# Publish speed values to Arduino  
pub = rospy.Publisher('safe_vel', Twist, queue_size=10)
safe_vel = Twist()

rospy.spin()
