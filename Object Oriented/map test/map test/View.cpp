#include "View.h"

string View::get_menu() {

	string menu = R"(
=====================================
Transaction List Management Solution
=====================================

*********************************
* (1) Print all transactions    *
* (2) Add a transaction         *
* (3) Delete a transaction(s)   *
* (4) Average transaction value *
* (5) Bonus winner              *
* (6) Exit                      *
*********************************
Selection: )";
	return menu;
}

string View::view_transactions()
{
	string header = R"(
TRANSACTIONS MADE:
==================== 
)";

	return header;
}

//**************** ADD TRANSACTION PROMPTS *******************
string View::prompt_for_name()                               
{
	string prompt = R"(
ADD TRANSACTION
+++++++++++++++++
Enter the name of the transactor: )";
	return prompt;
}

string View::prompt_for_price()
{
	string prompt = "Enter the price of the transaction: $";
	return prompt;
}

string View::prompt_for_year()
{
	string prompt = "Enter the year of the transaction: ";
	return prompt;
}

string View::prompt_for_month()
{
	string prompt = "Enter the month of the transaction: ";
	return prompt;
}

string View::prompt_for_day()
{
	string prompt = "Enter the day of the transaction: ";
	return prompt;
}

string View::prompt_for_hour()
{
	string prompt = "Enter the hour of the transaction: ";
	return prompt;
}

string View::prompt_for_minute()
{
	string prompt = "Enter the minute of the transaction: ";
	return prompt;
}

string View::prompt_for_second()
{
	string prompt = "Enter the second of the transaction: ";
	return prompt;
}
//**************************************************************

//********************* DELETE TRANSACTION PROMPTS ******************************
string View::delete_prompt()
{
	string prompt = R"(
DELETE TRANSACTION
--------------------
Would you like to delete by Date(D) or by Name(N)?
Enter (D) or (N): )";
	return prompt;
}

string View::delete_year_prompt()
{
	string prompt = "\nEnter the year of the transaction you wish to delete: ";
	return prompt;
}

string View::delete_month_prompt()
{
	string prompt = "Enter the month of the transaction you wish to delete: ";
	return prompt;
}

string View::delete_day_prompt()
{
	string prompt = "Enter the day of the transaction you wish to delete: ";
	return prompt;
}

string View::delete_hour_prompt()
{
	string prompt = "Enter the hour of the transaction you wish to delete: ";
	return prompt;
}

string View::delete_minute_prompt()
{
	string prompt = "Enter the minute of the transaction you wish to delete: ";
	return prompt;
}

string View::delete_second_prompt()
{
	string prompt = "Enter the second of the transaction you wish to delete: ";
	return prompt;
}

string View::delete_name_prompt()
{
	string prompt = "\nEnter the name of the transactor : ";
	return prompt;
}
//************************************************************************************

string View::average()
{
	string header = R"(
AVERAGE TRANSACTION VALUE
****************************
Average transaction: )";
	return header;
}

string View::bonus()
{
	string header = R"(
BONUS WINNER
***************
)";
	return header;
}
