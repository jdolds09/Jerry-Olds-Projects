#ifndef JDO3643_LIBRARIAN_H
#define JDO3643_LIBRARIAN_H

#include "jdo3643_Date.h"
#include "jdo3643_Media.h"
#include "jdo3643_Bundle.h"

class Librarian
{
private:
	string name;
	int id;
public:
	Librarian();
	Librarian(string n, int i);
	void check_out_media(Media m);
	void check_out_bundle(Bundle b);
	void check_in_media(Media m);
	void check_in_bundle(Bundle b);
	string get_name();
};

#endif