#include <cctype>
#include <iomanip>
#include "jdo3643_Transaction_List.h"

int main()
{
// Go again variable
    char go_again = 'Y';
    int months = 0;
    vector<Transaction_List> list;
// Month Transaction Loop
    while(go_again == 'Y')
    {
    // Variables
        double transaction = 0.0;
        string month_name;
    // Prompt user for month
        cout << "\nPlease enter the name of the month: ";
        cin >> month_name;
    // Object
        Transaction_List Obj {month_name};
    
    // Get transactions
        while(transaction != -999)
        {
            cout << "Please enter transaction (Enter -999 to stop): ";
            cin >> transaction;
            if(transaction != -999)
            {
                Obj.add_transaction(transaction);
            }
        }
    // Add month to list of transactions
        list.push_back(Obj);
        months++;
    // Ask user if they would like to enter another month
        cout << "\nWould you like to enter another month (Y/N)? ";
        cin >> go_again;
        go_again = toupper(go_again);
        while(go_again != 'N' && go_again != 'Y')
        {
            cout << "Invalid input." << endl;
            cout << "\nWould you like to enter another month (Y/N)? ";
        cin >> go_again;
        go_again = toupper(go_again);
        }
    }

// Output Results
    for(int i = 0; i < months; i++)
    {
        cout << "\nMonth: " << list[i].get_month() << endl;
        cout << "Average Transaction: " << fixed << setprecision(2) << list[i].average_transaction() << endl << endl;
    }       

// End of program
    return 0;
}
