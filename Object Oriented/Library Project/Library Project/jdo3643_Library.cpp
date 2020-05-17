#include "jdo3643_Library.h"

Library::Library()
{

}

void Library::create_new_media(int id, string cn, string t, string g)
{
	Media m{ id, cn, t, g };
	medias.push_back(m);
}

void Library::create_new_bundle(string n, vector<Media> m)
{
	Bundle b{ n };
	for (int i = 0; i < m.size(); i++)
		add_to_bundle(m[i]);
	bundles.push_back(b);
}

void Library::create_new_librarian(string n, int i)
{
	Librarian librarian(n, i);
	librarians.push_back(librarian);
}

void Library::create_new_customer(string n, int i, string p, string e)
{
	Customer customer{ n, i, p, e};
	customers.push_back(customer);
}

void Library::create_new_transaction(int tn, Date cod, Date dd, Date cid, Customer c, vector<Media> m, vector<Bundle> b)
{
	Transaction transaction{ tn, cod, dd, cid, c, m, b };
	transactions.push_back(transaction);
}

vector<Customer> Library::get_customers()
{
	return customers;
}

vector<Librarian> Library::get_librarians()
{
	return librarians;
}

vector<Media> Library::get_medias()
{
	return medias;
}

vector<Bundle> Library::get_bundles()
{
	return bundles;
}

vector<Transaction> Library::get_transactions()
{
	return transactions;
}