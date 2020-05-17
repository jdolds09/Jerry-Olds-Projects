#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
using namespace std;

int main(int argc, char *argv[])
{
// Variables
	ofstream outfile;
	string sequence;
	double h1 = .1;
	double h2 = .2;
	double h3 = .4;
	double h4 = .2;
	double h5 = .1;
	double c_next;
	double l_next;

	sequence = argv[1];

	outfile.open("result.txt");
	outfile << fixed << setprecision(5);
	outfile << "Observation sequence Q: " << sequence << endl;
	outfile << "Length of Q: " << sequence.length() << endl << endl;

// Calculate first step
	if(sequence[0] == 'C' || sequence[0] == 'c')
	{
		h1 = .2;
		h2 = .3;
		h3 = .4;
		h4 = .1;
		h5 = 0;
		c_next = .65;
		l_next = .35;

		outfile << "After Observation 1 = C:" << endl << endl;
		outfile << "P(h1 | Q) = " << h1 << endl;
		outfile << "P(h2 | Q) = " << h2 << endl;
		outfile << "P(h3 | Q) = " << h3 << endl;
		outfile << "P(h4 | Q) = " << h4 << endl;
		outfile << "P(h5 | Q) = " << h5 << endl << endl;
		outfile << "Probability that the next candy we pick will be C, given Q: " << c_next << endl;
		outfile << "Probability that the next candy we pick will be L, given Q: " << l_next << endl << endl;
	}

	else if(sequence[0] == 'L' || sequence[0] == 'l')
	{
		h1 = 0;
		h2 = .1;
		h3 = .4;
		h4 = .3;
		h5 = .2;
		c_next = .35;
		l_next = .65;

		outfile << "After Observation 1 = L:" << endl << endl;
		outfile << "P(h1 | Q) = " << h1 << endl;
		outfile << "P(h2 | Q) = " << h2 << endl;
		outfile << "P(h3 | Q) = " << h3 << endl;
		outfile << "P(h4 | Q) = " << h4 << endl;
		outfile << "P(h5 | Q) = " << h5 << endl << endl;
		outfile << "Probability that the next candy we pick will be C, given Q: " << c_next << endl;
		outfile << "Probability that the next candy we pick will be L, given Q: " << l_next << endl << endl;
	}

	else
	{
		cout << "Invalid character entered in at position 1" << endl;
		return 1;
	}

// Calculate every other observation
	for(int i = 1; i < sequence.length(); i++)
	{
		if(sequence[i] == 'C' || sequence[i] == 'c')
		{
			h1 = (1 * h1) / c_next;
			h2 = (.75 * h2) / c_next;
			h3 = (.5 * h3) / c_next;
			h4 = (.25 * h4) / c_next;
			h5 = 0;
			c_next = (1 * h1) + (.75 * h2) + (.5 * h3) + (.25 * h4);
			l_next = (.25 * h2) + (.5 * h3) + (.75 * h4) + (1 * h5);

			outfile << "After Observation " << i + 1 <<  " = C:" << endl << endl;
			outfile << "P(h1 | Q) = " << h1 << endl;
			outfile << "P(h2 | Q) = " << h2 << endl;
			outfile << "P(h3 | Q) = " << h3 << endl;
			outfile << "P(h4 | Q) = " << h4 << endl;
			outfile << "P(h5 | Q) = " << h5 << endl << endl;
			outfile << "Probability that the next candy we pick will be C, given Q: " << c_next << endl;
			outfile << "Probability that the next candy we pick will be L, given Q: " << l_next << endl << endl;
		}

		else if(sequence[i] == 'L' || sequence[i] == 'l')
		{
			h1 = 0;
			h2 = (.25 * h2) / l_next;
			h3 = (.5 * h3) / l_next;
			h4 = (.75 * h4) / l_next;
			h5 = (1 * h5)/ l_next;
			c_next = (1 * h1) + (.75 * h2) + (.5 * h3) + (.25 * h4);
			l_next = (.25 * h2) + (.5 * h3) + (.75 * h4) + (1 * h5);

			outfile << "After Observation " << i + 1 << " = L:" << endl << endl;
			outfile << "P(h1 | Q) = " << h1 << endl;
			outfile << "P(h2 | Q) = " << h2 << endl;
			outfile << "P(h3 | Q) = " << h3 << endl;
			outfile << "P(h4 | Q) = " << h4 << endl;
			outfile << "P(h5 | Q) = " << h5 << endl << endl;
			outfile << "Probability that the next candy we pick will be C, given Q: " << c_next << endl;
			outfile << "Probability that the next candy we pick will be L, given Q: " << l_next << endl << endl;
		}

		else
		{
			cout << "Invalid character entered at position " << i + 1 << endl;
			return 1;
		}
	}

// End of program
	outfile.close();
	cout << "\nresult.txt created successfully" << endl;
	return 0;	
}
