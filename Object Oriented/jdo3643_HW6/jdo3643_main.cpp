#include "jdo3643_Extendable_Arm.h"
#include "jdo3643_Powered_Arm.h"
#include "jdo3643_Mobile_Robot.h"
#include<iomanip>

// Function prototypes
void move_robot(Robot* robot);
void move_mobile_robot(Mobile_Robot* mb);
void move_arm_robot(Arm_Robot* ar);
void move_extendable_arm_robot(Extendable_Arm* ear);
void move_powered_arm_robot(Powered_Arm* par);

int main()
{
// Robot objects
	Robot robot{ 1000, "Robot", 100 };
	Mobile_Robot mobile_robot{ 1001, "Mobile Robot", 100 };
	Arm_Robot arm_robot{ 1002, "Arm Robot", 100, 25, 100 };
	Extendable_Arm extendable_arm_robot{ 1003, "Extendable Arm Robot", 100, 25, 100, 25 };
	Powered_Arm powered_arm_robot{ 1004, "Powered Arm Robot", 100, 25, 100, 200};
// Program title
	cout << "\n===========================" << endl;
	cout << "Robot Controller Program" << endl;
	cout << "===========================" << endl << endl;
// Move robots
	move_robot(&robot);
	move_mobile_robot(&mobile_robot);
	move_arm_robot(&arm_robot);
	move_extendable_arm_robot(&extendable_arm_robot);
	move_powered_arm_robot(&powered_arm_robot);
// End of program
	return 0;
}

void move_robot(Robot* robot)
{
// Variables
	int x = 25;
	int y = 25;
// Robot title
	cout << "ROBOT 1000\n-------------------------------------------------------------------------------" << endl;
// Move Robot 1000
	while (robot->move(x, y))
	{
		cout << "Robot 1000 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << robot->get_battery_percentage() << endl << endl;
		x += 25;
		y += 25;
	}
// Charge battery
	cout << "Battery charging..." << endl << endl;
	robot->charge();
// Move Robot 1000
	while (robot->move(x, y))
	{
		cout << "Robot 1000 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << robot->get_battery_percentage() << endl << endl;
		x -= 25;
		y -= 25;
	}
}

void move_mobile_robot(Mobile_Robot* mb)
{
// Variables
	int x = 5;
	int y = 5;
	int speed = 1;
	char enter;
// Continue
	cout << "-------------------------------------------------------------------------------" << endl;
	cin >> noskipws;
	cout << "PRESS ENTER TO DEPLOY NEXT ROBOT" << endl;
	cin >> enter;
// Robot title
	cout << "MOBILE ROBOT 1001\n-------------------------------------------------------------------------------------------" << endl;
// Move Mobile Robot 1001, Speed level = 1
	if (mb->move(x, y))
	{
		cout << "Mobile Robot 1001 was able to move successfully to position (" << x << "," << y << ") at a speed level of " << speed << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << mb->get_battery_percentage() << endl << endl;
		x += 5;
		y += 5;
		speed++;
	}
// Move Mobile Robot 1001, Speed level = 2
	if (mb->move(x, y, speed))
	{
		cout << "Mobile Robot 1001 was able to move successfully to position (" << x << "," << y << ") at a speed level of " << speed << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << mb->get_battery_percentage() << endl << endl;
		x += 5;
		y += 5;
	}
// Move Mobile Robot 1001, Speed level = 2
	if (mb->move(x, y))
	{
		cout << "Mobile Robot 1001 was able to move successfully to position (" << x << "," << y << ") at a speed level of " << speed << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << mb->get_battery_percentage() << endl << endl;
		x += 5;
		y += 5;
		speed++;
	}
// Move Mobile Robot 1001, Speed level = 3
	if (mb->move(x, y, speed))
	{
		cout << "Mobile Robot 1001 was able to move successfully to position (" << x << "," << y << ") at a speed level of " << speed << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << mb->get_battery_percentage() << endl;
		x += 5;
		y += 5;
	}
}

