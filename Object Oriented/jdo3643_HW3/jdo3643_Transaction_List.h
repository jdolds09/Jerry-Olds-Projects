#include <iostream>
#include <vector>
using namespace std;

class Transaction_List
{
private:
    string month;
    vector<double> transactions;
    int num_transactions;
public:
    Transaction_List(string m);
    string get_month();
    void add_transaction(double transaction);
    double average_transaction();
};

