#ifndef JDO3643_POWERED_ARM_H
#define JDO3643_POWERED_ARM_H

#include "jdo3643_Arm_Robot.h"

class Powered_Arm : public virtual Arm_Robot
{
protected:
	int motor_limit;
	bool motor_on;
	void power_on();
	void power_off();
public:
	Powered_Arm(int mn, string n, int bl, int l, int wl, int ml) : motor_limit{ ml }, motor_on{ false }, Arm_Robot(mn, n, bl, l, wl), Robot(mn, n, bl) {};
	bool move(int x, int y);
	bool pick_up(int weight);
	bool drop();
};

#endif