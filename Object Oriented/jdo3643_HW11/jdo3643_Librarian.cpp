#include "jdo3643_Librarian.h"

Librarian::Librarian()
{

}

Librarian::Librarian(string n, int i)
{
	name = n;
	id = i;
}

void Librarian::check_out_media(Media m)
{
	m.set_check(true);
}

void Librarian::check_in_media(Media m)
{
	m.set_check(false);
}

void Librarian::check_out_bundle(Bundle b)
{
	b.set_check(true);
}

void Librarian::check_in_bundle(Bundle b)
{
	b.set_check(false);
}

string Librarian::get_name()
{
	return name;
}