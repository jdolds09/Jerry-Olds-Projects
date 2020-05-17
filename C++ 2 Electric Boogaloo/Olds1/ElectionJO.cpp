// Author: Jerry Olds
// Course: COSC 1437
// Program 2 (***EXTRA CREDIT***)
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Election Structure
struct Election
{
	int states;
	string stateName;
	int republican;
	int democrat;
	int independent;
	int electoral;
};

// Election One Prototypes
char election_one(Election[][3]);
int republican_electoral1(Election[][3]);
int democrat_electoral1(Election[][3]);
int independent_electoral1(Election[][3]);
double republican_popular1(Election[][3]);
double democrat_popular1(Election[][3]);
double independent_popular1(Election[][3]);
// Election Two Prototypes
char election_two(Election[][3]);
int republican_electoral2(Election[][3]);
int democrat_electoral2(Election[][3]);
int independent_electoral2(Election[][3]);
double republican_popular2(Election[][3]);
double democrat_popular2(Election[][3]);
double independent_popular2(Election[][3]);
// Election Three Prototypes
char election_three(Election[][3]);
int republican_electoral3(Election[][3]);
int democrat_electoral3(Election[][3]);
int independent_electoral3(Election[][3]);
double republican_popular3(Election[][3]);
double democrat_popular3(Election[][3]);
double independent_popular3(Election[][3]);
// Election Four Prototypes
char election_four(Election[][3]);
int republican_electoral4(Election[][3]);
int democrat_electoral4(Election[][3]);
int independent_electoral4(Election[][3]);
double republican_popular4(Election[][3]);
double democrat_popular4(Election[][3]);
double independent_popular4(Election[][3]);

