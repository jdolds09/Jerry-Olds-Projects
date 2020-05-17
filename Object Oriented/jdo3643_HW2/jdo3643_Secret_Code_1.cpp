#include<iostream>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;

// Function prototype
void output(int num, vector<char> v1, string word, int sum);

int main()
{
// Variables
    char letter;
    int num_letters = 0;
    int count = 0;
    int sum = 0;
    int num;
    string secret_word = "";
    vector <char> v1;
    ifstream inFile;
    ofstream outFile;
// Open Input File
    inFile.open("Words.txt");
// Read in data from input file
    inFile >> noskipws;
    while(inFile >> letter)
    {
        if(isupper(letter))
            secret_word += letter;
        if(isdigit(letter))
        {
            num = letter - '0';
            sum += num;
        }
        v1.push_back(letter);
        num_letters++;
    }
// Append file
    outFile.open("Words.txt", ios::app);
    outFile << "\n\nSecret Word: " << secret_word << endl;
    outFile << "Sum: " << sum << endl; 
    outFile.close();
// Call output function
    output(num_letters, v1, secret_word, sum);
// End of Program
    return 0;
}

void output(int num, vector<char> v1, string word, int sum)
{
    // Display contents of vector
    cout << "\nFile Contents: " << endl;
    for(int i = 0; i < num; i++) 
        cout << v1[i];
// Output secret word and sum
    cout << "\n\nSecret Word: " << word << endl;
    cout << "Sum: " << sum << endl << endl;
}

