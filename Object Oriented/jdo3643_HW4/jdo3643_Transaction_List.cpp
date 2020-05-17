#include "jdo3643_Transaction_List.h"

bool Transaction_List::add_transaction(Date d, Transaction t)
{
	return transactions.insert(make_pair(d, t)).second;
}

void Transaction_List::list_transactions()
{
	if (transactions.size() == 0)
	{
		cout << "\nNo transactions made." << endl;
		return;
	}
	map<Date, Transaction>::iterator it = transactions.begin();
	for (; it != transactions.end(); it++)
		cout << it->second << " " << it->first << endl;
}

double Transaction_List::get_average_transaction()
{
// Variables
	double count = 0.0;
	double sum = 0.0;
	map<Date, Transaction>::iterator it = transactions.begin();
// Add all transactions
	for (; it != transactions.end(); it++)
	{
		sum += it->second.get_price();
		count++;
	}
// Return average transaction
	return (sum / count);
}

string Transaction_List::bonus()
{
// Variables
	vector<string> names;
	vector<double> value;
	string name;
	string number;
	bool winner = false;
	bool flag = false;
	bool contains;
	int place;
	int count = 0;
	double highest_value = 0.0;
	map<Date, Transaction>::iterator it = transactions.begin();
	map<Date, Transaction>::iterator bonus_winner;
// Store transactions with names
	for (; it != transactions.end(); it++)
	{
		contains = false;
		name = it->second.get_name();
		for (int i = 0; i < names.size(); i++)
			if (names[i] == name)
				contains = true;
		if (!contains)
		{
			names.push_back(name);
			value.push_back(it->second.get_price());
		}
		else
		{
			for (int i = 0; i < names.size(); i++)
				if (names[i] == name && !flag)
				{
					place = i;
					flag = true;
				}
			value[place] += it->second.get_price();
		}
	}
// Find person with highest transaction value
	for (int i = 0; i < value.size(); i++)
	{
		if (value[i] > highest_value)
		{
			highest_value = value[i];
			place = i;
		}
	}
// Find bonus winner name
	it = transactions.begin();
	while (!winner)
	{
		if (it->second.get_name() == names[place])
		{
			winner = true;
			bonus_winner = it;
		}
		it++;
	}
// Remove zeros from transaction value
	number = std::to_string(highest_value);
	flag = false;
	while (!flag)
	{
		if (number.at(count) == '.')
		{
			flag = true;
			count = count + 2;
		}
		count++;
	}
	number = number.substr(0, count);
	return "\n" + bonus_winner->second.get_name() + " is the bonus winner with transactions totaling to $" + number + "\n";
}

string Transaction_List::to_string() const
{
// Variables
	string string1 = "";
	string string2 = "";
// Convert to string
	for (auto it = transactions.cbegin(); it != transactions.cend(); it++)
	{
		string1 = it->first.to_string() + "\n" + it->second.to_string() + "\n";
		string2 += string1;
		string1 = "";
	}
	return string2;
}

ostream& operator<<(ostream& ost, const Transaction_List& trans_list_two)
{
	ost << trans_list_two.to_string();
	return ost;
}

void Transaction_List::delete_transaction_by_date(Date d)
{
	transactions.erase(d);
}

void Transaction_List::delete_transactions_by_name(string n)
{
	map<Date, Transaction>::iterator it = transactions.begin();
	while (it != transactions.end())
	{
		if (it->second.get_name() == n)
		{
			transactions.erase(it);
			it = transactions.begin();
		}
		else
			it++;
	}
}

int Transaction_List::get_size()
{
	return transactions.size();
}