void move_arm_robot(Arm_Robot* ar)
{
// Variables
	int x = 50;
	int y = 50;
	int weight = 150;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
	char enter;
// Continue
	cout << "-------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO DEPLOY NEXT ROBOT" << endl;
	cin >> enter;
// Robot title
	cout << "ARM ROBOT 1002\n-----------------------------------------------------------------------------------" << endl;
// Move Arm Robot 1002
	if (sqrt(pow(x, 2) + pow(y, 2)) > 25)
	{
		cout << "Arm Robot 1002 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << " units." <<  endl;
		ar->move(x, y);
		x = 5;
		y = 5;
		distance = sqrt(pow(x, 2) + pow(y, 2));
	}
	if (ar->move(x, y))
	{
		cout << "Arm Robot 1002 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << " units." << endl;
		cout << "Arm Robot 1002 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << ar->get_battery_percentage() << endl << endl;
	// Pick up object
		if (weight > 100)
		{
			cout << "Arm Robot 1002 attempting to pick up object that weighs " << weight << " units" << endl;
			ar->pick_up(weight);
			weight = 50;
		}
		if (ar->pick_up(weight))
		{
			cout << "Arm Robot 1002 attempting to pick up object that weighs " << weight << " units" << endl;
			cout << "Arm Robot 1002 was able to successfully pick up item with a weight of "<< weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << ar->get_battery_percentage() << endl << endl;
			x += 10;
			y += 10;
			distance = sqrt(pow(x, 2) + pow(y, 2));
		// Move with object
			if (ar->move(x, y))
			{
				cout << "Arm Robot 1002 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << " units." << endl;
				cout << "Arm Robot 1002 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << ar->get_battery_percentage() << endl << endl;
			// Drop object
				if (ar->drop())
				{
					cout << "Arm Robot 1002 was able to successfully drop the object at position ("<< x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << ar->get_battery_percentage() << endl;
				}
			}
		}
	}
}

