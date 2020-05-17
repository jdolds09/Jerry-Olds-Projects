#include "jdo3643_Arm_Robot.h"

class Extendable_Arm : public Arm_Robot
{
private:
	int extend_length;
	bool is_extended;
	bool extend();
	bool retract();
public:
	Extendable_Arm(int mn, string n, int bl, int l, int wl, int el);
	bool move(int x, int y);
};
