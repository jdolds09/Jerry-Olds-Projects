// Author: Jerry Olds
// Course: COSC 1437
// Program 3.1
#include<iostream>
using namespace std;

// Running Total Template
template <class T>
double total(T number)
{
// Variables
	double value;
	double sum = 0;
	for (int count = 0; count < number; count++)
	{
		cout << "Please enter a value: ";
		cin >> value;
		sum += value;
	}
	return sum;
}

int main()
{
// Variable
	int values;
	double result;
// Title
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t   Total Template Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// User Prompt
	cout << "Please enter the number of values to be totaled: ";
	cin >> values;
// Input Validation
	while (values < 0)
	{
		cout << "Invalid Input." << endl;
		cout << "Please enter the number of values to be totaled: ";
		cin >> values;
	}
	cout << "-------------------------------------------------------------------------------" << endl;
// Call Template
	result = total(values);
// Display Result
	cout << "\nTotal: " << result << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// End of Program
	return 0;
}