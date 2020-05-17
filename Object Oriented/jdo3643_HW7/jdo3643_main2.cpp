#include "jdo3643_Mobile_Arm.h"

// Function prototypes
void move_mobile_robot(Robot* mr);
void move_arm_robot(Robot* ar);
void move_extendable_arm(Robot* ear);
void move_powered_arm(Robot* par);
void move_super_arm(Robot* sar);
void move_mobile_arm(Robot* mar);

int main()
{
// Program title
	cout << "=========================" << endl;
	cout << "ROBOT CONTROLLER PROGRAM" << endl;
	cout << "=========================" << endl << endl;
// List of robots
	Robot* mobile_robot = new Mobile_Robot(1001, "Mobile Robot 1001", 100);
	Robot* arm_robot = new Arm_Robot(1002, "Arm Robot 1002", 100, 15, 50);
	Robot* extendable_arm = new Extendable_Arm(1003, "Extendable Arm Robot 1003", 100, 15, 50, 15);
	Robot* powered_arm = new Powered_Arm(1004, "Powered Arm Robot 1004", 100, 15, 50, 100);
	Robot* super_arm = new Super_Arm(1005, "Super Arm Robot 1005", 100, 15, 50, 15, 100);
	Robot* mobile_arm = new Mobile_Arm(1006, "Mobile Arm Robot 1006", 100, 15, 50, 15, 100);
// Call move robot functions
	move_mobile_robot(mobile_robot);
	move_arm_robot(arm_robot);
	move_extendable_arm(extendable_arm);
	move_powered_arm(powered_arm);
	move_super_arm(super_arm);
	move_mobile_arm(mobile_arm);
// End of program
	return 0;
}

void move_mobile_robot(Robot* mr)
{
// Variables
	int x = 5;
	int y = 5;
	int speed = 1;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Title
	cout << "MOBILE ROBOT 1001" << endl;
	cout << "==================" << endl;
// Move
	cout << "Mobile Robot 1001 is attempting to move to position (" << x << "," << y << ") at speed level " << speed << ". Distance: " << distance << endl;
	if (dynamic_cast<Mobile_Robot*>(mr)->move(x,y, speed))
	{
		cout << "Mobile Robot 1001 was able to successfully move to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage: " << mr->get_battery_percentage() << endl << endl;
		x += 5;
		y += 5;
		speed++;
	// Move
		cout << "Mobile Robot 1001 is attempting to move to position (" << x << "," << y << ") at speed level " << speed << ". Distance: " << distance << endl;
		if (dynamic_cast<Mobile_Robot*>(mr)->move(x, y, speed))
		{
			cout << "Mobile Robot 1001 was able to successfully move to position (" << x << "," << y << ")." << endl;
			cout << "Battery percentage: " << mr->get_battery_percentage() << endl << endl;
			x += 5;
			y += 5;
			speed++;
		// Move
			cout << "Mobile Robot 1001 is attempting to move to position (" << x << "," << y << ") at speed level " << speed << ". Distance: " << distance << endl;
			if (dynamic_cast<Mobile_Robot*>(mr)->move(x, y, speed))
			{
				cout << "Mobile Robot 1001 was able to successfully move to position (" << x << "," << y << ")." << endl;
				cout << "Battery percentage: " << mr->get_battery_percentage() << endl << endl;
			}
		}
	}
}

