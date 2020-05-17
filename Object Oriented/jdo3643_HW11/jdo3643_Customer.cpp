#include "jdo3643_Customer.h"
#include <cmath>

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
	if(b < 0 && abs(b) > get_balance())
		balance = 0;
	else
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

void Customer::check_in_media(Media m)
{
// Variables
	bool found = false;
	int i = 0;
// Find 
	while(found == false)
	{
		if(checked_out_medias[i].get_title() == m.get_title())
			found = true;
		if(found == false)
			i++;
	}
	checked_out_medias.erase(checked_out_medias.begin() + i);
}

void Customer::check_in_bundle(Bundle b)
{
// Variables
	bool found = false;
	int i = 0;
// Find 
	while(found == false)
	{
		if(checked_out_bundles[i].get_bundle_name() == b.get_bundle_name())
			found = true;
		if(found == false)
			i++;
	}
	checked_out_bundles.erase(checked_out_bundles.begin() + i);
}

vector<Media> Customer::get_checked_out_medias()
{
	return checked_out_medias;
}

vector<Bundle> Customer::get_checked_out_bundles()
{
	return checked_out_bundles;
}
