#include "jdo3643_Robot.h"

Robot::Robot(int mn, string n, int bl)
{
	model_number = mn;
	name = n;
	battery_life = bl;
	battery_level = bl;
	position.first = 0;
	position.second = 0;
}

bool Robot::move(int x, int y)
{
// Variables
	int distance;
	int x2 = x;
	int y2 = y;
// Calculate distance
	distance = sqrt(pow((x - position.first), 2) + pow((y - position.second), 2));
// Check for valid move
	if (distance > battery_level)
	{
		while (sqrt(pow((x2 - position.first), 2) + pow((y2 - position.second), 2)) > battery_level)
		{
			if (x2 - position.first < 0)
				x2++;
			else if (x2 != position.first)
				x2--;
			if (y2 - position.second < 0)
				y2++;
			else if (y2 != position.second)
				y2--;
		}
		position.first = x2;
		position.second = y2;
		cout << "Robot 1000 was able to get to coordinates (" << x2 << "," << y2 << ") before running out of power." << endl;
		return false;
	}
// Assign values
	else
		position.first = x;
		position.second = y;
		battery_level -= distance;
		return true;
}

void Robot::charge()
{
	battery_level = battery_life;
}

double Robot::get_battery_percentage()
{
	return (double(battery_level) / battery_life) * 100;
}
