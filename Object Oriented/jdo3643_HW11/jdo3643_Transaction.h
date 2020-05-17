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
	Date due_date;
	Date check_in_date;
	Librarian librarian;
	Customer customer;
	vector<Media> medias;
	vector<Bundle> bundles;
public:
	Transaction();
	Transaction(int tn, Date cod, Date dd, Date cid, Customer c, vector<Media> m, vector<Bundle> b);
	double calculate_fee();
};

#endif