// This program will calculate the difference of two
// sequential factorial numbers until the difference 
// is less than 0.000001
#include <iostream>
#include <iomanip>
using namespace std;

// Function Prototype
long factorial(long n);

int main()
{
// Variables
	int n = 0;
	double old_e = 0.0;
	double new_e = 1.0;

// Start of program
	cout << "\t\t\tFactorial Program" << endl;
	cout << "--------------------------------------------------------------------------";
	cout << endl;
	while (new_e - old_e > 0.000001)
	{
		cout << fixed << showpoint << setprecision(7);
		old_e = new_e;
		new_e = new_e + 1.0 / (factorial(++n));
		cout << "N = " << n << "\te(" << (n - 1) << ") = " << old_e;
		cout << "\te(" << n << ") = " << new_e;
		cout << "\tdelta = " << (new_e - old_e);
		cout << endl;
	}
	cout << "--------------------------------------------------------------------------";
	cout << endl;
	cout << "N = " << n << endl;
	cout << "e(" << n - 1 << ") = " << old_e << endl;
	cout << "e(" << n << ") = " << new_e;
	cout << endl;
return 0;
}

// Factorial function
long factorial(long n)
{
	if (n == 0)
		return 1;
	else	
		return(n * factorial(n - 1));
}