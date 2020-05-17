#include "jdo3643_Book.h"

Book::Book()
{

}

Book::Book(string a, int cy)
{
	author = a;
	copyright_year = cy;
}

string Book::get_author()
{
	return author;
}

int Book::get_year()
{
	return copyright_year;
}