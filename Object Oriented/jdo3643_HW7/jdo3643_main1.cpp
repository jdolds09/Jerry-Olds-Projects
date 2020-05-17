#include "jdo3643_Mobile_Arm.h"
#include<iomanip>

// Function prototypes
void move_super_arm(Super_Arm* sar);
void move_mobile_arm(Mobile_Arm* mar);

int main()
{
// Program title
	cout << "=========================" << endl;
	cout << "ROBOT CONTROLLER PROGRAM" << endl;
	cout << "=========================" << endl << endl;
// Create robot objects
	Super_Arm super_arm{ 1005, "Super Arm Robot 1005", 100, 15, 50, 15, 100 };
	Mobile_Arm mobile_arm{ 1006, "Mobile Arm Robot 1006", 100, 15, 50, 15, 100 };
// Call move functions
	move_super_arm(&super_arm);
	move_mobile_arm(&mobile_arm);
// End of program
	return 0;
}

void move_super_arm(Super_Arm* sar)
{
// Variables
	char enter;
	int x = 5;
	int y = 5;
	int weight = 25;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Title
	cout << "SUPER ARM ROBOT 1005" << endl;
	cout << "======================" << endl << endl;
// TASK 1
	cout << "TASK 1" << endl;
	cout << "--------" << endl;
// Move
	cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (sar->move(x, y))
	{
		cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
		cout << "Super Arm Robot 1005 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (sar->pick_up(weight))
		{
			cout << "Super Arm Robot 1005 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			int distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (sar->move(x, y))
			{
				cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			// Drop object
				if (sar->drop())
				{
					cout << "Super Arm Robot 1005 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;

				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Super Arm Robot 1005 return to base position of (0,0) to charge." << endl;
	sar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	sar->charge();
// TASK 2
	cout << "PRESS ENTER TO PREFORM TASK 2";
	cin >> noskipws >> enter;
	cout << "\nTASK 2" << endl;
	cout << "-------" << endl;
	x = 5;
	y = 5;
	distance = sqrt(pow(x, 2) + pow(y, 2));
// Move
	cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (sar->move(x, y))
	{
		cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
		cout << "Super Arm Robot 1005 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (sar->pick_up(weight))
		{
			cout << "Super Arm Robot 1005 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			x += 10;
			y += 10;
			int distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (sar->move(x, y))
			{
				cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			// Drop object
				if (sar->drop())
				{
					cout << "Super Arm Robot 1005 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;

				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Super Arm Robot 1005 return to base position of (0,0) to charge." << endl;
	sar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	sar->charge();
// TASK 3
	cout << "PRESS ENTER TO PREFORM TASK 3";
	cin >> enter;
	cout << "\nTASK 3" << endl;
	cout << "-------" << endl;
	x = 5;
	y = 5;
	weight = 75;
	distance = sqrt(pow(x, 2) + pow(y, 2));
// Move
	cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (sar->move(x, y))
	{
		cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
		cout << "Super Arm Robot 1005 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (sar->pick_up(weight))
		{
			cout << "Super Arm Robot 1005 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			int distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (sar->move(x, y))
			{
				cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			// Drop object
				if (sar->drop())
				{
					cout << "Super Arm Robot 1005 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;

				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Super Arm Robot 1005 return to base position of (0,0) to charge." << endl;
	sar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	sar->charge();
// TASK 4
	cout << "PRESS ENTER TO PREFORM TASK 4";
	cin >> enter;
	cout << "\nTASK 4" << endl;
	cout << "-------" << endl;
	x = 5;
	y = 5;
	weight = 75;
	distance = sqrt(pow(x, 2) + pow(y, 2));
	cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (sar->move(x, y))
	{
		cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
		cout << "Super Arm Robot 1005 attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up object
		if (sar->pick_up(weight))
		{
			cout << "Super Arm Robot 1005 was able to successfully pick up item with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			x += 10;
			y += 10;
			int distance = sqrt(pow(x, 2) + pow(y, 2));
			cout << "Super Arm Robot 1005 attempting to move to (" << x << "," << y << "). Distance from base: " << distance << endl;
		// Move with object
			if (sar->move(x, y))
			{
				cout << "Super Arm Robot 1005 was able to move successfully to position (" << x << "," << y << ")" << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;
			// Drop object
				if (sar->drop())
				{
					cout << "Super Arm Robot 1005 was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << sar->get_battery_percentage() << endl << endl;

				}
			}
		}
	}
	cout << "*********************************************" << endl;
	cout << "PRESS ENTER TO DEPLOY MOBILE ARM ROBOT 1006 *" << endl;
	cout << "*********************************************" << endl;
	cin >> enter;
}

void move_mobile_arm(Mobile_Arm* mar)
{
// Variables
	char enter;
	int x = 5;
	int y = 5;
	int speed = 1;
	int weight = 25;
// Title
	cout << "MOBILE ARM ROBOT 1006" << endl;
	cout << "=======================" << endl << endl;
// TASK 1
	cout << "TASK 1" << endl;
	cout << "-------" << endl;
// Move base
	cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
	if (mar->move(x, y))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 2
	cout << "PRESS ENTER TO PREFORM TASK 2";
	cin >> noskipws >> enter;
	cout << "\nTASK 2" << endl;
	cout << "-------" << endl;
	x = 100;
	y = 100;
// Move base
	cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
	if (mar->move(x, y))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 3
	cout << "PRESS ENTER TO PREFORM TASK 3";
	cin >> enter;
	cout << "\nTASK 3" << endl;
	cout << "-------" << endl;
	x = 5;
	y = 5;
// Move base
	cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
	if (mar->move(x, y, speed))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		x += 5;
		y += 5;
		speed++;
		cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
		if (mar->move(x, y, speed))
		{
			cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			speed++;
			cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
			if (mar->move(x, y, speed))
			{
				cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				x += 5;
				y += 5;
				speed++;
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 4
	cout << "PRESS ENTER TO PREFORM TASK 4";
	cin >> enter;
	cout << "\nTASK 4" << endl;
	cout << "-------" << endl;
	x = 15;
	y = 15;
	speed = 1;
// Move base
	cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
	if (mar->move(x, y, speed))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		x += 15;
		y += 15;
		speed++;
		cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
		if (mar->move(x, y, speed))
		{
			cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			x += 15;
			y += 15;
			speed++;
			cout << "Mobile Arm Robot attempting to move base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
			if (mar->move(x, y, speed))
			{
				cout << "Mobile Arm Robot was able to successfully move its base to position (" << x << "," << y << ") at speed level " << speed << "." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				x += 5;
				y += 5;
				speed++;
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 5
	cout << "PRESS ENTER TO PREFORM TASK 5";
	cin >> enter;
	cout << "\nTASK 5" << endl;
	cout << "-------" << endl;
	x = 5;
	y = 5;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Move arm
	cout << "Mobile Arm Robot attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << "." << endl;
	if (mar->move_arm(x, y))
	{
		cout << "Mobile Arm Robot was able to succesfully move its arm to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		cout << "Mobile Arm Robot attempting to pick up object that weighs " << weight << " units" << endl;
		// Pick up
		if (mar->pick_up(weight))
		{
			cout << "Mobile arm was able to successfully able to pick up object with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			x += 10;
			y += 10;
			distance = sqrt(pow(x, 2) + pow(y, 2));
			// Move with object
			cout << "Mobile Arm Robot attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << "." << endl;
			if (mar->move_arm(x, y))
			{
				cout << "Mobile Arm Robot was able to succesfully move its arm to position (" << x << "," << y << ")." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			// Drop
				if (mar->drop())
				{
					cout << "Mobile Arm Robot was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->drop();
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 6
	cout << "PRESS ENTER TO PREFORM TASK 6";
	cin >> enter;
	cout << "\nTASK 6" << endl;
	cout << "-------" << endl;
	x = 5;
	y = 5;
	distance = sqrt(pow(x, 2) + pow(y, 2));
// Move arm
	cout << "Mobile Arm Robot attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << "." << endl;
	if (mar->move_arm(x, y))
	{
		cout << "Mobile Arm Robot was able to succesfully move its arm to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		cout << "Mobile Arm Robot attempting to pick up object that weighs " << weight << " units" << endl;
	// Pick up
		if (mar->pick_up(weight))
		{
			cout << "Mobile arm was able to successfully able to pick up object with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			x += 20;
			y += 20;
			distance = sqrt(pow(x, 2) + pow(y, 2));
		// Move with object
			cout << "Mobile Arm Robot attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << "." << endl;
			if (mar->move_arm(x, y))
			{
				cout << "Mobile Arm Robot was able to succesfully move its arm to position (" << x << "," << y << ")." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			// Drop
				if (mar->drop())
				{
					cout << "Mobile Arm Robot was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				}
			}
		
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->drop();
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 7
	cout << "PRESS ENTER TO PREFORM TASK 7";
	cin >> enter;
	cout << "\nTASK 7" << endl;
	cout << "-------" << endl;
	int base_x = 5;
	int base_y = 5;
	int arm_x = 10;
	int arm_y = 10;
	distance = sqrt(pow(arm_x - base_x, 2) + pow(arm_y - base_y, 2));
// Move base and arm
	cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << "). Distance from base: " << distance << endl;
	if (mar->move(base_x, base_y, arm_x, arm_y))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		cout << "Mobile Arm Robot is attempting to pick up object that weighs " << weight << " units." << endl;
		// Pick up
		if (mar->pick_up(weight))
		{
			cout << "Mobile arm was able to successfully able to pick up object with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			base_x += 5;
			base_y += 5;
			arm_x += 10;
			arm_y += 10;
			// Move base and arm with object
			cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << "). Distance from base: " << distance << endl;
			if (mar->move(base_x, base_y, arm_x, arm_y))
			{
				cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				// Drop
				if (mar->drop())
				{
					cout << "Mobile Arm Robot was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->drop();
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 8
	cout << "PRESS ENTER TO PREFORM TASK 8";
	cin >> enter;
	cout << "\nTASK 8" << endl;
	cout << "-------" << endl;
	base_x = 5;
	base_y = 5;
	arm_x = 10;
	arm_y = 10;
	weight = 101;
	distance = sqrt(pow(arm_x - base_x, 2) + pow(arm_y - base_y, 2));
// Move base and arm
	cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << "). Distance from base: " << distance << endl;
	if (mar->move(base_x, base_y, arm_x, arm_y))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		cout << "Mobile Arm Robot is attempting to pick up object that weighs " << weight << " units." << endl;
	// Pick up
		if (mar->pick_up(weight))
		{
			cout << "Mobile arm was able to successfully able to pick up object with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			base_x += 5;
			base_y += 5;
			arm_x += 10;
			arm_y += 10;
		// Move base and arm with object
			cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << "). Distance from base: " << distance << endl;
			if (mar->move(base_x, base_y, arm_x, arm_y))
			{
				cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			// Drop
				if (mar->drop())
				{
					cout << "Mobile Arm Robot was able to successfully drop the object at position (" << x << "," << y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->drop();
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 9
	cout << "PRESS ENTER TO PREFORM TASK 9";
	cin >> enter;
	cout << "\nTASK 9" << endl;
	cout << "-------" << endl;
	base_x = 5;
	base_y = 5;
	arm_x = 10;
	arm_y = 10;
	speed = 1;
	weight = 25;
	distance = sqrt(pow(arm_x - base_x, 2) + pow(arm_y - base_y, 2));
	// Move base and arm
	cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") at speed level " << speed << " and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
	if (mar->move(base_x, base_y, arm_x, arm_y, speed))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") at speed level " << speed << " and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		cout << "Mobile Arm Robot is attempting to pick up object that weighs " << weight << " units." << endl;
		// Pick up
		if (mar->pick_up(weight))
		{
			cout << "Mobile arm was able to successfully able to pick up object with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			base_x += 5;
			base_y += 5;
			arm_x += 10;
			arm_y += 10;
			speed++;
			// Move base and arm with object
			cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") at speed level " << speed << " and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
			if (mar->move(base_x, base_y, arm_x, arm_y, speed))
			{
				cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				// Drop
				if (mar->drop())
				{
					cout << "Mobile Arm Robot was able to successfully drop the object at position (" << arm_x << "," << arm_y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
// Charge robot and send arm to home position
	cout << "Mobile Arm Robot 1006 return to position of (0,0) to charge." << endl;
	mar->drop();
	mar->move(0, 0);
	cout << "Battery charging..." << endl << endl;
	mar->charge();
// TASK 10
	cout << "PRESS ENTER TO PREFORM TASK 10";
	cin >> enter;
	cout << "\nTASK 10" << endl;
	cout << "-------" << endl;
	base_x = 15;
	base_y = 15;
	arm_x = 20;
	arm_y = 20;
	speed = 3;
	weight = 25;
// Move base and arm
	cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") at speed level " << speed << " and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
	if (mar->move(base_x, base_y, arm_x, arm_y, speed))
	{
		cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") at speed level " << speed << " and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
		cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
		cout << "Mobile Arm Robot is attempting to pick up object that weighs " << weight << " units." << endl;
	// Pick up
		if (mar->pick_up(weight))
		{
			cout << "Mobile arm was able to successfully able to pick up object with a weight of " << weight << " units." << endl;
			cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			base_x += 15;
			base_y += 15;
			arm_x += 20;
			arm_y += 20;
		// Move base and arm with object
			cout << "Mobile Arm Robot is attempting to move its base to position (" << base_x << "," << base_y << ") at speed level " << speed << " and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
			if (mar->move(base_x, base_y, arm_x, arm_y, speed))
			{
				cout << "Mobile Arm Robot was able to successfully move its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ")." << endl;
				cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
			// Drop
				if (mar->drop())
				{
					cout << "Mobile Arm Robot was able to successfully drop the object at position (" << arm_x << "," << arm_y << ")." << endl;
					cout << "Battery percentage %" << fixed << setprecision(0) << mar->get_battery_percentage() << endl << endl;
				}
			}
		}
	}
}
