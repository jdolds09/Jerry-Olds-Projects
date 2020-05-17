#include "jdo3643_Mobile_Arm.h"

bool Mobile_Arm::move(int x, int y)
{
// Charge
	if (x == 0 && y == 0)
	{
		position.first = 0;
		position.second = 0;
		arm_position.first = 0;
		arm_position.second = 0;
		return true;
	}
	bool value;
	value = Mobile_Robot::move(x, y);
	return value;
}

bool Mobile_Arm::move(int x, int y, int speed)
{
	bool value;
	value = Mobile_Robot::move(x, y, speed);
	return value;
}

bool Mobile_Arm::move_arm(int x, int y)
{
	bool value;
	value = Super_Arm::move(x, y);
	return value;
}

bool Mobile_Arm::move(int base_x, int base_y, int arm_x, int arm_y)
{
// Variables
	int base_distance;
	int arm_distance;
	int distance_from_base;
	int retract_length;
	int power;
	int base_power;
	int arm_power;
	int base_x2 = base_x;
	int base_y2 = base_y;
	int arm_x2 = arm_x;
	int arm_y2 = arm_y;
// Calculate distances
	base_distance = sqrt(pow(base_x - position.first, 2) + pow(base_y - position.second, 2));
	arm_distance = sqrt(pow(arm_x - arm_position.first, 2) + pow(arm_y - arm_position.second, 2));
	distance_from_base = abs(base_distance - arm_distance);
// Calculate power used by movement of robot
	base_power = base_distance;
// Check for valid move
	if (base_power > battery_level)
	{
		while (base_power > battery_level)
		{
			if (base_x2 - position.first < 0)
				base_x2++;
			else if (base_x2 != position.first)
				base_x2--;
			if (base_y2 - position.second < 0)
				base_y2++;
			else if (base_y2 != position.second)
				base_y2--;
			base_distance = sqrt(pow((base_x2 - position.first), 2) + pow((base_y2 - position.second), 2));
			base_power = base_distance;
		}
		position.first = base_x2;
		position.second = base_y2;
		cout << "Mobile Arm Robot 1006 was able to get to coordinates (" << base_x2 << "," << base_y2 << ") before running out of power." << endl << endl;
		return false;
	}
// Set retract length to original length
	if (!is_extended)
		retract_length = length;
	else
		retract_length = length - extend_length;
// Check to see if arm needs to be extended
	if (distance_from_base > retract_length)
	{
		if (extend())
			cout << "Arm is extending to reach object out of retracted arm reach of " << length - extend_length << ". Maximum reach is now " << length << "." << endl;
		if (distance_from_base <= length)
			cout << "Arm extended " << distance_from_base - (length - extend_length) << " units to reach position." << endl;
		else
		{
			cout << "Position is out of extended arm range of " << length << " units." << endl;
			return false;
		}
	}
// Check to see if arm needs to be retracted
	else
		if (retract())
			cout << "Arm is retracting. Maximum reach is now " << length << "." << endl;
// Calculate power used by arm
	if (is_holding && is_extended && motor_on)
		arm_power = distance_from_base * 5;
	else if (is_holding && motor_on)
		arm_power = distance_from_base * 4;
	else if (is_holding && is_extended)
		arm_power = distance_from_base * 3;
	else if (is_holding || is_extended)
		arm_power = distance_from_base * 2;
	else
		arm_power = distance_from_base;
// Calculate total power
	power = base_power + arm_power;
// Check for valid move
	if (power > battery_level)
	{
		while (power > battery_level)
		{
			if (arm_x2 - position.first < 0)
				arm_x2++;
			else if (arm_x2 != position.first)
				arm_x2--;
			if (arm_y2 - position.second < 0)
				arm_y2++;
			else if (arm_y2 != position.second)
				arm_y2--;
			arm_distance = sqrt(pow((arm_x2 - position.first), 2) + pow((arm_y2 - position.second), 2));
			if (is_holding && is_extended && motor_on)
				arm_power = distance_from_base * 5;
			else if (is_holding && motor_on)
				arm_power = distance_from_base * 4;
			else if (is_holding && is_extended)
				arm_power = distance_from_base * 3;
			else if (is_holding || is_extended)
				arm_power = distance_from_base * 2;
			else
				arm_power = distance_from_base;
			power = base_power + arm_power;
		}
		arm_position.first = arm_x2;
		arm_position.second = arm_y2;
		cout << "Mobile Arm Robot's arm was able to get to coordinates (" << arm_x2 << "," << arm_y2 << ") before running out of power." << endl << endl;
		return false;
	}
// Assign values
	position.first = base_x;
	position.second = base_y;
	arm_position.first = arm_x;
	arm_position.second = arm_y;
	battery_level -= power;
	return true;
}

