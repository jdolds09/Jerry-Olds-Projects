// Author: Jerry Olds
// Course: COSC 1437
// Program 3.2 (***EXTRA CREDIT***)
#include<iostream>
using namespace std;

// Find Median Prototype
int findMedian(int array[], int size, double sum, int count);

int main()
{
// Variables
	int elements;
	int median1;
	int count = 0;
	double sum = 0.0;
	double median2;
// Arrays
	int array1[] = { 1, 2, 3, 4, 5, 6, 7 };
	int array2[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
// Title
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t   Recursive Median Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// Find Number of Elements in Array
	elements = sizeof(array1) / sizeof(array1[0]);
// Call Find Median Function
	median1 = findMedian(array1, elements, sum, count);
// Set Elements to 0
	elements = 0;
// Display Result
	cout << "Given the array: 1 2 3 4 5 6 7" << endl;
	cout << "The median is: " << median1 << endl;
// Find Number of Elements in Array
	elements = sizeof(array2) / sizeof(array2[0]);
// Call Find Median Function
	median2 = findMedian(array2, elements, sum, count);
// Display Result
	cout << "\nGiven the array: 1 2 3 4 5 6 7 8" << endl;
	cout << "The median is: " << median2 / 2 << endl << endl;
// End of Program 
	return 0;
}

int findMedian(int array[], int size, double sum, int count)
{
// Even Number of Elements
	if (size % 2 == 0)
	{
// Find Median
		if (count != 2)
		{
			size /= 2;
			sum += array[size];
			size *= 2;
			findMedian(array, size - 2, sum, ++count);
		}
		else
		{	
			return sum;
		}
	}
// Odd Number of Elements
	else
	{
		size /= 2;
		return array[size];
	}
}