void move_extendable_arm_robot(Extendable_Arm* ear)
{
// Variables
	int x = 5;
	int y = 5;
	int weight = 50;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
	char enter;
// Continue
	cout << "-----------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO DEPLOY NEXT ROBOT" << endl;
	cin >> enter;
// Robot title
	cout << "EXTENDABLE ARM ROBOT 1003\n--------------------------" << endl;
// TASK 1
	cout << "TASK 1\n--------------------------------------------------------------------------------------------" << endl;
// Move Extendable Arm Robot 1003
	cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (ear->move(x, y))
	{
		cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
		cout << "Extendable Arm Robot 1003 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (ear->pick_up(weight))
		{
			cout << "Extendable Arm Robot 1003 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (ear->move(x, y))
			{
				cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			// Drop object
				if (ear->drop())
				{
					cout << "Extendable Arm Robot 1003 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send to home position
	cout << "Extendable Arm Robot return to base position of (0,0) to charge." << endl;
	ear->move(0, 0);
	cout << "Battery charging..." << endl;
	ear->charge();
// TASK 2
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO COMPLETE TASK 2" << endl;
	cin >> enter;
	cout << "TASK 2\n--------------------------------------------------------------------------------------------" << endl;
	x = 25;
	y = 25;
	distance = sqrt(pow(x, 2) + pow(y, 2));
// Move Extendable Arm Robot 1003
	cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (ear->move(x, y))
	{
		cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
		cout << "Extendable Arm Robot 1003 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (ear->pick_up(weight))
		{
			cout << "Extendable Arm Robot 1003 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (ear->move(x, y))
			{
				cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			// Drop object
				if (ear->drop())
				{
					cout << "Extendable Arm Robot 1003 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send to home position
	cout << "Extendable Arm Robot return to base position of (0,0) to charge." << endl;
	ear->move(0, 0);
	cout << "Battery charging..." << endl;
	ear->charge();
// TASK 3
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO COMPLETE TASK 3" << endl;
	cin >> enter;
	cout << "TASK 3\n--------------------------------------------------------------------------------------------" << endl;
	x = 5;
	y = 5;
	distance = sqrt(pow(x, 2) + pow(y, 2));
// Move Extendable Arm Robot 1003
	cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (ear->move(x, y))
	{
		cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
		cout << "Extendable Arm Robot 1003 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (ear->pick_up(weight))
		{
			cout << "Extendable Arm Robot 1003 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			x += 20;
			y += 20;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (ear->move(x, y))
			{
				cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			// Drop object
				if (ear->drop())
				{
					cout << "Extendable Arm Robot 1003 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send to home position
	cout << "Extendable Arm Robot return to base position of (0,0) to charge." << endl;
	ear->move(0, 0);
	cout << "Battery charging..." << endl;
	ear->charge();
// TASK 4
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO COMPLETE TASK 4" << endl;
	cin >> enter;
	cout << "TASK 4\n--------------------------------------------------------------------------------------------" << endl;
	x = 50;
	y = 50;
	distance = sqrt(pow(x, 2) + pow(y, 2));
// Move Extendable Arm Robot 1003
	cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (ear->move(x, y))
	{
		cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
		cout << "Extendable Arm Robot 1003 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (ear->pick_up(weight))
		{
			cout << "Extendable Arm Robot 1003 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			x += 25;
			y += 25;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Extendable Arm Robot 1003 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (ear->move(x, y))
			{
				cout << "Extendable Arm Robot 1003 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
			// Drop object
				if (ear->drop())
				{
					cout << "Extendable Arm Robot 1003 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << ear->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
}

void move_powered_arm_robot(Powered_Arm* par)
{
// Variables
	int x = 5;
	int y = 5;
	int weight = 50;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
	char enter;
// Continue
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO DEPLOY NEXT ROBOT" << endl;
	cin >> enter;
// Robot title
	cout << "POWERED ARM ROBOT 1004\n--------------------------" << endl;
// TASK 1
	cout << "TASK 1\n-----------------------------------------------------------------------------------------------" << endl;
// Move Powered Arm Robot 1004
	cout << "Powered Arm Robot 1004 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (par->move(x, y))
	{
		cout << "Powered Arm Robot 1004 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
		cout << "Powered Arm Robot 1004 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (par->pick_up(weight))
		{
			cout << "Powered Arm Robot 1004 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Powered Arm Robot 1004 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (par->move(x, y))
			{
				cout << "Powered Arm Robot 1004 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
			// Drop object
				if (par->drop())
				{
					cout << "Powered Arm Robot 1004 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot
	cout << "Powered Arm Robot return to base position of (0,0) to charge." << endl;
	par->move(0, 0);
	cout << "Battery charging..." << endl;
	par->charge();
// TASK 2
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO COMPLETE TASK 2" << endl;
	cin >> enter;
	cout << "TASK 2\n-----------------------------------------------------------------------------------------------" << endl;
	x = 5;
	y = 5;
	distance = sqrt(pow(x, 2) + pow(y, 2));
	weight = 150;
// Move Powered Arm Robot 1004
	cout << "Powered Arm Robot 1004 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (par->move(x, y))
	{
		cout << "Powered Arm Robot 1004 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
		cout << "Powered Arm Robot 1004 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (par->pick_up(weight))
		{
			cout << "Powered Arm Robot 1004 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Powered Arm Robot 1004 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (par->move(x, y))
			{
				cout << "Powered Arm Robot 1004 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
			// Drop object
				if (par->drop())
				{
					cout << "Powered Arm Robot 1004 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot
	cout << "Powered Arm Robot return to base position of (0,0) to charge." << endl;
	par->move(0, 0);
	cout << "Battery charging..." << endl;
	par->charge();
// TASK 3
	cout << "-----------------------------------------------------------------------------------------------" << endl;
	cout << "PRESS ENTER TO COMPLETE TASK 3" << endl;
	cin >> enter;
	cout << "TASK 3\n-----------------------------------------------------------------------------------------------" << endl;
	x = 5;
	y = 5;
	distance = sqrt(pow(x, 2) + pow(y, 2));
	weight = 300;
// Move Powered Arm Robot 1004
	cout << "Powered Arm Robot 1004 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (par->move(x, y))
	{
		cout << "Powered Arm Robot 1004 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
		cout << "Powered Arm Robot 1004 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (par->pick_up(weight))
		{
			cout << "Powered Arm Robot 1004 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Powered Arm Robot 1004 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (par->move(x, y))
			{
				cout << "Powered Arm Robot 1004 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
			// Drop object
				if (par->drop())
				{
					cout << "Powered Arm Robot 1004 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage: %" << fixed << setprecision(0) << par->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
	cout << "---------------------------------------------------------------------------------------------- - " << endl;
}