int main()
{
// Variables
	int elections;
	string fileName;
	int count = 0;
	int counter = 0;
// Election One Variables
	char winner_one;
	int r_electoral1;
	int d_electoral1;
	int i_electoral1;
	double r_popular1;
	double d_popular1;
	double i_popular1;
// Election Two Variables
	char winner_two;
	int r_electoral2;
	int d_electoral2;
	int i_electoral2;
	double r_popular2;
	double d_popular2;
	double i_popular2;
// Election Three Variables
	char winner_three;
	int r_electoral3;
	int d_electoral3;
	int i_electoral3;
	double r_popular3;
	double d_popular3;
	double i_popular3;
// Election Four Variables
	char winner_four;
	int r_electoral4;
	int d_electoral4;
	int i_electoral4;
	double r_popular4;
	double d_popular4;
	double i_popular4;

// Input File
	ifstream inputFile;
// Structure Array
	Election array[4][3];
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t\tElection Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Enter the File name: ";
	cin >> fileName;
// Open File
	inputFile.open("election.txt");
// Read in Election Information
	inputFile >> elections;
	while (count < elections)
	{
		inputFile >> array[count][counter].states;
		while (counter < array[count][0].states)
		{
			inputFile >> array[count][counter].stateName;
			inputFile >> array[count][counter].republican;
			inputFile >> array[count][counter].democrat;
			inputFile >> array[count][counter].independent;
			inputFile >> array[count][counter].electoral;
			counter++;
		}
		counter = 0;
		count++;
	}
// Close File
	inputFile.close();
// Call Election Functions
	winner_one = election_one(array);
	winner_two = election_two(array);
	winner_three = election_three(array);
	winner_four = election_four(array);
// Call Electoral Vote Functions
	r_electoral1 = republican_electoral1(array);
	d_electoral1 = democrat_electoral1(array);
	i_electoral1 = independent_electoral1(array);
	r_electoral2 = republican_electoral2(array);
	d_electoral2 = democrat_electoral2(array);
	i_electoral2 = independent_electoral2(array);
	r_electoral3 = republican_electoral3(array);
	d_electoral3 = democrat_electoral3(array);
	i_electoral3 = independent_electoral3(array);
	r_electoral4 = republican_electoral4(array);
	d_electoral4 = democrat_electoral4(array);
	i_electoral4 = independent_electoral4(array);
// Call Popular Vote Functions
	r_popular1 = republican_popular1(array);
	d_popular1 = democrat_popular1(array);
	i_popular1 = independent_popular1(array);
	r_popular2 = republican_popular2(array);
	d_popular2 = democrat_popular2(array);
	i_popular2 = independent_popular2(array);
	r_popular3 = republican_popular3(array);
	d_popular3 = democrat_popular3(array);
	i_popular3 = independent_popular3(array);
	r_popular4 = republican_popular4(array);
	d_popular4 = democrat_popular4(array);
	i_popular4 = independent_popular4(array);
// Display Election One Results
	cout << fixed << showpoint << setprecision(2);
	if (winner_one == 'r')
	{
		cout << "\nRepublicans win with " << r_electoral1 << " electoral votes and " << r_popular1 << "% of the popular vote." << endl;
	}
	else if (winner_one == 'd')
	{
		cout << "\nDemocrats win with " << d_electoral1 << " electoral votes and " << d_popular1 << "% of the popular vote. " << endl;
	}
	else if (winner_one == 'i')
	{
		cout << "\nIndependents win with " << i_electoral1 << " electoral votes and " << i_popular1 << "% of the popular vote. " << endl;
	}
	else if (winner_one == 't' && r_popular1 > d_popular1 && r_popular1 > i_popular1)
	{
		cout << "\nRepublicans win with " << r_electoral1 << " electoral votes and " << r_popular1 << "% of the popular vote." << endl;
	}
	else if (winner_one == 't' && d_popular1 > r_popular1 && d_popular1 > i_popular1)
	{
		cout << "\nDemocrats win with " << d_electoral1 << " electoral votes and " << d_popular1 << "% of the popular vote. " << endl;
	}
	else if (winner_one == 't' && i_popular1 > r_popular1 && i_popular1 > d_popular1)
	{
		cout << "\nIndependents win with " << i_electoral1 << " electoral votes and " << i_popular1 << "% of the popular vote. " << endl;
	}
	else
	{
		cout << "\nTie Election!";
	}
// Display Election Two Results
	if (winner_two == 'r')
	{
		cout << "Republicans win with " << r_electoral2 << " electoral votes and " << r_popular2 << "% of the popular vote." << endl;
	}
	else if (winner_two == 'd')
	{
		cout << "Democrats win with " << d_electoral2 << " electoral votes and " << d_popular2 << "% of the popular vote. " << endl;
	}
	else if (winner_two == 'i')
	{
		cout << "Independents win with " << i_electoral2 << " electoral votes and " << i_popular2 << "% of the popular vote. " << endl;
	}
	else if (winner_two == 't' && r_popular2 > d_popular2 && r_popular2 > i_popular2)
	{
		cout << "Republicans win with " << r_electoral2 << " electoral votes and " << r_popular2 << "% of the popular vote." << endl;
	}
	else if (winner_two == 't' && d_popular2 > r_popular2 && d_popular2 > i_popular2)
	{
		cout << "Democrats win with " << d_electoral2 << " electoral votes and " << d_popular2 << "% of the popular vote. " << endl;
	}
	else if (winner_two == 't' && i_popular2 > r_popular2 && i_popular2 > d_popular2)
	{
		cout << "Independents win with " << i_electoral2 << " electoral votes and " << i_popular2 << "% of the popular vote. " << endl;
	}
	else
	{
		cout << "Tie Election!" << endl;
	}
// Display Election Three Results
	if (winner_three == 'r')
	{
		cout << "Republicans win with " << r_electoral3 << " electoral votes and " << r_popular3 << "% of the popular vote." << endl;
	}
	else if (winner_three == 'd')
	{
		cout << "Democrats win with " << d_electoral3 << " electoral votes and " << d_popular3 << "% of the popular vote. " << endl;
	}
	else if (winner_three == 'i')
	{
		cout << "\n\nIndependents win with " << i_electoral3 << " electoral votes and " << i_popular3 << "% of the popular vote. " << endl;
	}
	else if (winner_three == 't' && r_popular3 > d_popular3 && r_popular3 > i_popular3)
	{
		cout << "Republicans win with " << r_electoral3 << " electoral votes and " << r_popular3 << "% of the popular vote." << endl;
	}
	else if (winner_three == 't' && d_popular3 > r_popular3 && d_popular3 > i_popular3)
	{
		cout << "Democrats win with " << d_electoral3 << " electoral votes and " << d_popular3 << "% of the popular vote. " << endl;
	}
	else if (winner_three == 't' && i_popular3 > r_popular3 && i_popular3 > d_popular3)
	{
		cout << "Independents win with " << i_electoral3 << " electoral votes and " << i_popular3 << "% of the popular vote. " << endl;
	}
	else
	{
		cout << "Tie Election!" << endl;
	}
// Display Election Four Results
	if (winner_four == 'r')
	{
		cout << "Republicans win with " << r_electoral4 << " electoral votes and " << r_popular4 << "% of the popular vote." << endl;
	}
	else if (winner_four == 'd')
	{
		cout << "Democrats win with " << d_electoral4 << " electoral votes and " << d_popular4 << "% of the popular vote. " << endl;
	}
	else if (winner_four == 'i')
	{
		cout << "Independents win with " << i_electoral4 << " electoral votes and " << i_popular4 << "% of the popular vote. " << endl;
	}
	else if (winner_four == 't' && r_popular4 > d_popular4 && r_popular4 > i_popular4)
	{
		cout << "Republicans win with " << r_electoral4 << " electoral votes and " << r_popular4 << "% of the popular vote." << endl;
	}
	else if (winner_four == 't' && d_popular4 > r_popular4 && d_popular4 > i_popular4)
	{
		cout << "Democrats win with " << d_electoral4 << " electoral votes and " << d_popular4 << "% of the popular vote. " << endl;
	}
	else if (winner_four == 't' && i_popular4 > r_popular4 && i_popular4 > d_popular4)
	{
		cout << "Independents win with " << i_electoral4 << " electoral votes and " << i_popular4 << "% of the popular vote. " << endl;
	}
	else
	{
		cout << "Tie Election!" << endl;
	}
	cout << endl;
	return 0;
}

