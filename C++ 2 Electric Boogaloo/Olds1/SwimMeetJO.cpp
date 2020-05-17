// Author: Jerry Olds
// Course: COSC 1437
// Program 3
// References: https://www.tutorialspoint.com/cplusplus/cpp_goto_statement.htm
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
using namespace std;

// Swim Meet Structure
struct SwimMeet
{
	string firstName;
	string lastName;
	char DQ;
	char Q;
	int minute;
	char colon;
	double second;
};

// Function Prototype
void sort(SwimMeet array[], int numCompetitors);

int main()
{
// Variables
	int numRaces;
	int distance;	
	int numCompetitors;
	int count = 0;
	char unit;
	string raceType;
	string fileName;
// Input File
	ifstream inputFile;
// Structure Array
	SwimMeet array[18];
// Output
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "\t\t\t       Swim Meet Program" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Enter the file name: ";
	getline(cin, fileName);
	cout << endl;
// Open File
	inputFile.open("swim.txt");
// Read in Swim Meet Information
	inputFile >> numRaces;
	inputFile >> distance;
	inputFile >> unit;
	inputFile >> raceType;
	inputFile >> numCompetitors;
	LOOP: while (count < numCompetitors)
	{
		inputFile >> array[count].firstName;
		inputFile >> array[count].lastName;
		inputFile >> array[count].DQ;
		if (array[count].DQ == 'D')
		{
			inputFile >> array[count].Q;
			array[count].minute = 99;
			array[count].colon = ':';
			array[count].second = 59.99;
			count++;
			goto LOOP;
		}
		inputFile >> array[count].minute;		
		inputFile >> array[count].colon;
		inputFile >> array[count].second;
		count++;
	}
// Close File
	inputFile.close();
// Call Sort Function
	sort(array, numCompetitors);
// Consolation Race 
	cout << fixed << showpoint << setprecision(2);
	cout << distance << " " << unit << " " << raceType << " CONSOLATION FINALS" << endl;
	cout << "1 " << array[14].lastName << ", " << array[14].firstName << " 0" << array[14].minute << array[14].colon << array[14].second << endl;
	cout << "2 " << array[12].lastName << ", " << array[12].firstName << " 0" << array[12].minute << array[12].colon << array[12].second << endl;
	cout << "3 " << array[10].lastName << ", " << array[10].firstName << " 0" << array[10].minute << array[10].colon << array[10].second << endl;
	cout << "4 " << array[8].lastName << ", " << array[8].firstName << " 0" << array[8].minute << array[8].colon << array[8].second << endl;
	cout << "5 " << array[9].lastName << ", " << array[9].firstName << " 0" << array[9].minute << array[9].colon << array[9].second << endl;
	cout << "6 " << array[11].lastName << ", " << array[11].firstName << " 0" << array[11].minute << array[11].colon << array[11].second << endl;
	cout << "7 " << array[13].lastName << ", " << array[13].firstName << " 0" << array[13].minute << array[13].colon << array[13].second << endl;
	cout << "8 " << array[15].lastName << ", " << array[15].firstName << " 0" << array[15].minute << array[15].colon << array[15].second << endl << endl;
// Championship Race
	cout << distance << " " << unit << " " << raceType << " CHAMPIONSHIP FINALS" << endl;
	cout << "1 " << array[6].lastName << ", " << array[6].firstName << " 0" << array[6].minute << array[6].colon << array[6].second << endl;
	cout << "2 " << array[4].lastName << ", " << array[4].firstName << " 0" << array[4].minute << array[4].colon << array[4].second << endl;
	cout << "3 " << array[2].lastName << ", " << array[2].firstName << " 0" << array[2].minute << array[2].colon << array[2].second << endl;
	cout << "4 " << array[0].lastName << ", " << array[0].firstName << " 0" << array[0].minute << array[0].colon << array[0].second << endl;
	cout << "5 " << array[1].lastName << ", " << array[1].firstName << " 0" << array[1].minute << array[1].colon << array[1].second << endl;
	cout << "6 " << array[3].lastName << ", " << array[3].firstName << " 0" << array[3].minute << array[3].colon << array[3].second << endl;
	cout << "7 " << array[5].lastName << ", " << array[5].firstName << " 0" << array[5].minute << array[5].colon << array[5].second << endl;
	cout << "8 " << array[7].lastName << ", " << array[7].firstName << " 0" << array[7].minute << array[7].colon << array[7].second << endl << endl;
// End of Program
	return 0;
}

// Sort Function
void sort(SwimMeet array[], int numCompetitors)
{
// Local Variables
	bool swap;
	string temp1;
	string temp2;
	int temp3;
	double temp4;
// Bubble Sort
	do
	{
		swap = false;
		for (int count = 0; count < (numCompetitors - 1); count++)
		{
			if (array[count].second > array[count + 1].second)
			{
				temp1 = array[count].firstName;
				temp2 = array[count].lastName;
				temp3 = array[count].minute;
				temp4 = array[count].second;
				array[count].firstName = array[count + 1].firstName;
				array[count].lastName = array[count + 1].lastName;
				array[count].minute = array[count + 1].minute;
				array[count].second = array[count + 1].second;
				array[count + 1].firstName = temp1;
				array[count + 1].lastName = temp2;
				array[count + 1].minute = temp3;
				array[count + 1].second = temp4;
				swap = true;
			}
		}
	} while (swap);
}