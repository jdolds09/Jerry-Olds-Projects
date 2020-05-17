#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Transaction
{
private:
	double price;
	string name;
public:
	double get_price();
	string get_name();
	Transaction(double p, string n);
	string to_string() const;
	friend ostream& operator<<(ostream& ost, const Transaction& trans_two);
};
