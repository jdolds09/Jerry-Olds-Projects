// This program will calculate total time parked and the 
// total charges of using a parking lot given the type of vehicle
// and the time entering and leaving the lot.
#include <iostream>
#include <iomanip>
using namespace std;

// Constants
const double FIRST_CAR_RATE = 0.0, SECOND_CAR_RATE = 1.25,
FIRST_BUS_RATE = 2.0, SECOND_BUS_RATE = 2.5,
FIRST_TRUCK_RATE = 3.75, SECOND_TRUCK_RATE = 4.5;

// Function Prototypes
void showMenu();
int time(int, int, int, int);
double rate(char, int, double, double, double, double, double, double);
void printReport(char, int, int, int, int, int, double);

// Beginning of Program
int main()
{
// Variables
	char vehicle;
	int hourIn, minuteIn, hourOut, minuteOut;
//Call Menu
	showMenu();
// Prompt user for vehicle
	cout << "Please enter the type of vehicle (C,B,T): ";
	cin >> vehicle;
// Input Validation
	while (vehicle != 'c' && vehicle != 'C' &&
		vehicle != 'b' && vehicle != 'B' &&
		vehicle != 't' && vehicle != 'T')
	{
		cout << "Invalid input." << endl;
		cout << "Please try again (C,B,T): ";
		cin >> vehicle;
	}
// Prompt user for Hours In
	cout << "Hours In (HH): ";
	cin >> hourIn;
// Input Validation
	while (hourIn < 0 || hourIn > 23)
	{
		cout << "Invalid input." << endl;
		cout << "Please enter a integer between 1 and 23: ";
		cin >> hourIn;
	}
// Prompt user for Minutes In
	cout << "Minutes In (MM): ";
	cin >> minuteIn;
// Input Validation
	while (minuteIn < 0 || minuteIn > 59)
	{
		cout << "Invalid input." << endl;
		cout << "Please enter a integer between 1 and 59: ";
		cin >> minuteIn;
	}
// Prompt user for Hours Out
	cout << "Hours Out (HH): ";
	cin >> hourOut;
// Input Validation
	while (hourOut < 0 || hourOut > 23)
	{
		cout << "Invalid input." << endl;
		cout << "Please enter a integer between 1 and 23: ";
		cin >> hourOut;
	}
	while (hourOut < hourIn)
	{
		cout << "NO OVERNIGHT PARKING!!!!!!" << endl;
		cout << "Please try again: ";
		cin >> hourOut;
	}
// Prompt user for Minutes Out
	cout << "Minutes Out (MM): ";
	cin >> minuteOut;
// Input Validation
	while (minuteOut < 0 || minuteOut > 59)
	{
		cout << "Invalid input." << endl;
		cout << "Please enter a integer between 1 and 59: ";
		cin >> minuteOut;
	}	
	while (hourOut == hourIn && minuteOut < minuteIn)
	{
		cout << "NO OVERNIGHT PARKING!!!!!!" << endl;
		cout << "Please try again: ";
		cin >> minuteOut;
	}
	cout << "--------------------------------------------------------------" << endl;
// Time Variable
	int roundedTotal;
// Call Time Function
	roundedTotal = time(hourIn, hourOut, minuteIn, minuteOut);
// Rate Variable
	double totalCharge;
// Call Rate Function
	totalCharge = rate(vehicle, roundedTotal, FIRST_CAR_RATE, SECOND_CAR_RATE, FIRST_BUS_RATE, SECOND_BUS_RATE, FIRST_TRUCK_RATE, SECOND_TRUCK_RATE);
// Call Print Report Function	
	printReport(vehicle, minuteIn, hourIn, minuteOut, hourOut, roundedTotal, totalCharge);
return 0;
}

// Menu Function
void showMenu()
{
// Menu
	cout << "--------------------------------------------------------------" << endl;
	cout << "CAR\t\t\t" << "BUS\t\t\t" << "TRUCK" << endl;
	cout << "--------------------------------------------------------------" << endl;
	cout << "First 3 hours\t\t" << "First 2 hours\t\t" << "First 1 hours" << endl;
	cout << "$0.00\t\t\t" << "$2.00\t\t\t" << "$3.75" << endl;
	cout << "After 3 hours\t\t" << "After 2 hours\t\t" << "After 1 hours" << endl;
	cout << "$1.25\t\t\t" << "$2.50\t\t\t" << "$4.50" << endl;
	cout << "\t\t    NO OVERNIGHT PARKING" << endl;
	cout << "--------------------------------------------------------------" << endl;
}
// Time function
int time(int hourIn, int hourOut, int minuteIn, int minuteOut)
{
// Variables
	int hourParkTime, minuteParkTime, roundHours;
// Time Mathmatical Validation
if (minuteOut < minuteIn)
	{
		minuteOut += 60;
		hourOut -= 1;
		hourParkTime = hourOut - hourIn;
		minuteParkTime = minuteOut - minuteIn;
	}
else
	{
		hourParkTime = hourOut - hourIn;
		minuteParkTime = minuteOut - minuteIn;
	}
// Determining Hours Parked
if (minuteParkTime >= 1)
	{
		roundHours = hourParkTime + 1;
		return roundHours;
	}
else
	{
		roundHours = hourParkTime;
		return roundHours;
	}
}
// Rate function
double rate(char vehicle, int roundedTotal, double FIRST_CAR_RATE, double SECOND_CAR_RATE, double FIRST_BUS_RATE,
	double SECOND_BUS_RATE, double FIRST_TRUCK_RATE, double SECOND_TRUCK_RATE)
{
// Variables
	int units;
	double firstRate, secondRate;
// Determining the Rate
	switch (vehicle)
	{
	case 'C':
	case 'c': units = 3;
		firstRate = FIRST_CAR_RATE;
		secondRate = SECOND_CAR_RATE;
		break;
	case 'B':
	case 'b': units = 2;
		firstRate = FIRST_BUS_RATE;
		secondRate = SECOND_BUS_RATE;
		break;
	case 'T':
	case 't': units = 1;
		firstRate = FIRST_TRUCK_RATE;
		secondRate = SECOND_TRUCK_RATE;
		break;
	}
// Charge
	if (roundedTotal <= units)
	{
		return roundedTotal * firstRate;
	}
	else
	{
		return (units * firstRate) + ((roundedTotal - units) * secondRate);
	}
}
// Print Report function
void printReport(char vehicle, int minuteIn, int hourIn, int minuteOut, int hourOut, int roundedTotal, double totalCharge)
{
	cout << "Type of vehicle: ";

	if (vehicle == 'c' || vehicle == 'C')
	{
		cout << "CAR" << endl;
	}
	else if (vehicle == 'b' || vehicle == 'B')
	{
		cout << "BUS" << endl;
	}
	else
	{
		cout << "TRUCK" << endl;
	}
	if (minuteIn < 10)
	{
		cout << "Time In: " << hourIn << ":0" << minuteIn << endl;
	}
	else
	{
		cout << "Time In: " << hourIn << ":" << minuteIn << endl;
	}
	if (minuteOut < 10)
	{
		cout << "Time Out: " << hourOut << ":0" << minuteOut << endl;
	}
	else
	{
		cout << "Time Out: " << hourOut << ":" << minuteOut << endl;
	}
	cout << "--------------------------------------------------------------" << endl;
	cout << "Total Time Parked: " << roundedTotal << " Hours" << endl;
	cout << fixed << showpoint << setprecision(2);
	cout << "Total Charges: $" << totalCharge << endl;
	cout << "--------------------------------------------------------------" << endl;
}