void move_arm_robot(Robot* ar)
{
// Variables
	char enter;
	int x = 15;
	int y = 15;
	int weight = 75;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Title
	cout << "PRESS ENTER TO DEPLOY ARM ROBOT 1002";
	cin >> noskipws >> enter;
	cout << "\nARM ROBOT 1002" << endl;
	cout << "===============" << endl;
// Move
	cout << "Arm Robot 1002 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (ar->move(x, y))
	{
		cout << "Arm Robot 1002 was able to successfully move to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage: " << ar->get_battery_percentage() << endl << endl;
	}
	else
	{
		x = 5;
		y = 5;
		distance = sqrt(pow(x, 2) + pow(y, 2));
	// Move
		cout << "Arm Robot 1002 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
		if (ar->move(x, y))
		{
			cout << "Arm Robot 1002 was able to successfully move to position (" << x << "," << y << ")." << endl;
			cout << "Battery percentage: " << ar->get_battery_percentage() << endl << endl;
		// Pick up
			cout << "Arm Robot 1002 is attempting to pick up object that weighs " << weight << " units." << endl;
			if (dynamic_cast<Arm_Robot*>(ar)->pick_up(weight))
			{
				cout << "Arm Robot 1002 was able to successfully pick up object that weighs " << weight << " units." << endl; 
				cout << "Battery percentage: " << ar->get_battery_percentage() << endl << endl;
			}
			else
			{
				weight = 25;
			// Pick up
				cout << "Arm Robot 1002 is attempting to pick up object that weighs " << weight << " units." << endl;
				if (dynamic_cast<Arm_Robot*>(ar)->pick_up(weight))
				{
					cout << "Arm Robot 1002 was able to successfully pick up object that weighs " << weight << " units." << endl;
					cout << "Battery percentage: " << ar->get_battery_percentage() << endl << endl;
					x += 5;
					y += 5;
				// Move
					cout << "Arm Robot 1002 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
					if (ar->move(x, y))
					{
						cout << "Arm Robot 1002 was able to successfully move to position (" << x << "," << y << ")." << endl;
						cout << "Battery percentage: " << ar->get_battery_percentage() << endl << endl;
					// Drop
						if (dynamic_cast<Arm_Robot*>(ar)->drop())
						{
							cout << "Arm Robot 1002 was able to drop the object at position (" << x << "," << y << ")." << endl;
							cout << "Battery percentage: " << ar->get_battery_percentage() << endl << endl;
						}
					}
				}
			}
		}
	}
}

void move_extendable_arm(Robot* ear)
{
// Variables
	char enter;
	int x = 30;
	int y = 30;
	int weight = 75;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Title
	cout << "PRESS ENTER TO DEPLOY EXTENDABLE ARM ROBOT 1003";
	cin >> enter;
	cout << "\nEXTENDABLE ARM ROBOT 1003" << endl;
	cout << "==========================" << endl;
// Move
	cout << "Extendable Arm Robot 1003 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (ear->move(x, y))
	{
		cout << "Extendable Arm Robot 1003 was able to successfully move to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage: " << ear->get_battery_percentage() << endl << endl;
	}
	else
	{
		x = 5;
		y = 5;
		distance = sqrt(pow(x, 2) + pow(y, 2));
	// Move
		cout << "Extendable Arm Robot 1003 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
		if (ear->move(x, y))
		{
			cout << "Extendable Arm Robot 1003 was able to successfully move to position (" << x << "," << y << ")." << endl;
			cout << "Battery percentage: " << ear->get_battery_percentage() << endl << endl;
		// Pick up
			cout << "Extendable Arm Robot 1003 is attempting to pick up object that weighs " << weight << " units." << endl;
			if (dynamic_cast<Extendable_Arm*>(ear)->pick_up(weight))
			{
				cout << "Extendable Arm Robot 1003 was able to successfully pick up object that weighs " << weight << " units." << endl;
				cout << "Battery percentage: " << ear->get_battery_percentage() << endl << endl;
			}
			else
			{
				weight = 25;
			// Pick up
				cout << "Extendable Arm Robot 1003 is attempting to pick up object that weighs " << weight << " units." << endl;
				if (dynamic_cast<Extendable_Arm*>(ear)->pick_up(weight))
				{
					cout << "Extendable Arm Robot 1003 was able to successfully pick up object that weighs " << weight << " units." << endl;
					cout << "Battery percentage: " << ear->get_battery_percentage() << endl << endl;
					x += 15;
					y += 15;
					distance = sqrt(pow(x, 2) + pow(y, 2));
				// Move
					cout << "Extendable Arm Robot 1003 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
					if (ear->move(x, y))
					{
						cout << "Extendable Arm Robot 1003 was able to successfully move to position (" << x << "," << y << ")." << endl;
						cout << "Battery percentage: " << ear->get_battery_percentage() << endl << endl;
					// Drop
						if (dynamic_cast<Extendable_Arm*>(ear)->drop())
						{
							cout << "Extendable Arm Robot 1003 was able to drop the object at position (" << x << "," << y << ")." << endl;
							cout << "Battery percentage: " << ear->get_battery_percentage() << endl << endl;
						}
					}
				}
			}
		}
	}
}

