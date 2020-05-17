#include "jdo3643_Transaction.h"

Transaction::Transaction()
{
}

void Transaction::set_transaction_number(int tn)
{
	transaction_number = tn;
}

void Transaction::set_librarian(Librarian l)
{
	librarian = l;
}

void Transaction::set_customer(Customer c)
{
	customer = c;
}

void Transaction::set_media(vector<Media> m)
{
	for (int i = 0; i < m.size(); i++)
		media.push_back(m[i]);
}

void Transaction::set_bundle(vector<Bundle> b)
{
	for (int i = 0; i < b.size(); i++)
		bundle.push_back(b[i]);
}

void Transaction::set_check_out_date(int y, int m, int d)
{
	Date date{y, m, d};
	check_out_date = date;
}

void Transaction::set_due_date(int y, int m, int d)
{
	Date date{ y, m, d };
	due_date = date;
}

void Transaction::set_check_in_date(int y, int m, int d)
{
	Date date{ y, m, d };
	check_in_date = date;
}

double Transaction::calculate_fee(int medias, int bundles)
{
	double price = 0.0;
	if (check_in_date.get_year() > due_date.get_year() || check_in_date.get_year() == due_date.get_year() && check_in_date.get_month() > due_date.get_month() || check_in_date.get_year() == due_date.get_year() && check_in_date.get_month() == due_date.get_month() && check_in_date.get_day() > due_date.get_day())
	{
		price += medias * 5.0;
		price += bundles * 10.0;
		price += 25.0;
	}
	else
	{
		price += bundles * 5.0;
		price += bundles * 10.0;
	}

	return price;
}