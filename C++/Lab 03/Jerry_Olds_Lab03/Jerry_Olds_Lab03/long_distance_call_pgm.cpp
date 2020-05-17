// This program will determine the end time of a long
// distance call and what the cost of the call was given
// rates for certain times of the day
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
// Constants
	const double RATE1 = 0.07, RATE2 = 0.12, RATE3 = 0.28;
// Variables
	double cost1, cost2, cost3;
	int hours, minutes, startTime, duration, endTime, endTimeHours, endTimeMinutes;
	
// Beginning of Program
	
// Rates
	cout << "                       Rates\n";
	cout << "Start Time of Call                Rate Per Minute\n";
	cout << "00:00-07:59                       0.07\n";
	cout << "08:00-18:59                       0.12\n";
	cout << "19:00-23:59                       0.28\n";
	cout << "----------------------------------------------------";
	cout << endl;

// Hour of start time
	cout << "Please enter the hours (HH) of your start time: ";
	cin >> hours;
	if (0 > hours || 23 < hours)
	{
		cout << "You have entered an invalid time.\n";
		cout << "Please run the program again and enter a value between 00 and 23\n";
		return 0;
	}
// Minutes of start time
	cout << "Please enter the minutes (MM) of your start time: ";
	cin >> minutes;
	if (0 > minutes || 59 < minutes)
	{
		cout << "You have entered an invalid time.\n";
		cout << "Please run the program again and enter a value between 00 and 59\n";
		return 0;
	}
// Start time
	else if (10 > minutes)
	{
		cout << "\nYour start time was: " << hours << ":0" << minutes << endl;
		
	}
	else
		cout << "\nYour start time was: " << hours << ":" << minutes << endl;
// Start time in minutes
		startTime = (hours * 60) + minutes;
// Duration
	cout << "\nPlease enter the duration of your call in minutes: ";
	cin >> duration;
// End Time
	endTime = startTime + duration;
	if (1440 < endTime)
	{
		endTime = endTime - 1440;
		endTimeHours = endTime / 60;
		endTimeMinutes = endTime % 60;
	if (10 > endTimeMinutes)
		{
			cout << "\nYour end time was: " << endTimeHours << ":0" << endTimeMinutes << endl;
			cout << "\nNEXT DAY\n";
		}
	else
	{
		cout << "\nYour end time was: " << endTimeHours << ":" << endTimeMinutes << endl;
		cout << "\nNEXT DAY\n";
	}
	}
	else
		cout << "\nYour end time was: " << endTime / 60 << ":" << endTime % 60 << endl;
// Cost
	if (0 <= startTime && 479 >= startTime)
	{
		cost1 = duration * 0.07;
		cout << "\nThe cost of your call was: $" << fixed << showpoint << setprecision(2) << cost1 << endl;
	}
	else if (480 <= startTime && 1139 >= startTime)
	{
		cost2 = duration * 0.12;
		cout << "\nThe cost of your call was: $" << fixed << showpoint << setprecision(2) << cost2 << endl;
	}
	else if (1140 <= startTime && 1439 >= startTime)
	{
		cost3 = duration * 0.28;
		cout << "\nThe cost of your call was: $" << fixed << showpoint << setprecision(2) << cost3 << endl;
	}
	cout << endl;
return 0;
}
