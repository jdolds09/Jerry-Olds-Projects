#include "jdo3643_Transaction.h"

Transaction::Transaction(double p, string n)
{
	price = p;
	name = n;
}

double Transaction::get_price()
{
	return price;
}

string Transaction::get_name()
{
	return name;
}

string Transaction::to_string() const
{
// Get rid of zeros after second decimal value
	int i = 0;
	string number = std::to_string(price);
	bool flag = false;
	while (!flag)
	{
		if (number.at(i) == '.')
		{
			flag = true;
			i = i + 2;
		}
		i++;
	}
	number = number.substr(0, i);
// Return result
	return "\nName:  " + name + "\nPrice: $" + number;
}

ostream& operator<<(ostream& ost, const Transaction& transaction_two)
{
	ost << transaction_two.to_string();
	return ost;
}
