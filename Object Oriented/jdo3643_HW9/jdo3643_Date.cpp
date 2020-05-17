#include "jdo3643_Date.h"

Date::Date()
{

}

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

int Date::get_year()
{
	return year;
}

int Date::get_month()
{
	return month;
}

int Date::get_day()
{
	return day;
}