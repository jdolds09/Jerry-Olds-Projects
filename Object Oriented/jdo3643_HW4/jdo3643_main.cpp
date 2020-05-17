#include "jdo3643_Transaction_List.h"

// Global variable
int transactions_made = 0;
// Function Prototypes
void display(Transaction_List *list);
void new_transaction(Transaction_List *list);
void delete_transaction(Transaction_List *list);
void average(Transaction_List *list);
void get_bonus(Transaction_List *list);

int main()
{
// Variables
	int choice;
// Transaction list object
	Transaction_List list{};
	do
	{
	// User prompt
		cout << "\nWelcome to the Transaction List Management Solution." << endl;
		cout << "Please make a selection from the following menu: " << endl;
		cout << "1: Print all transactions" << endl;
		cout << "2: Add a transaction" << endl;
		cout << "3: Delete a transaction(s)" << endl;
		cout << "4: Average transaction value" << endl;
		cout << "5: Bonus winner" << endl;
		cout << "6: Exit" << endl;
		cout << "\nSelection: ";
	// User input
		cin >> choice;
		while (choice < 1 || choice > 6)
		{
			cout << "\nInvalid input.";
			cout << "\nSelection: ";
			cin >> choice;
		}
	// Preform Action
		switch (choice)
		{
		case 1:
			display(&list);
			break;
		case 2:
			new_transaction(&list);
			break;
		case 3:
			delete_transaction(&list);
			break;
		case 4:
			average(&list);
			break;
		case 5:
			get_bonus(&list);
			break;
		}
	} while (choice != 6);
// End of program
	return 0;
}

void display(Transaction_List *list)
{
	list->list_transactions();
}

void new_transaction(Transaction_List *list)
{
// Variables
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	double price;
	string name;
	string buffer;
// Get transaction info
	getline(cin, buffer);
	cout << "\nEnter the name of the transactor: ";
	getline(cin, name);
	cout << "Enter the price of the transaction: $";
	cin >> price;
	cout << "Enter the year of the transaction: ";
	cin >> year;
	while (year < 0)
	{
		cout << "\nInvalid year" << endl;
		cout << "Enter the year of the transaction: ";
		cin >> year;
	}
	cout << "Enter the month of the transaction: ";
	cin >> month;
	while (month < 1 || month > 12)
	{
		cout << "\nInvalid month" << endl;
		cout << "Enter the month of the transaction: ";
		cin >> month;
	}
	cout << "Enter the day of the transaction: ";
	cin >> day;
	while ((day < 1 || day > 31) || (month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (month == 2 && day == 29 && (year % 4) != 0))
	{
		cout << "\nInvalid day" << endl;
		cout << "Enter the day of the transaction: ";
		cin >> day;
	}
	cout << "Enter the hour of the transaction: ";
	cin >> hour;
	while (hour < 0 || hour > 23)
	{
		cout << "\nInvalid hour" << endl;
		cout << "Enter the hour of the transaction: ";
		cin >> hour;
	}
	cout << "Enter the minute of the transaction: ";
	cin >> minute;
	while (minute < 0 || minute > 59)
	{
		cout << "\nInvalid minute" << endl;
		cout << "Enter the minute of the transaction: ";
		cin >> minute;
	}
	cout << "Enter the second of the transaction: ";
	cin >> second;
	while (second < 0 || second > 59)
	{
		cout << "\nInvalid second" << endl;
		cout << "Enter the second of the transaction: ";
		cin >> second;
	}
// Send info to classes
	Date d{ year, month, day, hour, minute, second };
	Transaction t{ price, name };
// Successful transaction
	if (list->add_transaction(d, t))
	{
		cout << "\nTransaction added!" << endl;
		transactions_made++;
	}
// Unsuccessful transaction
	else
		cout << "\nInvalid transaction." << endl;
}

void delete_transaction(Transaction_List *list)
{
// Variables
	char selection;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int size = list->get_size();
	string name = "";
	string buffer;
// Check to see if any transactions have been made
	if (transactions_made == 0)
	{
		cout << "\nNo transactions have been made!" << endl;
		return;
	}
// Prompt user for which transaction to be deleted
	cout << "\nWould you like to delete by Date (D) or by Name (N)?" << endl;
	cout << "Enter (D) or (N): ";
	cin >> selection;
	selection = toupper(selection);
	while (selection != 'D' && selection != 'N')
	{
		cout << "\nInvalid input." << endl;
		cout << "\nWould you like to delete by Date (D) or by Name (N)?" << endl;
		cout << "Enter (D) or (N): ";
		cin >> selection;
		selection = toupper(selection);
	}
// Delete transaction by date
	if (selection == 'D')
	{
		cout << "\nEnter the year of the transaction you wish to delete: ";
		cin >> year;
		cout << "Enter the month of the transaction you wish to delete: ";
		cin >> month;
		cout << "Enter the day of the transaction you wish to delete: ";
		cin >> day;
		cout << "Enter the hour of the transaction you wish to delete: ";
		cin >> hour;
		cout << "Enter the minute of the transaction you wish to delete: ";
		cin >> minute;
		cout << "Enter the second of the transaction you wish to delete: ";
		cin >> second;
		Date d{ year, month, day, hour, minute, second };
		list->delete_transaction_by_date(d);
		if (list->get_size() < size)
		{
			cout << "\nTransaction deleted!" << endl;
			transactions_made--;
		}
		else
			cout << "\nInvalid date. Transaction was not deleted." << endl;
	}
// Delete transaction(s) by name
	if (selection == 'N')
	{
		getline(cin, buffer);
		cout << "\nEnter the name of the transactor : ";
		getline(cin, name);
		list->delete_transactions_by_name(name);
		if (list->get_size() < size)
		{
			cout << "\nTransaction(s) deleted!" << endl;
			transactions_made--;
		}
		else
			cout << "\nInvalid name. Transaction was not deleted." << endl;
	}
}

void average(Transaction_List *list)
{
	double average_trans;
	average_trans = list->get_average_transaction();
	cout << "\nAverage transaction: " << fixed << setprecision(2) << average_trans << endl;
}

void get_bonus(Transaction_List *list)
{
	string winner;
	winner = list->bonus();
	cout << winner;
}
