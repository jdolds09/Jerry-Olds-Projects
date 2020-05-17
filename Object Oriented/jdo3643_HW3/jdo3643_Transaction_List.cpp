#include "jdo3643_Transaction_List.h"

Transaction_List::Transaction_List(string m)
{
    month = m;
    num_transactions = 0;
}

string Transaction_List::get_month()
{return month;}

void Transaction_List::add_transaction(double transaction)
{
    transactions.push_back(transaction);
    num_transactions++;
}

double Transaction_List::average_transaction()
{
    double sum = 0;
    for(int i = 0; i < num_transactions; i++)
    {
        sum += transactions[i];
    }
    return (sum / num_transactions);
}
