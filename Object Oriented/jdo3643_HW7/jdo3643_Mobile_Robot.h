#ifndef JDO3643_MOBILE_ROBOT_H
#define JDO3643_MOBILE_ROBOT_H

#include"jdo3643_Robot.h"

class Mobile_Robot : public virtual Robot
{
protected:
	int speed_level;
	void set_speed_level(int speed);
public:
	Mobile_Robot(int mn, string n, int bl) : speed_level{ 1 }, Robot(mn, n, bl) {};
	bool move(int x, int y);
	bool move(int x, int y, int speed);
};

#endif