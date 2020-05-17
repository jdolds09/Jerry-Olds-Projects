#include<iostream>
using namespace std;

int main()
{	
// Variables
	int hour1;
	int minute1;
	int hour2;
	int minute2;
	int minute;
	int hour;
	double result;
	char goAgain = 'y';
	while (goAgain == 'y')
	{
		cout << "Please enter hour: ";
		cin >> hour1;
		cout << "Please enter minute: ";
		cin >> minute1;
		cout << "Please enter hour: ";
		cin >> hour2;
		cout << "Please enter minute: ";
		cin >> minute2;
		cout << endl;
		if (minute2 < minute1)
		{
			hour2--;
			minute2 += 60;
			minute = minute2 - minute1;
		}
		else
			minute = minute2 - minute1;
		if (hour2 < hour1)
		{
			hour2 += 24;
			hour = hour2 - hour1;
		}
		else
			hour = hour2 - hour1;
		hour *= 60;
		minute += hour;
		result = minute / 60.0;
		cout << "Time Elapsed: " << result << endl;
		cout << "Go again? ";
		cin >> goAgain;
	}
}