#!/bin/bash

# gnome-terminal -- roscore
# sleep 2s

#Start the LIDAR node in the seperate ubuntu terminal
#echo "Start the LIDAR node"
#echo ""
#gnome-terminal -- roslaunch rplidar_ros rplidar_s1.launch

#Start the Safety node in the seperate ubuntu terminal
# echo "Start the Safety node"
# echo ""
# gnome-terminal -- roslaunch safety check_distance_launch.launch

# Start the joy node in the separate ubuntu terminal
echo "Start the joy node"
echo ""
gnome-terminal -- rosrun joy joy_node _autorepeat_rate:=4

# start the video feed
gnome-terminal -- python3 webstreaming.py --ip 10.0.0.9 --port 8000

# Start the teleop node in the separate ubuntu terminal
# echo "start the teleop node"
# echo ""
# gnome-terminal -- rosrun teleop_twist_joy teleop_node

# Start the serial node in the separate ubuntu terminal
# gnome-terminal -- rosrun rosserial_python serial_node.py /dev/ttyACM0
