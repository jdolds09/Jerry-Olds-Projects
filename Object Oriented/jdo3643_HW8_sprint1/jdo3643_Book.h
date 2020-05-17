#ifndef JDO3643_BOOK_H
#define JDO3643_BOOK_H

#include <iostream>
using namespace std;

class Book
{
private:
	string author;
	int copyright_year;
public:
	Book(string a, int cy);
};

#endif