#include <iomanip>
#include "jdo3643_Transaction_List.h"

int main()
{
// Variables
    string month_name;
    double avg_transaction;
// Object 1
    Transaction_List May {"May"};
// Send values to add_transaction
    May.add_transaction(150);
    May.add_transaction(225.3);
    May.add_transaction(78.9);
    May.add_transaction(523.99);
// Output Month
    month_name = May.get_month();
    if(month_name == "May")
        cout << endl << "Month: " << month_name << endl;
    else
        cout << endl << "Error! Invalid month of transactions" << endl;
// Ouput Average Transaction
    avg_transaction = May.average_transaction();
    if(avg_transaction == 244.5475)
    cout << fixed << setprecision(2) << "Average Transaction: " << avg_transaction << endl;
    else
        cout << "Error! Invalid average transaction." << endl;

// Object 2
    Transaction_List March {"March"};
// Send values to add_transaction
    March.add_transaction(150);
    March.add_transaction(225.3);
    March.add_transaction(78.9);
    March.add_transaction(523.99);
// Output Month
    month_name = March.get_month();
    if(month_name == "May")
        cout << endl << "Month: " << month_name << endl;
    else
        cout << endl << "Error! Invalid month of transactions" << endl;
// Ouput Average Transaction
    avg_transaction = March.average_transaction();
    if(avg_transaction == 244.5475)
    cout << fixed << setprecision(2) << "Average Transaction: " << avg_transaction << endl;
    else
        cout << "Error! Invalid average transaction." << endl;

// Object 3
    Transaction_List May2 {"May"};
// Send values to add_transaction
    May2.add_transaction(150);
    May2.add_transaction(225.8);
    May2.add_transaction(78.9);
    May2.add_transaction(523.99);
// Output Month
     month_name = May2.get_month();
    if(month_name == "May")
        cout << endl << "Month: " << month_name << endl;
    else
        cout << endl << "Error! Invalid month of transactions" << endl;
// Ouput Average Transaction
    avg_transaction = May2.average_transaction();
    if(avg_transaction == 244.5475)
    cout << fixed << setprecision(2) << "Average Transaction: " << avg_transaction << endl;
    else
        cout << "Error! Invalid average transaction." << endl << endl;

// End of Program
    return 0;
}
