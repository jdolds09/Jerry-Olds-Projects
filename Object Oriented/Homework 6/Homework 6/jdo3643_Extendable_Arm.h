#ifndef JDO3643_EXTENDABLE_ARM_H
#define JDO3643_EXTENDABLE_ARM_H

#include "jdo3643_Arm_Robot.h"

class Extendable_Arm : public virtual Arm_Robot
{
protected:
	int extend_length;
	bool is_extended;
	bool extend();
	bool retract();
public:
	Extendable_Arm(int mn, string n, int bl, int l, int wl, int el) : extend_length{ el }, is_extended { false }, Arm_Robot(mn, n, bl, l, wl), Robot(mn, n, bl) {};
	bool move(int x, int y);
};

#endif