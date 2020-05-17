#include "jdo3643_Super_Arm.h"
#include "jdo3643_Mobile_Robot.h"

class Mobile_Arm : public Super_Arm, public Mobile_Robot
{
private:
	pair<int, int> arm_position;
public:
	Mobile_Arm(int mn, string n, int bl, int l, int wl, int el, int ml) : Super_Arm(mn, n, bl, l, wl, el, ml), Extendable_Arm(mn, n, bl, l, wl, el), Powered_Arm(mn, n, bl, l, wl, ml), Arm_Robot(mn, n, bl, l, wl), Mobile_Robot(mn, n, bl), Robot(mn, n, bl) { arm_position.first = 0; arm_position.second = 0; };
	bool move(int x, int y);
	bool move(int x, int y, int speed);
	bool move_arm(int x, int y);
	bool move(int base_x, int base_y, int arm_x, int arm_y);
	bool move(int base_x, int base_y, int arm_x, int arm_y, int speed);
};