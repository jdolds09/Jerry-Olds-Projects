// This program will take grades from a txt file
// and calculate the grade average of each student,
// sort the grade averages and display the lowest and 
// highest scores in the class, and display the class 
// average score of each grade
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Structure
struct Grades
{
	int studentId;
	double exam01;
	double exam02;
	double exam03;
	double exam04;
	double finalExam;
	double lab01;
	double lab02;
	double lab03;
	double lab04;
	double lab05;
	double quizAverage;
};

// Function Prototypes
void histogram(double [], int, int);
void sort(double [], int, int);
double exam01(Grades[], int, int);
double exam02(Grades[], int, int);
double exam03(Grades[], int, int);
double exam04(Grades[], int, int);
double finalExam(Grades[], int, int);
double labs(Grades[], int, int);
double quiz(Grades[], int, int);

int main()
// The main function will read in the data from the input file
// and display a histogram, the lowest and highest averages in
// the class, number of students, and the class average of each assingment.
{
// Constant (Array Size)
	const int ARRAY_SIZE = 25;
// Input File
	ifstream inputFile;
// Array of Grades
	Grades array[ARRAY_SIZE];
// Array of Grade Averages
	double averageArray[ARRAY_SIZE];
// Counter
	int count = 0;
// Variables
	double exam01Average;
	double exam02Average;
	double exam03Average;
	double exam04Average;
	double finalExamAverage;
	double labAverage;
	double quizAverage;
// Title of Program
	cout << "\t\t\t\tGrade Report" << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
// Open File
	inputFile.open("GradeReport.txt");
// Read in Grades (Grades Array)
	while (count < ARRAY_SIZE)
	{
		inputFile >> array[count].studentId;		// This array holds each individual 
		inputFile >> array[count].exam01;			// grade of each student
		inputFile >> array[count].exam02;
		inputFile >> array[count].exam03;
		inputFile >> array[count].exam04;
		inputFile >> array[count].finalExam;
		inputFile >> array[count].lab01;
		inputFile >> array[count].lab02;
		inputFile >> array[count].lab03;
		inputFile >> array[count].lab04;
		inputFile >> array[count].lab05;
		inputFile >> array[count].quizAverage;
		count++;
	}
// Close File
	inputFile.close();
// Grade Average Array
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		averageArray[count] = (array[count].exam01 + array[count].exam02 + array[count].exam03 +	// This array holds the grade  
							array[count].exam04 + array[count].finalExam +							// average of each student
							array[count].lab01 + array[count].lab02 +
							array[count].lab03 + array[count].lab04 +
							array[count].lab05 + array[count].quizAverage) / 11;
	}
// Call Histogram Function
	 histogram(averageArray, count, ARRAY_SIZE);
// Call Sort Function
	 sort(averageArray, count, ARRAY_SIZE);
// Call Exam01 Function
	 exam01Average = exam01(array, count, ARRAY_SIZE);
// Call Exam02 Function
	 exam02Average = exam02(array, count, ARRAY_SIZE);
// Call Exam03 Function
	 exam03Average = exam03(array, count, ARRAY_SIZE);
// Call Exam04 Function
	 exam04Average = exam04(array, count, ARRAY_SIZE);
// Call finalExam Function
	 finalExamAverage = finalExam(array, count, ARRAY_SIZE);
// Call Labs Function
	 labAverage = labs(array, count, ARRAY_SIZE);
// Call Quiz Function
	 quizAverage = quiz(array, count, ARRAY_SIZE);
// Display scores
	 cout << fixed << showpoint << setprecision(1);
	 cout << "\nLowest Score in Class: " << averageArray[0] << endl;
	 cout << "Highest Score in Class: " << averageArray[24] << endl;
	 cout << "Number of Students: " << count << endl;
	 cout << "\nExam01 Average: " << exam01Average << endl;
	 cout << "Exam02 Average: " << exam02Average << endl;
	 cout << "Exam03 Average: " << exam03Average << endl;
	 cout << "Exam04 Average: " << exam04Average << endl;
	 cout << "Final Exam Average: " << finalExamAverage << endl;
	 cout << "\nLabs Average: " << labAverage << endl;
	 cout << "Quizzes Average: " << quizAverage << endl;
	 cout << endl;
