#ifndef JDO3643_TRANSACTION_H
#define JDO3643_TRANSACTION_H

#include "jdo3643_Media.h"
#include "jdo3643_Bundle.h"
#include "jdo3643_Date.h"
#include "jdo3643_Customer.h"
#include "jdo3643_Librarian.h"

class Transaction
{
private:
	int transaction_number;
	Date check_out_date;
	Librarian librarian;
	Customer customer;
	vector<Media> media;
	vector<Bundle> bundle;
	Date check_in_date;
	Date due_date;
public:
	Transaction();
	void set_transaction_number(int tn);
	void set_librarian(Librarian l);
	void set_customer(Customer c);
	void set_media(vector<Media> m);
	void set_bundle(vector<Bundle> b);
	void set_check_out_date(int y, int m, int d);
	void set_due_date(int y, int m, int d);
	void set_check_in_date(int y, int m, int d);
	double calculate_fee(int medias, int bundles);
};

#endif