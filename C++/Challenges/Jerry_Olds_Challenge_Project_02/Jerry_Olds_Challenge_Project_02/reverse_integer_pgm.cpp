// This program will take an integer between 0 and 
// 9999 and will print the reverse of the number.
#include <iostream>
using namespace std;

int main()
{
// Variables
	int number, a, b, c;
	
// Beginning of Program
	cout << "Please enter a integer (0-9999) and I will print the\n";
	cout << "reverse of that number: ";
	cin >> number;
	cout << endl;
	if (number < 0 || number > 9999)
	{
		cout << "Invalid number. ";
		cout << "Please enter a integer between 0 and 9999.\n" << endl;
		return 0;
	}
	else
	a = number % 10;

	if (a == number)
	{
		cout << "The reverse of your number is: " << number << endl << endl;
		return 0;
	}
	
	else
	a *= 10;
	number /= 10;
	b = number % 10;
	
	if (b == number)
	{
		cout << "The reverse of your number is: " << a + number << endl << endl;
		return 0;
	}
	else
	a *= 10;
	b *= 10;
	number /= 10;
	c = number % 10;

	if (c == number)
	{
		cout << "The reverse of your number is: " << a + b + number << endl << endl;
		return 0;
	}
	else
	a *= 10;
	b *= 10;
	c *= 10;
	number /= 10;

		cout << "The reverse of your number is: " << a + b + c + number << endl << endl;
	return 0;
}