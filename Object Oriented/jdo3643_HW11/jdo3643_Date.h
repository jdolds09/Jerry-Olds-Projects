#ifndef JDO3643_DATE_H
#define JDO3643_DATE_H

#include <iostream>
using namespace std;

class Date
{
private:
	int year;
	int month;
	int day;
public:
	Date();
	Date(int y, int m, int d);
	int get_year();
	int get_month();
	int get_day();
};

#endif