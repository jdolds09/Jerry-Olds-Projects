#ifndef JDO3643_CUSTOMER_H
#define JDO3643_CUSTOMER_H

#include "jdo3643_Bundle.h"

class Customer
{
private:
	string name;
	int id;
	string phone;
	string email;
	double balance;
	vector<Media> checked_out_medias;
	vector<Bundle> checked_out_bundles;
public:
	Customer();
	Customer(string n, int i, string p, string e);
	void add_balance(double b);
	string get_name();
	string get_phone();
	string get_email();
	double get_balance();
	void check_out_media(Media m);
	void check_out_bundle(Bundle b);
	vector<Media> get_checked_out_medias();
	vector<Bundle> get_checked_out_bundles();
};

#endif