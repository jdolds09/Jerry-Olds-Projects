#include "jdo3643_Powered_Arm.h"

bool Powered_Arm::move(int x, int y)
{
	// Variable
	int distance;
	int power;
	int x2 = x;
	int y2 = y;
	// Calculate distance
	distance = sqrt(pow((x - position.first), 2) + pow((y - position.second), 2));
	// Check for valid move
	if (distance > length)
	{
		cout << "Position that is " << distance << " units away is not within the reach of " << length << " units." << endl << endl;
		return false;
	}
	// Calculate power
	if (is_holding && motor_on)
		power = distance * 4;
	else if (motor_on)
		power = distance * 3;
	else if (is_holding)
		power = distance * 2;
	else
		power = distance;
	// Check for valid move
	if (power > battery_level)
	{
		while (power > battery_level)
		{
			if (x2 - position.first < 0)
				x2++;
			else if (x2 != position.first)
				x2--;
			if (y2 - position.second < 0)
				y2++;
			else if (y2 != position.second)
				y2--;
			distance = sqrt(pow((x2 - position.first), 2) + pow((y2 - position.second), 2));
			// Calculate power
			if (is_holding && motor_on)
				power = distance * 4;
			else if (motor_on)
				power = distance * 3;
			else if (is_holding)
				power = distance * 2;
			else
				power = distance;
		}
		position.first = x2;
		position.second = y2;
		cout << "Powered Arm Robot 1004 was able to get to coordinates (" << x2 << "," << y2 << ") before running out of power." << endl << endl;
		return false;
	}
	// Assign values
	position.first = x;
	position.second = y;
	battery_level -= power;
	return true;
}

bool Powered_Arm::pick_up(int weight)
{
	if (!is_holding && (weight > weight_limit))
		power_on();
	if (!is_holding && (weight <= motor_limit))
	{
		is_holding = true;
		battery_level--;
		return true;
	}
	else
		cout << "Object exceeds weight limit of " << motor_limit << " units." << endl << endl;
	return false;
}

bool Powered_Arm::drop()
{
	if (is_holding)
	{
		power_off();
		is_holding = false;
		battery_level--;
		return true;
	}
	else
		return false;
}

void Powered_Arm::power_on()
{

	cout << "Object exceeds weight limit of " << weight_limit << " units. Motor is powered on. Weight limit is now " << motor_limit << " units." << endl;
	motor_on = true;
}

void Powered_Arm::power_off()
{
	if (motor_on)
		cout << "Motor has been powered off" << endl;

	motor_on = false;
}