// Election One Function
char election_one(Election array[][3])
{
// Local Variables
	int r1 = array[0][0].republican;
	int d1 = array[0][0].democrat;
	int i1 = array[0][0].independent;
	int r2 = array[0][1].republican;
	int d2 = array[0][1].democrat;
	int i2 = array[0][1].independent;
	int r3 = array[0][2].republican;
	int d3 = array[0][2].democrat;
	int i3 = array[0][2].independent;
	int electoral_one = array[0][0].electoral;
	int electoral_two = array[0][1].electoral;
	int electoral_three = array[0][2].electoral;
	int republican_electoral = 0;
	int democrat_electoral = 0;
	int independent_electoral = 0;
	char winner;
// Texas
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
	else if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
	else if (i1 > r1 && i1 > d1)
	{
		independent_electoral += electoral_one;
	}
// California
	if (r2 > d2 && r2 > i2)
	{
		republican_electoral += electoral_two;
	}
	else if (d2 > r2 && d2 > i2)
	{
		democrat_electoral += electoral_two;
	}
	else if (i2 > r2 && i2 > d2)
	{
		independent_electoral += electoral_two;
	}
// Nevada
	if (r3 > d3 && r3 > i3)
	{
		republican_electoral += electoral_three;
	}
	else if (d3 > r3 && d3 > i3)
	{
		democrat_electoral += electoral_three;
	}
	else if (i3 > r3 && i3 > d3)
	{
		independent_electoral += electoral_three;
	}
// Determine Winner
	if (republican_electoral > democrat_electoral && republican_electoral > independent_electoral)
	{
		return winner = 'r';
	}
	else if (democrat_electoral > republican_electoral && democrat_electoral > independent_electoral)
	{
		return winner = 'd';
	}
	else if (independent_electoral > republican_electoral && independent_electoral > democrat_electoral)
	{
		return winner = 'i';
	}
	else
		return winner = 't';
}

// Republican Electoral1 Function
int republican_electoral1(Election array[][3])
{
// Local Variables
	int r1 = array[0][0].republican;
	int d1 = array[0][0].democrat;
	int i1 = array[0][0].independent;
	int r2 = array[0][1].republican;
	int d2 = array[0][1].democrat;
	int i2 = array[0][1].independent;
	int r3 = array[0][2].republican;
	int d3 = array[0][2].democrat;
	int i3 = array[0][2].independent;
	int electoral_one = array[0][0].electoral;
	int electoral_two = array[0][1].electoral;
	int electoral_three = array[0][2].electoral;
	int republican_electoral = 0;
// Texas
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
// California
	if (r2 > d2 && r2 > i2)
	{
		republican_electoral += electoral_two;
	}
// Nevada
	if (r3 > d3 && r3 > i3)
	{
		republican_electoral += electoral_three;
	}
// Return Republican Electoral
	return republican_electoral;
}