bool Mobile_Arm::move(int base_x, int base_y, int arm_x, int arm_y, int speed)
{
// Variables
	int base_distance;
	int arm_distance;
	int distance_from_base;
	int retract_length;
	int power;
	int base_power;
	int arm_power;
	int arm_x2 = arm_x;
	int arm_y2 = arm_y;
	int base_x2 = base_x;
	int base_y2 = base_y;
// Set speed level
	set_speed_level(speed);
// Calculate distances
	base_distance = sqrt(pow(base_x - position.first, 2) + pow(base_y - position.second, 2));
	arm_distance = sqrt(pow(arm_x - arm_position.first, 2) + pow(arm_y - arm_position.second, 2));
	distance_from_base = abs(base_distance - arm_distance);
// Calculate power used by movement of robot
	base_power = base_distance * speed_level;
// Check for valid move
	if (base_power > battery_level)
	{
		while (base_power > battery_level)
		{
			if (base_x2 - position.first < 0)
				base_x2++;
			else if (base_x2 != position.first)
				base_x2--;
			if (base_y2 - position.second < 0)
				base_y2++;
			else if (base_y2 != position.second)
				base_y2--;
			base_distance = sqrt(pow((base_x2 - position.first), 2) + pow((base_y2 - position.second), 2));
			base_power = base_distance * speed_level;
		}
		position.first = base_x2;
		position.second = base_y2;
		cout << "Mobile Arm Robot 1006 was able to get to coordinates (" << base_x2 << "," << base_y2 << ") before running out of power." << endl << endl;
		return false;
	}
// Set retract length to original length
	if (!is_extended)
		retract_length = length;
	else
		retract_length = length - extend_length;
// Check to see if arm needs to be extended
	if (distance_from_base > retract_length)
	{
		if (extend())
			cout << "Arm is extending to reach object out of retracted arm reach of " << length - extend_length << ". Maximum reach is now " << length << "." << endl;
		if (distance_from_base <= length)
			cout << "Arm extended " << distance_from_base - (length - extend_length) << " units to reach position." << endl;
		else
		{
			cout << "Position is out of extended arm range of " << length << " units." << endl;
			return false;
		}
	}
// Check to see if arm needs to be retracted
	else
		if (retract())
			cout << "Arm is retracting. Maximum reach is now " << length << "." << endl;
// Calculate power used by arm
	if (is_holding && is_extended && motor_on)
		arm_power = distance_from_base * 5;
	else if (is_holding && motor_on)
		arm_power = distance_from_base * 4;
	else if (is_holding && is_extended)
		arm_power = distance_from_base * 3;
	else if (is_holding || is_extended)
		arm_power = distance_from_base * 2;
	else
		arm_power = distance_from_base;
// Calculate total power
	power = base_power + arm_power;
// Check for valid move
	if (power > battery_level)
	{
		while (power > battery_level)
		{
			if (arm_x2 - position.first < 0)
				arm_x2++;
			else if (arm_x2 != position.first)
				arm_x2--;
			if (arm_y2 - position.second < 0)
				arm_y2++;
			else if (arm_y2 != position.second)
				arm_y2--;
			arm_distance = sqrt(pow((arm_x2 - position.first), 2) + pow((arm_y2 - position.second), 2));
			distance_from_base = abs(base_distance - arm_distance);
			if (is_holding && is_extended && motor_on)
				arm_power = distance_from_base * 5;
			else if (is_holding && motor_on)
				arm_power = distance_from_base * 4;
			else if (is_holding && is_extended)
				arm_power = distance_from_base * 3;
			else if (is_holding || is_extended)
				arm_power = distance_from_base * 2;
			else
				arm_power = distance_from_base;
			power = base_power + arm_power;
		}
		arm_position.first = arm_x2;
		arm_position.second = arm_y2;
		cout << "Mobile Arm Robot's arm was able to get to coordinates (" << arm_x2 << "," << arm_y2 << ") before running out of power." << endl << endl;
		return false;
	}
// Assign values
	position.first = base_x;
	position.second = base_y;
	arm_position.first = arm_x;
	arm_position.second = arm_y;
	battery_level -= power;
	return true;
}