return 0;
}

// Histogram Function
void histogram(double averageArray[], int count, int ARRAY_SIZE)
{
// This function creates a histogram displaying the amount of students
// That got a certain letter grade.

// A grade
	cout << "A (90-100) ";
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		if (averageArray[count] >= 90 && averageArray[count] <= 100)
			cout << "*";
	}
	cout << endl;
// B grade
	cout << "B (80-89) ";
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		if (averageArray[count] >= 80 && averageArray[count] < 90)
			cout << "*";
	}
	cout << endl;
// C grade
	cout << "C (70-79) ";
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		if (averageArray[count] >= 70 && averageArray[count] < 80)
			cout << "*";
	}
	cout << endl;
// D grade
	cout << "D (60-69) ";
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		if (averageArray[count] >= 60 && averageArray[count] < 70)
			cout << "*";
	}
	cout << endl;
// F grade
	cout << "F (0-59) ";
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		if (averageArray[count] >= 0 && averageArray[count] < 60)
			cout << "*";
	}
	cout << endl;
}

// Sort Function
void sort(double averageArray[], int count, int ARRAY_SIZE)
// This function sorts averageArray in ascending order
// using the bubble sort.
{
// Local Variables
	bool swap;
	double temp;
// Bubble Sort
	do
	{
		swap = false;
		for (int count = 0; count < (ARRAY_SIZE - 1); count++)
		{
			if (averageArray[count] > averageArray[count + 1])
			{
				temp = averageArray[count];
				averageArray[count] = averageArray[count + 1];
				averageArray[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

// Exam01 Average Function
double exam01(Grades array[], int count, int ARRAY_SIZE)
// This function calculates the average score of the class
// on Exam 01.
{
// Local Variable
	double sumExam01 = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumExam01 += array[count].exam01;
	}
return (sumExam01 / 25.0);
}

// Exam02 Average Function
double exam02(Grades array[], int count, int ARRAY_SIZE)
// This function calculates the average score of the class
// on Exam 02.
{
// Local Variable
	double sumExam02 = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumExam02 += array[count].exam02;
	}
return (sumExam02 / 25.0);
}

// Exam03 Average Function
double exam03(Grades array[], int count, int ARRAY_SIZE)
// This function calculates the average score of the class
// on Exam 03.
{
// Local Variable
	double sumExam03 = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumExam03 += array[count].exam03;
	}
return (sumExam03 / 25.0);
}

// Exam04 Average Function
double exam04(Grades array[], int count, int ARRAY_SIZE)
// This function calcualtes the average score of the class
// on Exam 04
{
// Local Variable
	double sumExam04 = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumExam04 += array[count].exam04;
	}
return (sumExam04 / 25.0);
}

// Final Exam Average Function
double finalExam(Grades array[], int count, int ARRAY_SIZE)
// This fucntion calculates the average score of the class
// on the Final Exam.
{
// Local Variable
	double sumFinal = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumFinal += array[count].finalExam;
	}
return (sumFinal / 25.0);
}

// Labs Average Function
double labs(Grades array[], int count, int ARRAY_SIZE)
// This function calcualtes the average score of the class
// of the Lab Assignments.
{
// Local Variable
	double sumLabs = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumLabs += (array[count].lab01 + array[count].lab02 + array[count].lab03 + array[count].lab04 + array[count].lab05);
	}
	return (sumLabs / 125.0);
}

// Quiz Average Function
double quiz(Grades array[], int count, int ARRAY_SIZE)
// This function calculates the class average
// of the quiz assignments.
{
// Local Variable
	double sumQuiz = 0.0;
// Sum Loop
	for (count = 0; count < ARRAY_SIZE; count++)
	{
		sumQuiz += array[count].quizAverage;
	}
	return (sumQuiz / 25.0);
}