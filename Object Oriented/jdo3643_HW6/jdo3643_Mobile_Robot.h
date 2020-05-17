#include"jdo3643_Robot.h"

class Mobile_Robot : public Robot
{
private:
	int speed_level;
	void set_speed_level(int speed);
public:
	Mobile_Robot(int mn, string n, int bl);
	bool move(int x, int y);
	bool move(int x, int y, int speed);
};
