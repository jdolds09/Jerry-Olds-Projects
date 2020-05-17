// Author: Jerry Olds
// Set 3 Program 4
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

int blobCounter(vector <vector<int>> square, int squareSize);
bool nextValue(vector <vector<int>> square, int count, int counter, int squareSize);

int main()
{
// Variables
	int squareSize;
	int blobs;
// Input file
	ifstream inputFile;
// Title
	cout << "-----------------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\t       Island Program" << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl;
// Open Input File
	inputFile.open("blob.txt");
// Read in Square Size
	inputFile >> squareSize;
// Create 2D Vector
	vector <vector<int>> square(squareSize, vector<int>(squareSize));
// Read in values
	for (int count = 0; count < squareSize; count++)
	{
		for (int counter = 0; counter < squareSize; counter++)
			inputFile >> square[count][counter];
	}
// Display Values
	for (int count = 0; count < squareSize; count++)
	{
		for (int counter = 0; counter < squareSize; counter++)
		{
			cout << square[count][counter];
			if (counter == squareSize - 1)
				cout << endl;
		}
	}
	cout << endl;
// Close Input File
	inputFile.close();
// Calculate number of blobs
	blobs = blobCounter(square, squareSize);
	cout << "\nThere are " << blobs << " blobs on the grid." << endl;
}

int blobCounter(vector<vector<int>> square, int squareSize)
{
// Variables
	int blobs = 0;
	int count2;
	int counter2;
	int token;
	bool next;
	vector<vector<int>> square2(squareSize, vector<int>(squareSize));
// Assign values from square to square2
	for (int count = 0; count < squareSize; count++)
	{
		for (int counter = 0; counter < squareSize; counter++)
		{
			square2[count][counter] = square[count][counter];
		}
	}
// Find 1's
	for (int count = 0; count < squareSize; count++)
	{
		for (int counter = 0; counter < squareSize; counter++)
		{
			if (square2[count][counter] == 1)
			{
				square2[count][counter] = 2;
				blobs++; // NOTE TO FUTURE SELF: This needs to be the last command in this if statement
			}
		}
	}
	for (int count = 0; count < squareSize; count++)
	{
		for (int counter = 0; counter < squareSize; counter++)
		{
			cout << square2[count][counter];
			if (counter == squareSize - 1)
				cout << endl;
		}
	}
	return blobs;
}

bool nextValue(vector<vector<int>> square, int count, int counter, int squareSize)
{
	if (count + 1 < squareSize && counter - 1 >= 0 && square[count + 1][counter - 1] == 1)
		return true;
	else if (count + 1 < squareSize && square[count + 1][counter] == 1)
		return true;
	else if (count + 1 < squareSize && counter + 1 < squareSize && square[count + 1][counter + 1] == 1)
		return true;
	else if (counter + 1 < squareSize && square[count][counter + 1] == 1)
		return true;
	else if (count - 1 >= 0 && counter + 1 < squareSize && square[count - 1][counter + 1] == 1)
		return true;
	else if (count - 1 >= 0 && square[count - 1][counter] == 1)
		return true;
	else if (count - 1 >= 0 && counter - 1 >= 0 && square[count - 1][counter - 1] == 1)
		return true;
	else if (counter - 1 >= 0 && square[count][counter - 1] == 1)
		return true;
	else
		return false;
}