#ifndef JDO3643_ROBOT_H
#define JDO3643_ROBOT_H

#include<iostream>
#include<string>
#include<cmath>
using namespace std;

class Robot
{
protected:
	int model_number;
	string name;
	int battery_life;
	int battery_level;
	pair <int, int> position;
public:
	Robot(int mn, string n, int bl);
	virtual bool move(int x, int y) = 0;
	void charge();
	double get_battery_percentage();
};

#endif