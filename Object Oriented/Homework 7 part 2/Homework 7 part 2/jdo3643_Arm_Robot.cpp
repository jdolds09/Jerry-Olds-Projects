#include "jdo3643_Arm_Robot.h"

bool Arm_Robot::move(int x, int y)
{
	// Variables
	int distance;
	int power;
	int x2 = x;
	int y2 = y;
	// Calculate distance
	distance = sqrt(pow((x - position.first), 2) + pow((y - position.second), 2));
	// Check to see if object is within reach of Arm Robot 1002
	if (distance > length)
	{
		cout << "Position that is " << distance << " units away is not within the reach of " << length << " units." << endl << endl;
		return false;
	}
	// Calculate power
	if (is_holding)
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
			if (is_holding)
				power = distance * 2;
			else
				power = distance;
		}
		position.first = x2;
		position.second = y2;
		cout << "Arm Robot 1002 was able to get to coordinates (" << x2 << "," << y2 << ") before running out of power." << endl << endl;
		return false;
	}
	// Assign values
	position.first = x;
	position.second = y;
	battery_level -= power;
	return true;
}

bool Arm_Robot::pick_up(int weight)
{
	if (!is_holding && (weight <= weight_limit))
	{
		is_holding = true;
		battery_level--;
		return true;
	}
	else
		cout << "Object that weighs " << weight << " units exceeds weight limit of " << weight_limit << "." << endl << endl;
	return false;
}

bool Arm_Robot::drop()
{
	if (is_holding)
	{
		is_holding = false;
		battery_level--;
		return true;
	}
	else
		cout << "Arm Robot 1002 is not holding an object." << endl;
	return false;
}