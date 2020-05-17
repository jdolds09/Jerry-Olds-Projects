// Author: Jerry Olds
// Course: COSC 1437
// Program 2.3
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

// Function Prototype
string expression();

int main()
{
// Variables
// two minus two
	string sentence;
	int a;
	double b;
	double c;
	double result;
	char sign;
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t    Math Expression Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// Call Expression Function
	FUNCTION:sentence = expression();
// Find Operator Sign
	a = sentence.find("PLUS", 0);
	if (a != -1)
	{
		sign = '+';
	}
	a = sentence.find("MINUS", 0);
	if (a != -1)
	{
		sign = '-';
	}
	a = sentence.find("TIMES", 0);
	if (a != -1)
	{
		sign = 'x';
	}
	a = sentence.find("DIVIDED-BY", 0);
	if (a != -1)
	{
		sign = '%';
	}
// Find Second Number
	a = sentence.find("ZERO", 6);
	if (a != -1)
	{
		b = 0.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("ONE", 6);
	if (a != -1)
	{
		b = 1.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("TWO", 6);
	if (a != -1)
	{
		b = 2.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("THREE", 6);
	if (a != -1)
	{
		b = 3.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("FOUR", 6);
	if (a != -1)
	{
		b = 4.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("FIVE", 6);
	if (a != -1)
	{
		b = 5.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("SIX", 6);
	if (a != -1)
	{
		b = 6.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("SEVEN", 6);
	if (a != -1)
	{
		b = 7.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("EIGHT", 6);
	if (a != -1)
	{
		b = 8.0;
		sentence.erase(6, 25);
	}
	a = sentence.find("NINE", 6);
	if (a != -1)
	{
		b = 9.0;
		sentence.erase(6, 25);
	}
// Find First Number
	a = sentence.find("ZERO", 0);
	if (a != -1)
	{
		c = 0.0;
	}
	a = sentence.find("ONE", 0);
	if (a != -1)
	{
		c = 1.0;
	}
	a = sentence.find("TWO", 0);
	if (a != -1)
	{
		c = 2.0;
	}
	a = sentence.find("THREE", 0);
	if (a != -1)
	{
		c= 3.0;
	}
	a = sentence.find("FOUR", 0);
	if (a != -1)
	{
		c = 4.0;
	}
	a = sentence.find("FIVE", 0);
	if (a != -1)
	{
		c = 5.0;
	}
	a = sentence.find("SIX", 0);
	if (a != -1)
	{
		c = 6.0;
	}
	a = sentence.find("SEVEN", 0);
	if (a != -1)
	{
		c = 7.0;
	}
	a = sentence.find("EIGHT", 0);
	if (a != -1)
	{
		c = 8.0;
	}
	a = sentence.find("NINE", 0);
	if (a != -1)
	{
		c = 9.0;
	}
// Determine Result
	if (sign == '+')
	{
		result = c + b;
	}
	else if (sign == '-')
	{
		result = c - b;
	}
	else if (sign == 'x')
	{
		result = c * b;
	}
	else
		result = c / b;
// Display Results
	cout << "Result: " << result << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// Start Over
	if (result != 0)
	{
		goto FUNCTION;
	}
// End of Program
	return 0;
}

// Expression Prototype
string expression()
{
// Variable
	string math;
	int x;	
	int count = 0;
	char y;
// Output
	cout << "Enter the expression: ";
	getline(cin, math);	
// Change Lowercase Letters to Uppercase Letters
	x = math.length();
	while (count < x)
	{
		y = math.at(count);
		if (islower(y))
		{
			y = toupper(y);
			math.erase(count, 1);
			math.insert(count, 1, y);
		}
		count++;
	}
	return math;
}