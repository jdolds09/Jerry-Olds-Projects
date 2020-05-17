#ifndef JDO3643_SUPER_ARM_H
#define JDO3643_SUPER_ARM_H

#include "jdo3643_Extendable_Arm.h"
#include "jdo3643_Powered_Arm.h"

class Super_Arm : public virtual Extendable_Arm, public virtual Powered_Arm
{
public:
	Super_Arm(int mn, string n, int bl, int l, int wl, int el, int ml): Extendable_Arm(mn, n, bl, l, wl, el), Powered_Arm(mn, n, bl, l, wl, ml), Arm_Robot(mn, n, bl, l, wl), Robot(mn, n, bl) {};
	bool move(int x, int y);
private:

};

#endif