#ifndef JDO3643_CUSTOMER_H
#define JDO3643_CUSTOMER_H

#include <iostream>
using namespace std;

class Customer
{
private:
	string name;
	int id;
	unsigned int phone;
	string email;
	double balance;
public:
	Customer();
	Customer(string n, int i, unsigned int p, string e);
	void add_balance(double b);
	double get_balance();
};

#endif
