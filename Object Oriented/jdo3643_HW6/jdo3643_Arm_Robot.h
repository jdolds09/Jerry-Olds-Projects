#ifndef JDO3643_ARM_ROBOT_H
#define JDO3643_ARM_ROBOT_H


#include "jdo3643_Robot.h"

class Arm_Robot : public Robot
{
protected:
	int length;
	int weight_limit;
	bool is_holding;
public:
	Arm_Robot(int mn, string n, int bl, int l, int wl);
	bool move(int x, int y);
	bool pick_up(int weight);
	bool drop();
};

#endif