// Democrat Electoral1 Function
int democrat_electoral1(Election array[][3])
{
// Local Variables
	int r1 = array[0][0].republican;
	int d1 = array[0][0].democrat;
	int i1 = array[0][0].independent;
	int r2 = array[0][1].republican;
	int d2 = array[0][1].democrat;
	int i2 = array[0][1].independent;
	int r3 = array[0][2].republican;
	int d3 = array[0][2].democrat;
	int i3 = array[0][2].independent;
	int electoral_one = array[0][0].electoral;
	int electoral_two = array[0][1].electoral;
	int electoral_three = array[0][2].electoral;
	int democrat_electoral = 0;
// Texas
	if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
// California
	if (d2 > r2 && d2 > i2)
	{
		democrat_electoral += electoral_two;
	}
// Nevada
	if (d3 > r3 && d3 > i3)
	{
		democrat_electoral += electoral_three;
	}
// Return Democrat Electoral
	return democrat_electoral;
}

// Independent Electoral1 Function
int independent_electoral1(Election array[][3])
{
// Local Variables
	int r1 = array[0][0].republican;
	int d1 = array[0][0].democrat;
	int i1 = array[0][0].independent;
	int r2 = array[0][1].republican;
	int d2 = array[0][1].democrat;
	int i2 = array[0][1].independent;
	int r3 = array[0][2].republican;
	int d3 = array[0][2].democrat;
	int i3 = array[0][2].independent;
	int electoral_one = array[0][0].electoral;
	int electoral_two = array[0][1].electoral;
	int electoral_three = array[0][2].electoral;
	int independent_electoral = 0;
// Texas
	if (i1 > d1 && i1 > r1)
	{
		independent_electoral += electoral_one;
	}
// California
	if (i2 > d2 && i2 > r2)
	{
		independent_electoral += electoral_two;
	}
// Nevada
	if (i3 > d3 && i3 > r3)
	{
		independent_electoral += electoral_three;
	}
// Return Republican Electoral
	return independent_electoral;
}

// Republican Popular1 Function
double republican_popular1(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double republican_total = 0.0;
	int counter;
	double republican_popular;
// Total Votes
	for (counter = 0; counter < 3; counter++)
	{
		total += array[0][counter].republican + array[0][counter].democrat + array[0][counter].independent;
	}
// Republican Total
	for (counter = 0; counter < 3; counter++)
	{
		republican_total += array[0][counter].republican;
	}
// Return Republican Popular
	return republican_popular = (republican_total / total) * 100.0;
}

// Democrat Popular1 Function
double democrat_popular1(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double democrat_total = 0.0;
	int counter;
	double democrat_popular;
// Total Votes
	for (counter = 0; counter < 3; counter++)
	{
		total += (array[0][counter].republican + array[0][counter].democrat + array[0][counter].independent);
	}
// Democrat Total
	for (counter = 0; counter < 3; counter++)
	{
		democrat_total += (array[0][counter].democrat);
	}
// Return Democrat Popular
	 return democrat_popular = (democrat_total / total) * 100.0;
}

// Independent Popular1 Function
double independent_popular1(Election array[][3])
{
	// Local Variables
	double total = 0.0;
	double independent_total = 0.0;
	int counter;
	double independent_popular;
	// Total Votes
	for (counter = 0; counter < 3; counter++)
	{
		total += array[0][counter].republican + array[0][counter].democrat + array[0][counter].independent;
	}
	// Independent Total
	for (counter = 0; counter < 3; counter++)
	{
		independent_total += array[0][counter].independent;
	}
	// Return Independent Popular
	return independent_popular = (independent_total / total) * 100.0;
}

// Election Two Function
char election_two(Election array[][3])
{
// Local Variables
	int r1 = array[1][0].republican;
	int d1 = array[1][0].democrat;
	int i1 = array[1][0].independent;
	int r2 = array[1][1].republican;
	int d2 = array[1][1].democrat;
	int i2 = array[1][1].independent;
	int electoral_one = array[1][0].electoral;
	int electoral_two = array[1][1].electoral;
	int republican_electoral = 0;
	int democrat_electoral = 0;
	int independent_electoral = 0;
	char winner;
// Utah
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
	else if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
	else if (i1 > r1 && i1 > d1)
	{
		independent_electoral += electoral_one;
	}
// Nevada
	if (r2 > d2 && r2 > i2)
	{
		republican_electoral += electoral_two;
	}
	else if (d2 > r2 && d2 > i2)
	{
		democrat_electoral += electoral_two;
	}
	else if (i2 > r2 && i2 > d2)
	{
		independent_electoral += electoral_two;
	}
// Determine Winner
	if (republican_electoral > democrat_electoral && republican_electoral > independent_electoral)
	{
		return winner = 'r';
	}
	else if (democrat_electoral > republican_electoral && democrat_electoral > independent_electoral)
	{
		return winner = 'd';
	}
	else if (independent_electoral > republican_electoral && independent_electoral > democrat_electoral)
	{
		return winner = 'i';
	}
	else
		return winner = 't';
}

