#include "jdo3643_Library.h"

Library::Library()
{

}

void Library::create_new_media(int id, string cn, string t, string g)
{
	Media media{ id, cn, t, g };
	medias.push_back(media);
}

void Library::create_new_bundle(string n, vector<Media> m)
{
	Bundle bundle{ n, false };
	for (int i = 0; i < m.size(); i++)
		add_to_bundle(m[i]);
	bundles.push_back(bundle);
}

void Library::create_new_librarian(string n, int i)
{
	Librarian librarian;
	librarian.set_name(n);
	librarian.set_id(i);
	librarians.push_back(librarian);
}

void Library::create_new_customer(string n, int i, unsigned int p, string e)
{
	Customer customer{ n, i, p, e};
	customers.push_back(customer);
}

void Library::create_new_transaction()
{
	set_transaction_number(1);
	set_librarian(librarians[0]);
	set_customer(customers[0]);
	set_media(medias);
	set_bundle(bundles);
	set_check_out_date(2018, 3, 31);
	set_due_date(2018, 4, 2);
	set_check_in_date(2018, 4, 1);
}
