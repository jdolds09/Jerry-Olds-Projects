// Author: Jerry Olds
// Course: COSC 1437
// Program 4 (***EXTRA CREDIT***)
// Reference: http://www.codeproject.com/Articles/4952/Magic-Square
#include<iostream>
#include<vector>
using namespace std;

// Function Prototypes
void oddSquare(vector <vector<int> > &square, int n);
void singlyEvenSquare(vector <vector<int> > &square, int n);
void doublyEvenSquare(vector <vector<int> > &square, int n);
void magicSquare(vector <vector<int> > &square, int n);
int magicNumber(int n);

int main()
{
// Variables
	int n;
	int count;
	char again;
	int number;
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t     Magic Square Program" << endl;
	cout << "-------------------------------------------------------------------------------";
	START: cout << "\nPlease enter order (size) of the Magic Square (3-20): ";
	cin >> n;
// Input Validation
	while (n < 3 || n > 20)
	{
		cout << "Invalid input." << endl;
		cout << "Please enter order (size) of the Magic Square (3-20): ";
		cin >> n;
	}
// 2D Vector
	vector < vector<int> > square(n, vector<int>(n, 0));
	cout << "The magic square order of " << n << " is: " << endl << endl;
// Call Square Function
	magicSquare(square, n);
// Print Results
	for (int i = 0; i < n; i++)
	{
			cout << "| ";
		for (int j = 0; j < n; j++)
		{
			if (square[i][j] < 10)
				cout << "0" << square[i][j] << " | ";
			else if (square[i][j] >= 100)
				cout << square[i][j] << "| ";
			else
				cout << square[i][j] << " | ";
			if (j == n - 1)
			cout << endl;
		}
	}
	cout << endl;
// Call Magic Number Function
	number = magicNumber(n);
	cout << "Magic Number: " << number << endl;
// Prompt User to Continue
	cout << "\nEnter another Magic Square?(Y/N): ";
	cin >> again;
	if (again == 'y' || again == 'Y')
		goto START;
	else
		return 0;
}

// Determine Square Function
void magicSquare(vector <vector<int> > &square, int n)
{
// Call Odd Function
	if (n % 2 == 1)
	{
		oddSquare(square, n);
	}
// Call Doubly Even Function
	else if (n % 4 == 0)
	{
		doublyEvenSquare(square, n);
	}
// Call Singly Even Function
	else
	{
		singlyEvenSquare(square, n);
	}
}

// Odd Square Function
void oddSquare(vector <vector<int> > &square, int n)
{
// Placeholders
	int i = 0;
	int j = n / 2;
// Loop
	for (int count = 1; count <= n * n; count++)
	{
		square[i][j] = count;
		
		i--;
		j++;

		if (count % n == 0)
		{
			i += 2;
			--j;
		}
		else
		{
			if (j == n)
				j -= n;
			else if (i<0)
				i += n;
		}
	}
}

// Singly Even Square Function
void singlyEvenSquare(vector <vector<int> > &square, int n)
{
	int p = n / 2;

	vector<vector<int> > secondSquare(p, vector<int>(p, 0));
	magicSquare(secondSquare, p);

	int i, j, k;

	for (i = 0; i<p; i++)
		for (j = 0; j<p; j++)
		{
			square[i][j] = secondSquare[i][j];
			square[i + p][j] = secondSquare[i][j] + 3 * p*p;
			square[i][j + p] = secondSquare[i][j] + 2 * p*p;
			square[i + p][j + p] = secondSquare[i][j] + p*p;
		}

	if (n == 2)
		return;

	vector<int> I(p, 0);
	vector<int> J;

	for (i = 0; i<p; i++)
		I[i] = i + 1;

	k = (n - 2) / 4;

	for (i = 1; i <= k; i++)
		J.push_back(i);

	for (i = n - k + 2; i <= n; i++)
		J.push_back(i);

	int temp;
	for (i = 1; i <= p; i++)
		for (j = 1; j <= J.size(); j++)
		{
			temp = square[i - 1][J[j - 1] - 1];
			square[i - 1][J[j - 1] - 1] = square[i + p - 1][J[j - 1] - 1];
			square[i + p - 1][J[j - 1] - 1] = temp;
		}

	i = k;
	j = 0;
	temp = square[i][j]; square[i][j] = square[i + p][j]; square[i + p][j] = temp;

	j = i;
	temp = square[i + p][j]; square[i + p][j] = square[i][j]; square[i][j] = temp;
}

// Doubly Even Square Function
void doublyEvenSquare(vector <vector<int> > &square, int n)
{
	vector<vector<int> > I(n, vector<int>(n, 0));
	vector<vector<int> > J(n, vector<int>(n, 0));

	int i, j;

	int index = 1;
	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
		{
			I[i][j] = ((i + 1) % 4) / 2;
			J[j][i] = ((i + 1) % 4) / 2;
			square[i][j] = index;
			index++;
		}

	for (i = 0; i<n; i++)
		for (j = 0; j<n; j++)
		{
			if (I[i][j] == J[i][j])
				square[i][j] = n*n + 1 - square[i][j];
		}
}

// Magic Number Function
int magicNumber(int n)
{
// Variable
	int x;
// Formula
	return x = (n *(pow(n, 2) + 1)) / 2;
}