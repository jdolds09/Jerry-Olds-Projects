#include "jdo3643_Date.h"

Date::Date(int y, int m, int d, int h, int min, int s)
{
	year = y;
	month = m;
	day = d;
	hour = h;
	minute = min;
	second = s;
}

string Date::to_string() const
{
// Put zeros in front of time values that are less than 10
	if (hour < 10 && minute < 10 && second < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  0" + std::to_string(hour) + ":0" + std::to_string(minute) + ":0" + std::to_string(second);
	else if (hour < 10 && minute < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  0" + std::to_string(hour) + ":0" + std::to_string(minute) + ":" + std::to_string(second);
	else if (hour < 10 && second < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  0" + std::to_string(hour) + ":" + std::to_string(minute) + ":0" + std::to_string(second);
	else if (minute < 10 && second < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  " + std::to_string(hour) + ":0" + std::to_string(minute) + ":0" + std::to_string(second);
	else if (hour < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  0" + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
	else if (minute < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  " + std::to_string(hour) + ":0" + std::to_string(minute) + ":" + std::to_string(second);
	else if (second < 10)
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  " + std::to_string(hour) + ":" + std::to_string(minute) + ":0" + std::to_string(second);
	else
		return "\nDate:  (" + std::to_string(month) + "/" + std::to_string(day) + "/" + std::to_string(year) + ")" + "\nTime:  " + std::to_string(hour) + ":" + std::to_string(minute) + ":" + std::to_string(second);
}

bool Date::operator<(const Date& date_two) const
{
	if (this->year < date_two.year)
		return true;
	if (this->year > date_two.year)
		return false;
	if (this->month < date_two.month)
		return true;
	if (this->month > date_two.month)
		return false;
	if (this->day < date_two.day)
		return true;
	if (this->day > date_two.day)
		return false;
	if (this->hour < date_two.hour)
		return true;
	if (this->hour > date_two.hour)
		return false;
	if (this->minute < date_two.minute)
		return true;
	if (this->minute > date_two.minute)
		return false;
	if (this->second < date_two.second)
		return true;
	return false;
}


ostream& operator<<(ostream& ost, const Date& date_two)
{
	ost << date_two.to_string();
	return ost;
}