// Republican Electoral2 Function
int republican_electoral2(Election array[][3])
{
// Local Variables
	int r1 = array[1][0].republican;
	int d1 = array[1][0].democrat;
	int i1 = array[1][0].independent;
	int r2 = array[1][1].republican;
	int d2 = array[1][1].democrat;
	int i2 = array[1][1].independent;
	int electoral_one = array[1][0].electoral;
	int electoral_two = array[1][1].electoral;
	int republican_electoral = 0;
// Utah
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
// Nevada
	if (r2 > d2 && r2 > i2)
	{
		republican_electoral += electoral_two;
	}
// Return Republican Electoral
	return republican_electoral;
}

// Democrat Electoral2 Function
int democrat_electoral2(Election array[][3])
{
// Local Variables
	int r1 = array[1][0].republican;
	int d1 = array[1][0].democrat;
	int i1 = array[1][0].independent;
	int r2 = array[1][1].republican;
	int d2 = array[1][1].democrat;
	int i2 = array[1][1].independent;
	int electoral_one = array[1][0].electoral;
	int electoral_two = array[1][1].electoral;
	int democrat_electoral = 0;
// Utah
	if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
// Nevada
	if (d2 > r2 && d2 > i2)
	{
		democrat_electoral += electoral_two;
	}
// Return Republican Electoral
	return democrat_electoral;
}

// Independent Electoral2 Function
int independent_electoral2(Election array[][3])
{
// Local Variables
	int r1 = array[1][0].republican;
	int d1 = array[1][0].democrat;
	int i1 = array[1][0].independent;
	int r2 = array[1][1].republican;
	int d2 = array[1][1].democrat;
	int i2 = array[1][1].independent;
	int electoral_one = array[1][0].electoral;
	int electoral_two = array[1][1].electoral;
	int independent_electoral = 0;
// Utah
	if (i1 > d1 && i1 > r1)
	{
		independent_electoral += electoral_one;
	}
// Nevada
	if (i2 > d2 && i2 > r2)
	{
		independent_electoral += electoral_two;
	}
// Return Republican Electoral
	return independent_electoral;
}

// Republican Popular2 Function
double republican_popular2(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double republican_total = 0.0;
	int counter;
	double republican_popular;
// Total Votes
	for (counter = 0; counter < 2; counter++)
	{
		total += array[1][counter].republican + array[1][counter].democrat + array[1][counter].independent;
	}
// Republican Total
	for (counter = 0; counter < 2; counter++)
	{
		republican_total += array[1][counter].republican;
	}
// Return Republican Popular
	return republican_popular = (republican_total / total) * 100.0;
}

// Democrat Popular2 Function
double democrat_popular2(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double democrat_total = 0.0;
	int counter;
	double democrat_popular;
// Total Votes
	for (counter = 0; counter < 2; counter++)
	{
		total += array[1][counter].republican + array[1][counter].democrat + array[1][counter].independent;
	}
// Republican Total
	for (counter = 0; counter < 2; counter++)
	{
		democrat_total += array[1][counter].democrat;
	}
// Return Republican Popular
	return democrat_popular = (democrat_total / total) * 100.0;
}

// Independent Popular2 Function
double independent_popular2(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double independent_total = 0.0;
	int counter;
	double independent_popular;
// Total Votes
	for (counter = 0; counter < 2; counter++)
	{
		total += array[1][counter].republican + array[1][counter].democrat + array[1][counter].independent;
	}
// Republican Total
	for (counter = 0; counter < 2; counter++)
	{
		independent_total += array[1][counter].independent;
	}
// Return Republican Popular
	return independent_popular = (independent_total / total) * 100.0;
}

