// This program will take 10 numbers inputted from the user
// and sort them in ascending order using the  
// selection sort technique
#include <iostream>
using namespace std;

// Constant
const int SIZE = 10;
// Function Prototype
void sort(int [], int);

int main()
{
// Array Declaration
	int array[SIZE];
// Variable
	int count;

// Beginning of program
	cout << "\t\t\t\tSorting Program\n";
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Please Enter Ten Numbers: " << endl;
// Entering Values in to array
	for (count = 0; count < SIZE; count++)
	{
		cout << "Number " << count + 1 << ": ";
		cin >> array[count];
	}
	cout << endl;
	cout << "Here is the numbers you entered in ascending order: " << endl;
// Function Call
	sort(array, SIZE);
// Display values
	for (int val : array)
		cout << val << " ";
	cout << endl;
return 0;
}

// Sort Function
void sort(int array[], int SIZE)
{
// Local Variables
	int counter, minIndex, minValue;
// Selection Sort
	for (counter = 0; counter < (SIZE - 1); counter++)
	{
		minIndex = counter;
		minValue = array[counter];
		for (int index = counter + 1; index < SIZE; index++)
		{
			if (array[index] < minValue)
			{
				minValue = array[index];
				minIndex = index;
			}
		}
		array[minIndex] = array[counter];
		array[counter] = minValue;
	}
}
