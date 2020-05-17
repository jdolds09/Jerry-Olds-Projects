#include "jdo3643_Mobile_Robot.h"

Mobile_Robot::Mobile_Robot(int mn, string n, int bl) : Robot(mn, n, bl)
{
	model_number = mn;
	name = n;
	battery_life = bl;
	battery_level = bl;
	speed_level = 1;
	position.first = 0;
	position.second = 0;
}

bool Mobile_Robot::move(int x, int y)
{
// Variables
	int distance;
	int power;
	int x2 = x;
	int y2 = y;
// Calculate distance
	distance = sqrt(pow((x - position.first), 2) + pow((y - position.second), 2));
// Calculate power
	power = distance * speed_level;
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
			power = distance * speed_level;
		}
		position.first = x2;
		position.second = y2;
		cout << "Mobile Robot 1001 was able to get to coordinates (" << x2 << "," << y2 << ") at speed level " << speed_level << " before running out of power." << endl << endl;
		return false;
	}
// Assign values
	else
		position.first = x;
		position.second = y;
		battery_level -= power;
		return true;
}

bool Mobile_Robot::move(int x, int y, int speed)
{
// Variables
	int distance;
	int power;
	int x2 = x;
	int y2 = y;
// Set speed level
	set_speed_level(speed);
// Calculate distance
	distance = sqrt(pow((x - position.first), 2) + pow((y - position.second), 2));
// Calculate power
	power = distance * speed_level;
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
			power = distance * speed_level;
		}
		position.first = x2;
		position.second = y2;
		cout << "Mobile Robot 1001 was able to get to coordinates (" << x2 << "," << y2 << ") at speed level " << speed_level << " before running out of power." << endl << endl;
		return false;
	}
// Assign values
	else
		position.first = x;
		position.second = y;
		battery_level -= power;
		return true;
}

void Mobile_Robot::set_speed_level(int speed)
{
	speed_level = speed;
}
