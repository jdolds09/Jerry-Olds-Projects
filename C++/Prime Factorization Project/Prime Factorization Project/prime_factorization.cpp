#include<iostream>
#include<cmath>
using namespace std;

int main()
{
// Variables
	int num;
	int count;
	int remainder;
	int quotient;
	bool remainderFlag;
// Output Prompt
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\tPrime Factorization Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "This program will find the prime factors of integers.\nEnter 0 when you are finished." << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	do
	{
		cout << "Enter a number: ";
		cin >> num;
		while (num < 0)
		{
			cout << "Invalid Input." << endl << endl;
			cout << "Enter a number: ";
			cin >> num;
		}
		count = 2;
		remainderFlag = false;
		if (num != 0)
		{
			cout << "The prime factors are: ";
// Finding Prime Numbers
			while (count < (num / 2) + 1)
			{
				remainder = num % count;
				if (remainder == 0)
					remainderFlag = true;
				count++;
			}
			if (remainderFlag == false)
			{
				if (num == 1)
					cout << num;
				else
					cout << "1 " << num;
			}
// Even Numbers
			else if (num % 2 == 0)
			{
				quotient = num;
				while (quotient % 2 == 0 && quotient != 1)
				{
					cout << "2 ";
					quotient /= 2;
				}
				count = 3;
				while (quotient % 2 != 0 && quotient != 1)
				{
					if (quotient % count == 0 && quotient >= count)
					{
						cout << count << " ";
						quotient /= count;
						while (quotient % count == 0 && quotient >= count)
						{
							cout << count << " ";
							quotient /= count;
						}
					}
					count += 2;
				}
			}
// Odd Numbers
			else
			{
				quotient = num;
				count = 3;
				while (quotient != 1)
				{
					if (quotient % count == 0 && quotient >= count)
					{
						cout << count << " ";
						quotient /= count;
							while (quotient % count == 0 && quotient >= count)
							{
								cout << count << " ";
								quotient /= count;
							}
					}
					count += 2;
				}
			}
			cout << endl;
		}// End of If(num != 0) Statement
		cout << endl;
	}// End of Do While Loop
	while (num != 0);
	return 0;
}