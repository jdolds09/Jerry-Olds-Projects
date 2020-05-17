#include "jdo3643_Customer.h"

Customer::Customer()
{

}

Customer::Customer(string n, int i, string p, string e)
{
	name = n;
	id = i;
	phone = p;
	email = e;
	balance = 0;
}

void Customer::add_balance(double b)
{
	balance += b;
}

double Customer::get_balance()
{
	return balance;
}

string Customer::get_name()
{
	return name;
}

string Customer::get_phone()
{
	return phone;
}

string Customer::get_email()
{
	return email;
}

void Customer::check_out_media(Media m)
{
	checked_out_medias.push_back(m);
}

void Customer::check_out_bundle(Bundle b)
{
	checked_out_bundles.push_back(b);
}

vector<Media> Customer::get_checked_out_medias()
{
	return checked_out_medias;
}

vector<Bundle> Customer::get_checked_out_bundles()
{
	return checked_out_bundles;
}