// Election Three Function
char election_three(Election array[][3])
{
// Local Variables
	int r1 = array[2][0].republican;
	int d1 = array[2][0].democrat;
	int i1 = array[2][0].independent;
	int r2 = array[2][1].republican;
	int d2 = array[2][1].democrat;
	int i2 = array[2][1].independent;
	int electoral_one = array[2][0].electoral;
	int electoral_two = array[2][1].electoral;
	int republican_electoral = 0;
	int democrat_electoral = 0;
	int independent_electoral = 0;
	char winner;
// Utah
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
	else if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
	else if (i1 > r1 && i1 > d1)
	{
		independent_electoral += electoral_one;
	}
// Nevada
	if (r2 > d2 && r2 > i2)
	{
		republican_electoral += electoral_two;
	}
	else if (d2 > r2 && d2 > i2)
	{
		democrat_electoral += electoral_two;
	}
	else if (i2 > r2 && i2 > d2)
	{
		independent_electoral += electoral_two;
	}
// Determine Winner
	if (republican_electoral > democrat_electoral && republican_electoral > independent_electoral)
	{
		return winner = 'r';
	}
	else if (democrat_electoral > republican_electoral && democrat_electoral > independent_electoral)
	{
		return winner = 'd';
	}
	else if (independent_electoral > republican_electoral && independent_electoral > democrat_electoral)
	{
		return winner = 'i';
	}
	else
		return winner = 't';
}

// Republican Electoral3 Function
int republican_electoral3(Election array[][3])
{
// Local Variables
	int r1 = array[2][0].republican;
	int d1 = array[2][0].democrat;
	int i1 = array[2][0].independent;
	int r2 = array[2][1].republican;
	int d2 = array[2][1].democrat;
	int i2 = array[2][1].independent;
	int electoral_one = array[2][0].electoral;
	int electoral_two = array[2][1].electoral;
	int republican_electoral = 0;
// Utah
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
// Nevada
	if (r2 > d2 && r2 > i2)
	{
		republican_electoral += electoral_two;
	}
// Return Republican Electoral
	return republican_electoral;
}

// Democrat Electoral3 Function
int democrat_electoral3(Election array[][3])
{
// Local Variables
	int r1 = array[2][0].republican;
	int d1 = array[2][0].democrat;
	int i1 = array[2][0].independent;
	int r2 = array[2][1].republican;
	int d2 = array[2][1].democrat;
	int i2 = array[2][1].independent;
	int electoral_one = array[2][0].electoral;
	int electoral_two = array[2][1].electoral;
	int democrat_electoral = 0;
// Utah
	if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
// Nevada
	if (d2 > r2 && d2 > i2)
	{
		democrat_electoral += electoral_two;
	}
// Return Democrat Electoral
	return democrat_electoral;
}

// Independent Electoral3 Function
int independent_electoral3(Election array[][3])
{
// Local Variables
	int r1 = array[2][0].republican;
	int d1 = array[2][0].democrat;
	int i1 = array[2][0].independent;
	int r2 = array[2][1].republican;
	int d2 = array[2][1].democrat;
	int i2 = array[2][1].independent;
	int electoral_one = array[2][0].electoral;
	int electoral_two = array[2][1].electoral;
	int independent_electoral = 0;
// Utah
	if (i1 > d1 && i1 > r1)
	{
		independent_electoral += electoral_one;
	}
// Nevada
	if (i2 > d2 && i2 > r2)
	{
		independent_electoral += electoral_two;
	}
// Return Independent Electoral
	return independent_electoral;
}

// Republican Popular3 Function
double republican_popular3(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double republican_total = 0.0;
	int counter;
	double republican_popular;
// Total Votes
	for (counter = 0; counter < 2; counter++)
	{
		total += array[2][counter].republican + array[2][counter].democrat + array[2][counter].independent;
	}
// Republican Total
	for (counter = 0; counter < 2; counter++)
	{
		republican_total += array[2][counter].republican;
	}
// Return Republican Popular
	return republican_popular = (republican_total / total) * 100.0;
}

// Democrat Popular3 Function
double democrat_popular3(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double democrat_total = 0.0;
	int counter;
	double democrat_popular;
// Total Votes
	for (counter = 0; counter < 2; counter++)
	{
		total += array[2][counter].republican + array[2][counter].democrat + array[2][counter].independent;
	}
// Democrat Total
	for (counter = 0; counter < 2; counter++)
	{
		democrat_total += array[2][counter].democrat;
	}
// Return Democrat Popular
	return democrat_popular = (democrat_total / total) * 100.0;
}

