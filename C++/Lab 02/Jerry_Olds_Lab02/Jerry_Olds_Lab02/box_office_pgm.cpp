// This program will calculate the gross and net profit
// of a box office in one night.
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	// Constants
	const double ADULT_TICKET = 5.5;
	const double CHILD_TICKET = 2.25;
	// Variables
	string movieTitle;
	int adult;
	int child;
	// Input
	cout << "Please enter the movie title: ";
	getline(cin, movieTitle);
	cout << "Please enter the number of adult tickets sold: ";
	cin >> adult;
	cout << "Please enter the number of child tickets sold: ";
	cin >> child;
	cout << "--------------------------------------------------------";
	// More Variables
	double totalSales = (adult * ADULT_TICKET) + (child * CHILD_TICKET);
	double boxOffice = totalSales * .2;
	double distributor = totalSales * .8;
	// Output
	cout << showpoint << setprecision(2) << fixed;
	cout << "\nTotal sales for the night: " << setw(2) << "$" << totalSales << endl;
	cout << "Net box office profit: " << setw(6) << "$" << boxOffice << endl;
	cout << "Amount paid to distributor: $" << right << distributor << endl;
	cout << endl;
	// End of Program
	return 0;
}