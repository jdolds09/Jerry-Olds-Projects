#include "jdo3643_Library.h"
#include <iomanip>

int main()
{
// Object 
	Library library;
	Transaction transaction;
// Variables
	string name;
	string email;
	unsigned int phone;
	int selection;
	int medias = 0;
	int bundles = 0;
	double price;
// Prompt
	cout << "\nEnter the name of the customer: ";
	getline(cin, name);
	cout << "Enter phone number of customer(1234567890): ";
	cin >> phone;
	cout << "Enter email address of customer: ";
	cin >> email;
// Create customer
	library.create_new_customer(name, 1, phone, email);
// Create librarian
	library.create_new_librarian("Kate Smith", 1);
// Check out media
	cout << "What media would you like to check out: " << endl;
	cout << "1) Book" << endl;
	cout << "2) Movie" << endl;
	cout << "3) Video Game" << endl;
	cout << "4) Music Album" << endl;
	cout << "5) Television Show Season" << endl;
	cout << "---------------------------" << endl;
	cout << "Selection: ";
	cin >> selection;
	while (selection < 1 || selection > 5)
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
	switch(selection)
	{
	case 1:
		library.create_new_media(1, "B1", "Aventures of Huckleberry Finn", "Book");
		break;
	case 2:
		library.create_new_media(1, "M1", "The Sandlot", "Movie");
		break;
	case 3:
		library.create_new_media(1, "VG1", "Star Wars: Knights of the Old Republic", "Video Game");
		break;
	case 4:
		library.create_new_media(1, "MA1", "Thriller", "Music Album");
		break;
	case 5:
		library.create_new_media(1, "TSS1", "Game of Thrones Season 7", "Television Show Season");
		break;
	}
	medias++;
// Check out bundle
	cout << "\nWhat bundle would you like to check out: " << endl;
	cout << "1) Book, Movie, Video Game" << endl;
	cout << "2) Video Game, Music Album, Television Show Season" << endl;
	cout << "---------------------------" << endl;
	cout << "Selection: ";
	cin >> selection;
	while (selection < 1 || selection > 5)
	{
		cout << "\nInvalid input." << endl;
		cout << "Selection: ";
		cin >> selection;
	}
// Create Bundles
	vector<Media> bundle;
	Media book{ 1, "B1", "Aventures of Huckleberry Finn", "Book" };
	Media movie{ 1, "M1", "The Sandlot", "Movie" };
	Media video_game{ 1, "VG1", "Star Wars: Knights of the Old Republic", "Video Game" };
	Media music_album{ 1, "MA1", "Thriller", "Music Album" };
	Media television_show{ 1, "TSS1", "Game of Thrones Season 7", "Television Show Season" };
	switch (selection)
	{
	case 1:
		bundle.push_back(book);
		bundle.push_back(movie);
		bundle.push_back(video_game);
		library.create_new_bundle("Bundle 1", bundle);
		break;
	case 2:
		bundle.push_back(video_game);
		bundle.push_back(music_album);
		bundle.push_back(television_show);
		library.create_new_bundle("Bundle 2", bundle);
		break;
	}
	bundles++;
	library.create_new_transaction();
	price = transaction.calculate_fee(medias, bundles);
	cout << fixed << setprecision(2) << "\nTotal balance: $" << price << endl;
// End of program
	return 0;
}
