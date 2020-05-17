#include "jdo3643_Controller.h"

int Controller::customer_select(vector<Customer> c)
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input validation
	while (selection < 1 || selection > c.size())
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	return selection;
}

int Controller::librarian_select(vector<Librarian> l)
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input validation
	while (selection < 1 || selection > l.size())
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	return selection;
}

int Controller::menu_select()
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input Validation
	while (selection < 1 || selection > 6)
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	return selection;
}

int Controller::media_select(vector<Media> m)
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input validation
	while (selection < 1 || selection > m.size() + 1)
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	return selection;
}

int Controller::bundle_select()
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input validation
	while (selection < 1 || selection > 5)
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	return selection;
}

int Controller::media_check_in_select(vector<Media> m)
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input validation
	while (selection < 1 || selection > m.size())
	{
		cout << "\nInvalid input." << endl;
		cout << "Please choose one to check in: ";
		cin >> selection;
	}
	return selection;
}

int Controller::bundle_check_in_select(vector<Bundle> b)
{
// Variable
	int selection;
// Input
	cin >> selection;
// Input validation
	while (selection < 1 || selection > b.size())
	{
		cout << "\nInvalid input." << endl;
		cout << "Please choose one to check in: ";
		cin >> selection;
	}
	return selection;
}