void move_powered_arm(Robot* par)
{
// Variables
	char enter;
	int x = 15;
	int y = 15;
	int weight = 101;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Title
	cout << "PRESS ENTER TO DEPLOY POWERED ARM ROBOT 1004";
	cin >> enter;
	cout << "\nPOWERED ARM ROBOT 1004" << endl;
	cout << "==========================" << endl;
// Move
	cout << "Powered Arm Robot 1004 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (par->move(x, y))
	{
		cout << "Powered Arm Robot 1004 was able to successfully move to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage: " << par->get_battery_percentage() << endl << endl;
	}
	else
	{
		x = 5;
		y = 5;
		distance = sqrt(pow(x, 2) + pow(y, 2));
	// Move
		cout << "Powered Arm Robot 1004 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
		if (par->move(x, y))
		{
			cout << "Powered Arm Robot 1004 was able to successfully move to position (" << x << "," << y << ")." << endl;
			cout << "Battery percentage: " << par->get_battery_percentage() << endl << endl;
		// Pick up
			cout << "Powered Arm Robot 1004 is attempting to pick up object that weighs " << weight << " units." << endl;
			if (dynamic_cast<Powered_Arm*>(par)->pick_up(weight))
			{
				cout << "Powered Arm Robot 1004 was able to successfully pick up object that weighs " << weight << " units." << endl;
				cout << "Battery percentage: " << par->get_battery_percentage() << endl << endl;
			}
			else
			{
				weight = 75;
			// Pick up
				cout << "Powered Arm Robot 1004 is attempting to pick up object that weighs " << weight << " units." << endl;
				if (dynamic_cast<Powered_Arm*>(par)->pick_up(weight))
				{
					cout << "Powered Arm Robot 1004 was able to successfully pick up object that weighs " << weight << " units." << endl;
					cout << "Battery percentage: " << par->get_battery_percentage() << endl << endl;
					x += 5;
					y += 5;
					distance = sqrt(pow(x, 2) + pow(y, 2));
				// Move
					cout << "Powered Arm Robot 1004 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
					if (par->move(x, y))
					{
						cout << "Powered Arm Robot 1004 was able to successfully move to position (" << x << "," << y << ")." << endl;
						cout << "Battery percentage: " << par->get_battery_percentage() << endl << endl;
					// Drop
						if (dynamic_cast<Powered_Arm*>(par)->drop())
						{
							cout << "Powered Arm Robot 1004 was able to drop the object at position (" << x << "," << y << ")." << endl;
							cout << "Battery percentage: " << par->get_battery_percentage() << endl << endl;
						}
					}
				}
			}
		}
	}
}

void move_super_arm(Robot* sar)
{
// Variables
	char enter;
	int x = 30;
	int y = 30;
	int weight = 101;
	int distance = sqrt(pow(x, 2) + pow(y, 2));
// Title
	cout << "PRESS ENTER TO DEPLOY SUPER ARM ROBOT 1005";
	cin >> enter;
	cout << "\nSUPER ARM ROBOT 1005" << endl;
	cout << "=====================" << endl;
// Move
	cout << "Super Arm Robot 1005 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
	if (sar->move(x, y))
	{
		cout << "Super Arm Robot 1005 was able to successfully move to position (" << x << "," << y << ")." << endl;
		cout << "Battery percentage: " << sar->get_battery_percentage() << endl << endl;
	}
	else
	{
		x = 5;
		y = 5;
		distance = sqrt(pow(x, 2) + pow(y, 2));
	// Move
		cout << "Super Arm Robot 1005 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
		if (sar->move(x, y))
		{
			cout << "Super Arm Robot 1005 was able to successfully move to position (" << x << "," << y << ")." << endl;
			cout << "Battery percentage: " << sar->get_battery_percentage() << endl << endl;
		// Pick up
			cout << "Super Arm Robot 1005 is attempting to pick up object that weighs " << weight << " units." << endl;
			if (dynamic_cast<Super_Arm*>(sar)->pick_up(weight))
			{
				cout << "Super Arm Robot 1005 was able to successfully pick up object that weighs " << weight << " units." << endl;
				cout << "Battery percentage: " << sar->get_battery_percentage() << endl << endl;
			}
			else
			{
				weight = 75;
			// Pick up
				cout << "Super Arm Robot 1005 is attempting to pick up object that weighs " << weight << " units." << endl;
				if (dynamic_cast<Super_Arm*>(sar)->pick_up(weight))
				{
					cout << "Super Arm Robot 1005 was able to successfully pick up object that weighs " << weight << " units." << endl;
					cout << "Battery percentage: " << sar->get_battery_percentage() << endl << endl;
					x += 10;
					y += 10;
					distance = sqrt(pow(x, 2) + pow(y, 2));
				// Move
					cout << "Super Arm Robot 1005 is attempting to move arm to position (" << x << "," << y << "). Distance from base: " << distance << endl;
					if (sar->move(x, y))
					{
						cout << "Super Arm Robot 1005 was able to successfully move to position (" << x << "," << y << ")." << endl;
						cout << "Battery percentage: " << sar->get_battery_percentage() << endl << endl;
					// Drop
						if (dynamic_cast<Powered_Arm*>(sar)->drop())
						{
							cout << "Super Arm Robot 1005 was able to drop the object at position (" << x << "," << y << ")." << endl;
							cout << "Battery percentage: " << sar->get_battery_percentage() << endl << endl;
						}
					}
				}
			}
		}
	}
}

