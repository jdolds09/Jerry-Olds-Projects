// Author: Jerry Olds
// Course: COSC 1437
// Program 1
// References: http://www.cplusplus.com/reference/cmath/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// Function Prototype
double gosper(int n);

int main()
{
// Variable
	int number;
	double result;
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tGosper Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Enter a postive integer (0-7): ";
// Input
	cin >> number;
	cout << endl;
// Input Validation
	while (number < 0 || number > 7)
	{
		cout << "Invalid input." << endl;
		cout << "\nPlease enter a positive integer (0-7): ";
		cin >> number;
		cout << endl;
	}
// Call Gosper Function
	result = gosper(number);
// Display Result
	cout << fixed << showpoint << setprecision(4);
	cout << number << "! is approximately " << result << endl;
	cout << endl;
// End of Program
	return 0;
}
// Gosper Function
double gosper(int n)
{
// Local Varibales
	const double PI = 3.1415926535897;
	double factorial;
	double x;
	double y;
	double z;
// Gosper Formula
	x = (2 * n + (1.0 / 3.0)) * PI;
	y = sqrt(x);
	z = pow(n, n) * exp(-n);
	return factorial = y * z;
}