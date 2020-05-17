#include "Controller.h"

void Controller::cli()
{
	int cmd = -1;
	while (cmd != 6)
	{
		cout << view.get_menu();
		cin >> cmd;
		execute_cmd(cmd);
	}
}

void Controller::execute_cmd(int cmd)
{
	
	switch (cmd)
	{
	case 1:
		cout << view.view_transactions();
		transaction_list.list_transactions();
		break;
	case 2:
		new_transaction();
		break;
	case 3:
		delete_transaction();
		break;
	case 4:
		average();
		break;
	case 5:
		bonus();
		break;
	case 6:
		break;
	default:
		cout << "Invalid input.";
	}
}

void Controller::new_transaction()
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
// Get name
	cin.ignore();
	cout << view.prompt_for_name();
	getline(cin, name);
// Get price
	cout << view.prompt_for_price();
	cin >> price;
// Get year
	cout << view.prompt_for_year();
	cin >> year;
	// Input validation
		while (year < 0)
		{
			cout << "\nInvalid year" << endl;
			cout << "Enter the year of the transaction: ";
			cin >> year;
		}
// Get month
	cout << view.prompt_for_month();
	cin >> month;
	// Input validation
		while (month < 1 || month > 12)
		{
			cout << "\nInvalid month" << endl;
			cout << "Enter the month of the transaction: ";
			cin >> month;
		}
// Get day
	cout << view.prompt_for_day();
	cin >> day;
	// Input Validation
		while ((day < 1 || day > 31) || (month == 2 && day > 29) || ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) || (month == 2 && day == 29 && (year % 4) != 0))
		{
			cout << "\nInvalid day" << endl;
			cout << "Enter the day of the transaction: ";
			cin >> day;
		}
// Get hour
	cout << view.prompt_for_hour();
	cin >> hour;
	// Input validation
		while (hour < 0 || hour > 23)
		{
			cout << "\nInvalid hour" << endl;
			cout << "Enter the hour of the transaction: ";
			cin >> hour;
		}
// Get minute
	cout << view.prompt_for_minute();
	cin >> minute;
	// Input Validation
		while (minute < 0 || minute > 59)
		{
			cout << "\nInvalid minute" << endl;
			cout << "Enter the minute of the transaction: ";
			cin >> minute;
		}
// Get second
	cout << view.prompt_for_second();
	cin >> second;
	// Input Validation
		while (second < 0 || second > 59)
		{
			cout << "\nInvalid second" << endl;
			cout << "Enter the second of the transaction: ";
			cin >> second;
		}
// Send info to classes
	Date d{ year, month, day, hour, minute, second };
	Transaction t{ price, name };
// Succesful transaction
	if (transaction_list.add_transaction(d, t))
	{
		cout << "\nTransaction added!" << endl;
		transaction_list.save();
	}
// Unsuccessful transaction
	else
		cout << "\nInvalid transaction." << endl;
}

void Controller::delete_transaction()
{
// Variables
	char selection;
	int year;
	int month;
	int day;
	int hour;
	int minute;
	int second;
	int size = transaction_list.get_size();
	string name = "";
// See if any transactions have been made
	if (size == 0)
	{
		cout << "\nNo transactions have been made!" << endl;
		return;
	}
// Prompt user if they would like to delete by name or by date
	cout << view.delete_prompt();
	cin >> selection;
	selection = toupper(selection);
	while (selection != 'D' && selection != 'N')
	{
		cout << "\nInvalid input." << endl;
		cout << "\nWould you like to delete by Date (D) or by Name (N)?" << endl;
		cout << "\Enter (D) or (N): ";
		cin >> selection;
		selection = toupper(selection);
	}
// Delete Transaction by date
	if (selection == 'D')
	{
	// Get year to be deleted
		cout << view.delete_year_prompt();
		cin >> year;
	// Get month to be deleted
		cout << view.delete_month_prompt();
		cin >> month;
	// Get day to be deleted
		cout << view.delete_day_prompt();
		cin >> day;
	// Get hour to be deleted
		cout << view.delete_hour_prompt();
		cin >> hour;
	// Get minute to be deleted
		cout << view.delete_minute_prompt();
		cin >> minute;
	// Get second to be deleted
		cout << view.delete_second_prompt();
		cin >> second;
	// Send data to class
		Date d{ year, month, day, hour, minute, second };
		transaction_list.delete_transaction_by_date(d);
	// Transaction deleted successfully
		if (transaction_list.get_size() < size)
		{
			cout << "\nTransaction deleted" << endl;
			transaction_list.save();
		}
	// Transaction deleted unsuccessfully
		else
			cout << "\nInvalid date. Transaction was not deleted." << endl;
	}
	if (selection == 'N')
	{
	// Get name to be deleted
		cin.ignore();
		cout << view.delete_name_prompt();
		getline(cin, name);
	// Send data to class
		transaction_list.delete_transactions_by_name(name);
	// Transaction deleted successfully
		if (transaction_list.get_size() < size)
		{
			cout << "\nTransaction(s) deleted" << endl;
			transaction_list.save();
		}
	// Transaction deleted unsuccessfully
		else
			cout << "\nInvalid name. Transaction was not deleted." << endl;
	}
}

void Controller::average()
{
	double average_trans;
	average_trans = transaction_list.get_average_transaction();
	cout << view.average();
	cout << fixed << setprecision(2) << average_trans << endl;
}

void Controller::bonus()
{
	if (transaction_list.get_size() == 0)
	{
		cout << "\nNo transactions made!" << endl;
		return;
	}
	string winner;
	winner = transaction_list.bonus();
	cout << view.bonus();
	cout << winner;
}
