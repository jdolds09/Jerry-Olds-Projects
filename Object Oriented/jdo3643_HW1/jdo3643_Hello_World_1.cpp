#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

int main()
{
// Variables
    string name;
    int num1;
    int num2;
    double num3;
    double num4;
// Prompt for user name
    cout << "\nHello User. Please enter your name: ";
// Input for user name
    getline(cin, name);
// Output name
    cout << "Thank you " << name << " for telling me your name." << endl;
// Prompt user for two ints
    cout << "\nPlease enter an integer number: ";
    cin >> num1;
    cout << "Please enter another integer number: ";
    cin >> num2;
// Output results
    cout << "\nSum:        " << right << (num1 + num2);
    cout << "\nDifference: " << right << (num1 - num2);
    cout << "\nProduct:    " << right << (num1 * num2);
    cout << "\nQuotient:   " << right << (num1 / num2) << endl;
// Prompt user for two doubles
    cout << "\nPlease enter a floating-point number: ";
    cin >> num3;
    cout << "Please enter another floating-point number: ";
    cin >> num4;
// Output results
    cout << "\nSum:        " << right << (num3 + num4);
    cout << "\nDifference: " << right << (num3 - num4);
    cout << "\nProduct:    " << right << (num3 * num4);
    cout << "\nQuotient:   " << right << (num3 / num4) << endl;
// Thank user for their time
    cout << "\nThank you "<< name << " for your time!" << endl << endl;
// End of program
    return 0;
}
