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

void Robot::charge()
{
	battery_level = battery_life;
}

double Robot::get_battery_percentage()
{
	return (double(battery_level) / battery_life) * 100;
}