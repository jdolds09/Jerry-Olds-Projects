#ifndef JDO3643_LIBRARY_H
#define JDO3643_LIBRARY_H

#include "jdo3643_Media.h"
#include "jdo3643_Bundle.h"
#include "jdo3643_Customer.h"
#include "jdo3643_Librarian.h"
#include "jdo3643_Transaction.h"

class Library : public Bundle, public Transaction, public Media
{
private:
	vector<Media> medias;
	vector<Transaction> transactions;
	vector<Customer> customers;
	vector<Librarian> librarians;
	vector<Bundle> bundles;
public:
	Library();
	void create_new_media(int id, string cn, string t, string g);
	void create_new_bundle(string n, vector<Media> medias);
	void create_new_librarian(string n, int i);
	void create_new_customer(string n, int i, string p, string e);
	void create_new_transaction(int tn, Date cod, Date dd, Date cid, Customer c, vector<Media> m, vector<Bundle> b);
	vector<Customer> get_customers();
	vector<Librarian> get_librarians();
	vector<Media> get_medias();
	vector<Bundle> get_bundles();
	vector<Transaction> get_transactions();
};

#endif