// Independent Popular3 Function
double independent_popular3(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double independent_total = 0.0;
	int counter;
	double independent_popular;
// Total Votes
	for (counter = 0; counter < 2; counter++)
	{
		total += array[2][counter].republican + array[2][counter].democrat + array[2][counter].independent;
	}
// Independent Total
	for (counter = 0; counter < 2; counter++)
	{
		independent_total += array[2][counter].independent;
	}
// Return Independent Popular
	return independent_popular = (independent_total / total) * 100.0;
}

// Election Four Function
char election_four(Election array[][3])
{
// Local Variables
	int r1 = array[3][0].republican;
	int d1 = array[3][0].democrat;
	int i1 = array[3][0].independent;
	int electoral_one = array[3][0].electoral;
	int republican_electoral = 0;
	int democrat_electoral = 0;
	int independent_electoral = 0;
	char winner;
// Louisiana
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
	else if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
	else if (i1 > r1 && i1 > d1)
	{
		independent_electoral += electoral_one;
	}
// Determine Winner
	if (republican_electoral > democrat_electoral && republican_electoral > independent_electoral)
	{
		return winner = 'r';
	}
	else if (democrat_electoral > republican_electoral && democrat_electoral > independent_electoral)
	{
		return winner = 'd';
	}
	else if (independent_electoral > republican_electoral && independent_electoral > democrat_electoral)
	{
		return winner = 'i';
	}
	else
		return winner = 't';
}

// Republican Electoral4 Function
int republican_electoral4(Election array[][3])
{
// Local Variables
	int r1 = array[3][0].republican;
	int d1 = array[3][0].democrat;
	int i1 = array[3][0].independent;
	int electoral_one = array[3][0].electoral;
	int republican_electoral = 0;
// Louisiana
	if (r1 > d1 && r1 > i1)
	{
		republican_electoral += electoral_one;
	}
// Return Republican Electoral
	return republican_electoral;
}

// Democrat Electoral4 Function
int democrat_electoral4(Election array[][3])
{
// Local Variables
	int r1 = array[3][0].republican;
	int d1 = array[3][0].democrat;
	int i1 = array[3][0].independent;
	int electoral_one = array[3][0].electoral;
	int democrat_electoral = 0;
// Louisiana
	if (d1 > r1 && d1 > i1)
	{
		democrat_electoral += electoral_one;
	}
// Return Democrat Electoral
	return democrat_electoral;
}

// Independent Electoral4 Function
int independent_electoral4(Election array[][3])
{
// Local Variables
	int r1 = array[3][0].republican;
	int d1 = array[3][0].democrat;
	int i1 = array[3][0].independent;
	int electoral_one = array[3][0].electoral;
	int independent_electoral = 0;
// Louisiana
	if (i1 > d1 && i1 > r1)
	{
		independent_electoral += electoral_one;
	}
// Return Independent Electoral
	return independent_electoral;
}

// Republican Popular4 Function
double republican_popular4(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double republican_total = 0.0;
	int counter;
	double republican_popular;
// Total Votes
	for (counter = 0; counter < 1; counter++)
	{
		total += array[3][counter].republican + array[3][counter].democrat + array[3][counter].independent;
	}
// Republican Total
	for (counter = 0; counter < 1; counter++)
	{
		republican_total += array[3][counter].republican;
	}
// Return Republican Popular
	return republican_popular = (republican_total / total) * 100.0;
}

// Republican Popular4 Function
double democrat_popular4(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double democrat_total = 0.0;
	int counter;
	double democrat_popular;
// Total Votes
	for (counter = 0; counter < 1; counter++)
	{
		total += array[3][counter].republican + array[3][counter].democrat + array[3][counter].independent;
	}
// Democrat Total
	for (counter = 0; counter < 1; counter++)
	{
		democrat_total += array[3][counter].democrat;
	}
// Return Democrat Popular
	return democrat_popular = (democrat_total / total) * 100.0;
}

// Independent Popular4 Function
double independent_popular4(Election array[][3])
{
// Local Variables
	double total = 0.0;
	double independent_total = 0.0;
	int counter;
	double independent_popular;
// Total Votes
	for (counter = 0; counter < 1; counter++)
	{
		total += array[3][counter].republican + array[3][counter].democrat + array[3][counter].independent;
	}
// Independent Total
	for (counter = 0; counter < 1; counter++)
	{
		independent_total += array[3][counter].independent;
	}
// Return Independent Popular
	return independent_popular = (independent_total / total) * 100.0;
}