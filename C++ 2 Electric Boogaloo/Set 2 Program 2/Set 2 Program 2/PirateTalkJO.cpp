// Author: Jerry Olds
// Course: COSC 1437
// Program 2.2 (***EXTRA CREDIT***)
#include<iostream>
#include<string>
#include<cctype>
using namespace std;

// Function Prototype
string pirateTalk();

int main()
{
// Variables
	string pirate;
	int x;
	int y;
	char punctuation;
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t    Pirate Talk Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// Call Pirate Talk Function
	FUNCTION: pirate = pirateTalk();
// End Program
	if (pirate == "quit" || pirate == "Quit")
		return 0;
// Punctuation
	punctuation = pirate.back();
	x = pirate.find('!', 0);
	if (x != -1)
	{
		pirate.erase(x, 1);
	}
	x = pirate.find('?', 0);
	if (x != -1)
	{
		pirate.erase(x, 1);
	}
	x = pirate.find('.', 0);
	if (x != -1)
	{
		pirate.erase(x, 1);
	}
// String Manipulation
	y = pirate.length();
	pirate.insert(0, 1, ' ');
	pirate.insert(y + 1, 1, ' ');
	pirate.insert(0, "Arr, me hearty, ");
	FIND1:x = pirate.find('g', 0);
	while (x != -1)
	{
		pirate.replace(x, 1, "\'");
		goto FIND1;
	}
	FIND2:x = pirate.find('v', 0);
	while (x != -1)
	{
		pirate.replace(x, 1, "\'");
		goto FIND2;
	}
	FIND3:x = pirate.find(" hey ", 0);
	while (x != -1)
	{
		pirate.replace(x, 5, " ahoy ");
		goto FIND3;
	}
	FIND4:x = pirate.find(" of ", 0);
	while (x != -1)
	{
		pirate.replace(x, 4, " o\' ");
		goto FIND4;
	}
	FIND5:x = pirate.find(" you ", 0);
	while (x != -1)
	{
		pirate.replace(x, 5, " ye ");
		goto FIND5;
	}
	FIND6:x = pirate.find(" your ", 0);
	while (x != -1)
	{
		pirate.replace(x, 6, " yer ");
		goto FIND6;
	}
	FIND7:x = pirate.find(" my ", 0);
	while (x != -1)
	{
		pirate.replace(x, 4, " me ");
		goto FIND7;
	}
	FIND8:x = pirate.find(" are ", 0);
	while (x != -1)
	{
		pirate.replace(x, 5, " be ");
		goto FIND8;
	}
	FIND9:x = pirate.find(" is ", 0);
	while (x != -1)
	{
		pirate.replace(x, 4, " be ");
		goto FIND9;
	}
	y = pirate.length();
	pirate.erase(16, 1);
	pirate.erase(y - 2, 1);
	pirate.append(", matey");
// Display Results
	if (punctuation == '!' || punctuation == '?' || punctuation == '.')
	{
		cout << endl << pirate << punctuation << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
	}
	else
	{
		cout << endl << pirate << endl << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
	}
// Start Over
	goto FUNCTION;
}

// Pirate Talk Function
string pirateTalk()
{
// Local Variables
	string talk;
	int y;
	int count = 0;
// Output
	PROMPT:cout << "Enter yer input: ";
	getline(cin, talk);
// Limit Caracters
	y = talk.length();
	while (y >= 58)
	{
		cout << "\nPlease keep input under 59 characters." << endl;
		cout << "-------------------------------------------------------------------------------" << endl;
		goto PROMPT;
	}
	return talk;
}
