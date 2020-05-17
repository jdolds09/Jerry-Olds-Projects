#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;

// Function Prototype
void output(int num, vector<char> v1, string word, int sum);

int main()
{
// Variables
    char letter;
    int num_letters = 0;
    int count = 0;
    int sum = 0;
    int num;
    string number = "";
    string secret_word = "";
    vector <char> v1;
    ifstream inFile;
    ofstream outFile;
// Open Input File
    inFile.open("Bonus_Words.txt");
// Read in data from input file
    inFile >> noskipws;
    while(inFile >> letter)
    {
        v1.push_back(letter);
        num_letters++;
        if(isupper(letter))
            secret_word += letter;
        while(isdigit(letter))
        {
            number += letter;
            inFile >> letter;
            v1.push_back(letter);
            num_letters++;
            if(!isdigit(letter))
            {
                num = stoi(number);
                number = "";
                sum += num;
            }
        }
    }
// Close input file
    inFile.close();
// Append file
    outFile.open("Bonus_Words.txt", ios::app);
    outFile << "\n\nSecret Word: " << secret_word << endl;
    outFile << "Sum: " << sum << endl; 
    outFile.close();
// Call Output Function
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
