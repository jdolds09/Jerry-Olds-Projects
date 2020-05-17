#include "jdo3643_Arm_Robot.h"

class Powered_Arm : public Arm_Robot
{
private:
	int motor_limit;
	bool motor_on;
	void power_on();
	void power_off();
public:
	Powered_Arm(int mn, string n, int bl, int l, int wl, int ml);
	bool move(int x, int y);
	bool pick_up(int weight);
	bool drop();
};