void move_mobile_arm(Robot* mar)
{
// Variables
	char enter;
	int speed = 1;
	int base_x = 5;
	int base_y = 5;
	int arm_x = 35;
	int arm_y = 35;
	int weight = 101;
	int distance_from_base = sqrt(pow(arm_x - base_x, 2) + pow(arm_y - base_y, 2));
// Title
	cout << "PRESS ENTER TO DEPLOY MOBILE ARM ROBOT 1006";
	cin >> enter;
	cout << "\nMOBILE ARM ROBOT 1006" << endl;
	cout << "=====================" << endl;
// Move
	cout << "Mobile Arm Robot 1006 is attempting to its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ") at speed level "<< speed << ". Distance from base: " << distance_from_base << endl;
	if (dynamic_cast<Mobile_Arm*>(mar)->move(base_x, base_y, arm_x, arm_y, speed))
	{
		cout << "Mobile Arm Robot 1006 was able to sucessfully move its base to position (" << base_x << "," << base_y << ") and its arm to position (" << arm_x << "," << arm_y << ")." << endl;
		cout << "Battery percentage: " << mar->get_battery_percentage() << endl << endl;
	}
	else
	{
		arm_x = 10;
		arm_y = 10;
		distance_from_base = sqrt(pow(arm_x - base_x, 2) + pow(arm_y - base_y, 2));
		// Move
		cout << "Mobile Arm Robot 1006 is attempting to its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ") at speed level " << speed << ". Distance from base: " << distance_from_base << endl;
		if (dynamic_cast<Mobile_Arm*>(mar)->move(base_x, base_y, arm_x, arm_y, speed))
		{
			cout << "Mobile Arm Robot 1006 was able to sucessfully move its base to position (" << base_x << "," << base_y << ") and its arm to position (" << arm_x << "," << arm_y << ")." << endl;
			cout << "Battery percentage: " << mar->get_battery_percentage() << endl << endl;
		// Pick up
			cout << "Mobile Arm Robot 1006 is attempting to pick up object that weighs " << weight << " units." << endl;
			if (dynamic_cast<Mobile_Arm*>(mar)->pick_up(weight))
			{
				cout << "Mobile Arm Robot 1006 was able to successfully pick up object that weighs " << weight << " units." << endl;
				cout << "Battery percentage: " << mar->get_battery_percentage() << endl << endl;
			}
			else
			{
				weight = 75;
			// Pick up
				cout << "Mobile Arm Robot 1006 is attempting to pick up object that weighs " << weight << " units." << endl;
				if (dynamic_cast<Mobile_Arm*>(mar)->pick_up(weight))
				{
					cout << "Mobile Arm Robot 1006 was able to successfully pick up object that weighs " << weight << " units." << endl;
					cout << "Battery percentage: " << mar->get_battery_percentage() << endl << endl;
					mar->charge();
					base_x += 5;
					base_y += 5;
					arm_x += 12;
					arm_y += 12;
					speed++;
					distance_from_base = sqrt(pow(arm_x - base_x, 2) + pow(arm_y - base_y, 2));
				// Move
					cout << "Mobile Arm Robot 1006 is attempting to its base to position (" << base_x << "," << base_y << ") and move its arm to position (" << arm_x << "," << arm_y << ") at speed level " << speed << ". Distance from base: " << distance_from_base << endl;
					if (dynamic_cast<Mobile_Arm*>(mar)->move(base_x, base_y, arm_x, arm_y, speed))
					{
						cout << "Mobile Arm Robot 1006 was able to sucessfully move its base to position (" << base_x << "," << base_y << ") and its arm to position (" << arm_x << "," << arm_y << ")." << endl;
						cout << "Battery percentage: " << mar->get_battery_percentage() << endl << endl;
					// Drop
						if (dynamic_cast<Mobile_Arm*>(mar)->drop())
						{
							cout << "Mobile Arm Robot 1006 was able to drop the object at position (" << arm_x << "," << arm_y << ")." << endl;
							cout << "Battery percentage: " << mar->get_battery_percentage() << endl << endl;
						}
					}
				}
			}
		}
	}
}
