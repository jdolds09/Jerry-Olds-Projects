#ifndef JDO3643_LIBRARIAN_H
#define JDO3643_LIBRARIAN_H

#include "jdo3643_Date.h"

class Librarian
{
private:
	string name;
	int id;
public:
	void set_name(string n);
	void set_id(int id);
	void check_out();
	void check_in();
};

#endif