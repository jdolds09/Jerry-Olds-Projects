#include "jdo3643_Date.h"
#include "jdo3643_Transaction.h"
#include <map>
#include <iterator>
#include <iomanip>
#include <string>
#include <fstream>

class Transaction_List
{
private:
	map <Date, Transaction>transactions;
public:
	Transaction_List() {};
	bool add_transaction(Date date, Transaction transaction);
	void list_transactions();
	double get_average_transaction();
	string bonus();
	string to_string() const;
	friend ostream& operator<<(ostream& ost, const Transaction_List& trans_list_two);
	void delete_transaction_by_date(Date d);
	void delete_transactions_by_name(string n);
	int get_size();
	void save();
	void load();
};
