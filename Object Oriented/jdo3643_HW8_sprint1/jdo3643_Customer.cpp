#include "jdo3643_Customer.h"

Customer::Customer()
{

}

Customer::Customer(string n, int i, unsigned int p, string e)
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
