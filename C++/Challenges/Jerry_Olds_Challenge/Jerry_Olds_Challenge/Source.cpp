// This program will determine the change given back to 
// the customer and what coins were given to the customer
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int price, change, halfDollars, quarters, dimes, nickels, pennies;
	
// Beginning of program
	cout << "Please enter item price: ";
	cin >> price;
	
if (0 > price || 100 < price)
	{
		cout << "Sorry you have entered an invalid price.\n";
		cout << "Please run the program again and enter a integer between 0 and 100.\n";
	}
else
	{
		change = (100 - price);
			cout << "Change Rendered: " << change << endl;
		halfDollars = change / 50;
			cout << "Number of Half Dollars: " << halfDollars << endl;
		quarters = (change - (halfDollars * 50)) / 25;
			cout << "Number of Quarters: " << quarters << endl;
		dimes = (change - ((halfDollars * 50) + (quarters * 25))) / 10;
			cout << "Number of Dimes: " << dimes << endl;
		nickels = (change - ((halfDollars * 50) + (quarters * 25) + (dimes * 10))) / 5;
			cout << "Number of Nickels: " << nickels << endl;
		pennies = (change - ((halfDollars * 50) + (quarters * 25) + (dimes * 10) + (nickels * 5))) / 1;
			cout << "Number of Pennies: " << pennies << endl;
	}
return 0;
}
