#include "jdo3643_Transaction.h"
#include <iomanip>

Transaction::Transaction()
{

}

Transaction::Transaction(int tn, Date cod, Date dd, Date cid, Customer c, vector<Media> m, vector<Bundle> b)
{
	transaction_number = tn;
	check_out_date = cod;
	due_date = dd;
	check_in_date = cid;
	customer = c;
	medias = m;
	bundles = b;
}

double Transaction::calculate_fee()
{
	double price = 0.0;
	if (check_in_date.get_year() > due_date.get_year() || check_in_date.get_year() == due_date.get_year() && check_in_date.get_month() > due_date.get_month() || check_in_date.get_year() == due_date.get_year() && check_in_date.get_month() == due_date.get_month() && check_in_date.get_day() > due_date.get_day())
	{
		price += medias.size() * 5.0;
		price += bundles.size() * 10.0;
		price += 25.0;
		cout << endl << customer.get_name() << " checked in items past the due date. An additional $25.00 late fee will be added to the transaction." << endl;
		cout << "-------------" << endl;
		cout << fixed << setprecision(2) << "Total cost: " << price << endl << endl;;
	}
	else
	{
		price += medias.size() * 5.0;
		price += bundles.size() * 10.0;
		cout << endl << "-------------" << endl;
		cout << fixed << setprecision(2) << "Total cost: $" << price << endl << endl;
	}
	return price;
}