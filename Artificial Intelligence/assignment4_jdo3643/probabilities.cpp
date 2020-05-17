#include<iostream>
#include<fstream>
using namespace std;

int main()
{
// Variables
	ifstream infile;
	int input;
	double count = 0;
	double baseball = 0;
	double tv = 0;
	double cat_food = 0;
	double feed_cat = 0;
	double baseball_t;
	double baseball_f;
	double tv_t;
	double tv_f;
	double cat_food_t;
	double cat_food_f;
	double feed_cat_t;
	double feed_cat_f;

	infile.open("probabilities.txt");
	
	while(infile >> input)
	{	
		count++;
		if(input == 1)
			baseball++;
		infile >> input;
		
		if(input == 1)
			tv++;
		infile >> input;

		if(input == 1)
			cat_food++;
		infile >> input;

		if(input == 1)
			feed_cat++;
	}

	baseball_t = (baseball / count);
	baseball_f = (1 - (baseball / count));
	tv_t = (tv / count);
	tv_f = (1 - (tv / count));
	cat_food_t = (cat_food / count);
	cat_food_f = (1 - (cat_food / count));
	feed_cat_t = (feed_cat / count);
	feed_cat_f = (1 - (feed_cat / count));

	cout << "\nBaseball game T: " << baseball_t << endl;
	cout << "Baseball game F: " << baseball_f << endl << endl;
	cout << "George watches tv T: " << tv_t << endl;
	cout << "George watches tv F: " << tv_f << endl << endl;
	cout << "Out of cat food T: " << cat_food_t << endl;
	cout << "Out of cat food F: " << cat_food_f << endl << endl;
	cout << "George feeds cat T: " << feed_cat_t << endl;
	cout << "George feeds cat F: " << feed_cat_f << endl << endl;
	
// End of program
	infile.close();
	return 0;	
}
