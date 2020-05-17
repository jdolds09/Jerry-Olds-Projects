// This program will calculate N terms of the 
// fibonacci sequence
#include <iostream>
using namespace std;

// Function prototype
long fibonacci(long);

// Beginning of program
int main()
{
	// Variables
	int n;
	int counter;
// Program Title
	cout << "\t\t\tFibonacci Sequence Program";
	cout << endl;
	cout << "-------------------------------------------------------------------------------";
	cout << endl;
// User input
	cout << "Please enter the number of terms: ";
	cin >> n;
// Input Validation
	while (n <= 0 || n > 40)
	{
		cout << "Invalid input.\n";
		cout << "Please enter a number between 1 and 40: ";
		cin >> n;
	}
	cout << endl;
	cout << "Fibonacci Sequence for " << n << " terms:";
	cout << endl << endl;
// Loop
	for (counter = 1; counter < n + 1; counter++)
	{
		cout << " " << fibonacci(counter);			
		if (counter % 5 == 0)
			cout << endl;
	}
	cout << endl << endl;
return 0;
}
// Fibonacci Function
long fibonacci(long n)
{
	if (n == 0 || n == 1)
	{
		return n;
	}
	else
	{
		return (fibonacci(n - 1) + fibonacci(n - 2));
	}
}
