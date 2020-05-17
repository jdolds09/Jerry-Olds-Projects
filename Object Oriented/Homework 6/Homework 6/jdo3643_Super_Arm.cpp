#include "jdo3643_Super_Arm.h"

bool Super_Arm::move(int x, int y)
{
// Variables
	int distance1;
	int distance2;
	int power;
	int x2 = x;
	int y2 = y;
	int retract_length;
// Set retract length to original length
	if (!is_extended)
		retract_length = length;
	else
		retract_length = length - extend_length;
// Return home
	if (x == 0 && y == 0)
	{
		position.first = x;
		position.second = y;
		return true;
	}
// Calculate distances
	distance1 = sqrt(pow((x - position.first), 2) + pow((y - position.second), 2));
	distance2 = sqrt(pow((x), 2) + pow((y), 2));
// Check to see if arm needs to be extended
	if (distance2 > retract_length)
	{
		if (extend())
			cout << "Arm is extending to reach object out of retracted arm reach of " << length - extend_length << ". Maximum reach is now " << length << "." << endl;
		if (distance2 <= length)
			cout << "Arm extended " << distance2 - (length - extend_length) << " units to reach position." << endl;
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
// Calculate power
	if (is_holding && is_extended && motor_on)
		power = distance1 * 5;
	else if (is_holding && motor_on)
		power = distance1 * 4;
	else if (is_holding && is_extended)
		power = distance1 * 3;
	else if (is_holding || is_extended)
		power = distance1 * 2;
	else
		power = distance1;
	// Calculate battery life after movement
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
			distance1 = sqrt(pow((x2 - position.first), 2) + pow((y2 - position.second), 2));
			if (is_holding && is_extended)
				power = distance1 * 3;
			else if (is_holding || is_extended)
				power = distance1 * 2;
			else
				power = distance1;
		}
		position.first = x2;
		position.second = y2;
		cout << "Super Arm Robot 1005 was able to get to coordinates (" << x2 << "," << y2 << ") before running out of power." << endl << endl;
		return false;
	}
// Assign values
	position.first = x;
	position.second = y;
	battery_level -= power;
	return true;
}
