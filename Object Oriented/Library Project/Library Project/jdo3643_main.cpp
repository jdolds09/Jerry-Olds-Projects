#include "jdo3643_Library.h"
#include "jdo3643_View.h"
#include "jdo3643_Controller.h"
#include <iomanip>

// Function prototype
Customer create_customer(Library* library, int id);
Media create_book(Library* library, int m_size, int b_size);
Media create_movie(Library* library, int media_size, int movie_size);
Media create_album(Library* library, int m_size, int ma_size);
Media create_show(Library* library, int m_size, int tss_size);
Media create_game(Library* library, int m_size, int vg_size);
Date check_in_media();

int main()
{
// Objects
	Library library;
	View view;
	Controller controller;
	Librarian librarian;
	Customer customer;
	Date check_out_date{ 2018, 4, 9 };
	Date due_date{ 2018, 4, 16 };
	Date check_in_date;
// Create default librarian
	library.create_new_librarian("Jane Doe", 1);
// Create default books
	library.create_new_media(1, "B1", "To Kill a Mockingbird", "Book");
	library.create_new_media(2, "B2", "Adventures of Huckleberry Finn", "Book");
	library.create_new_media(3, "B3", "Moby Dick", "Book");
	library.create_new_media(4, "B4", "Odyssey", "Book");
	library.create_new_media(5, "B5", "Oliver Twist", "Book");
// Create default movies
	library.create_new_media(6, "M1", "The Godfather", "Movie");
	library.create_new_media(7, "M2", "The Shawshank Redemption", "Movie");
	library.create_new_media(8, "M3", "Forrest Gump", "Movie");
	library.create_new_media(9, "M4", "Gladiator", "Movie");
	library.create_new_media(10, "M5", "Titanic", "Movie");
// Create defualt music albums
	library.create_new_media(11, "MA1", "Thriller", "Music Album");
	library.create_new_media(12, "MA2", "Back in Black", "Music Album");
	library.create_new_media(13, "MA3", "Rumours", "Music Album");
	library.create_new_media(14, "MA4", "The Wall", "Music Album");
	library.create_new_media(15, "MA5", "Led Zeppelin IV", "Music Album");
// Create default television show seasons
	library.create_new_media(16, "TSS1", "Game of Thrones", "Television Show Season");
	library.create_new_media(17, "TSS2", "Breaking Bad", "Television Show Season");
	library.create_new_media(18, "TSS3", "Westworld", "Television Show Season");
	library.create_new_media(19, "TSS4", "The Walking Dead", "Television Show Season");
	library.create_new_media(20, "TSS5", "Dexter", "Television Show Season");
// Create default video games
	library.create_new_media(21, "VG1", "Star Wars: Knights of the Old Republic", "Video Game");
	library.create_new_media(22, "VG2", "The Witcher 3: Wild Hunt", "Video Game");
	library.create_new_media(23, "VG3", "Red Dead Redemption", "Video Game");
	library.create_new_media(24, "VG4", "The Elder Scrolls IV: Oblivion", "Video Game");
	library.create_new_media(25, "VG5", "Fallout 4", "Video Game");
// Variables
	vector<Customer> customers = library.get_customers();
	vector<Librarian> librarians = library.get_librarians();
	vector<Media> medias = library.get_medias();
	vector<string> customer_names;
	vector<Media> books;
	vector<Media> movies;
	vector<Media> albums;
	vector<Media> shows;
	vector<Media> games;
	string n;
	double price = 0;
	int transaction_number = 1;
	int customer_selection;
	int menu_selection;
	int media_selection;
	int bundle_selection;
	int selection;
	char existing_customer;
	char go_again = 'Y';
	char check_another = 'Y';
// Create vector of books
	for (int i = 0; i < medias.size(); i++)
	{
		if (medias[i].get_genre() == "Book")
			books.push_back(medias[i]);
	}
// Create vector of movies
	for (int i = 0; i < medias.size(); i++)
	{
		if (medias[i].get_genre() == "Movie")
			movies.push_back(medias[i]);
	}
// Create vector of albums
	for (int i = 0; i < medias.size(); i++)
	{
		if (medias[i].get_genre() == "Music Album")
			albums.push_back(medias[i]);
	}
// Create vector of shows
	for (int i = 0; i < medias.size(); i++)
	{
		if (medias[i].get_genre() == "Television Show Season")
			shows.push_back(medias[i]);
	}
// Create vector of games
	for (int i = 0; i < medias.size(); i++)
	{
		if (medias[i].get_genre() == "Video Game")
			games.push_back(medias[i]);
	}

// Title
	view.title();

// User interface loop
	do
	{
	// Vectors that clear every iteration of loop
		vector<Media> books_for_checkout;
		vector<Media> movies_for_checkout;
		vector<Media> albums_for_checkout;
		vector<Media> shows_for_checkout;
		vector<Media> games_for_checkout;
		vector<Media> media_bundle;
		vector<Media> medias_checked_in;
		vector<Media> medias_checked_out;
		vector<Bundle> checked_out_bundles;
		vector<Bundle> bundles_checked_in;
	// Books for check out
		for (int i = 0; i < books.size(); i++)
		{
			if (books[i].get_checked_out() == false)
				books_for_checkout.push_back(books[i]);
		}
	// Movies for checkout
		for (int i = 0; i < movies.size(); i++)
		{
			if (movies[i].get_checked_out() == false)
				movies_for_checkout.push_back(movies[i]);
		}
	// Albums for checkout
		for (int i = 0; i < albums.size(); i++)
		{
			if (albums[i].get_checked_out() == false)
				albums_for_checkout.push_back(albums[i]);
		}
	// Shows for checkout
		for (int i = 0; i < shows.size(); i++)
		{
			if (shows[i].get_checked_out() == false)
				shows_for_checkout.push_back(shows[i]);
		}
	// Games for checkout
		for (int i = 0; i < games.size(); i++)
		{
			if (games[i].get_checked_out() == false)
				games_for_checkout.push_back(games[i]);
		}
	// Create customer if no customer exists
		if (customers.size() == 0)
		{
			customers.push_back(create_customer(&library, customers.size()));
			customer_selection = customers.size();
		}
	// Create or choose existing customer
		else
		{
			cout << "\nAre you an existing customer (Y/N)? ";
			cin >> existing_customer;
			cin.ignore();
			existing_customer = toupper(existing_customer);
		// Input validation
			while (existing_customer != 'Y' && existing_customer != 'N')
			{
				cout << "\nInvalid input." << endl;
				cout << "Are you an existing customer (Y/N)? ";
				cin >> existing_customer;
				existing_customer = toupper(existing_customer);
			}
		// Create new customer
			if (existing_customer == 'N')
			{
				customers.push_back(create_customer(&library, customers.size()));
				customer_selection = customers.size();
			}
		// Choose existing customer
			else
			{
				view.customer_list(customers);
				customer_selection = controller.customer_select(customers);
			}
		}
	// Choose action
		view.menu();
		menu_selection = controller.menu_select();
	
	// Preform action
		switch (menu_selection)
		{

// ***********CHECK OUT MEDIA******************
		case 1:
			view.media_catalog();
			media_selection = controller.menu_select();
			switch (media_selection)
			{
			// Check out book
			case 1:
				view.book_catalog(books_for_checkout);
				selection = controller.media_select(books_for_checkout);
				if (selection == books_for_checkout.size() + 1)
				{
					books.push_back(create_book(&library, medias.size(), books.size()));
					books[books.size() - 1].set_check(true);
					view.checked_out(books[books.size() - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(books[books.size() - 1]);
				}
				else
				{
					selection += books.size() - books_for_checkout.size();
					books[selection - 1].set_check(true);
					selection -= books.size() - books_for_checkout.size();
					view.checked_out(books_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(books_for_checkout[selection - 1]);
				}
				break;
			// Check out movie
			case 2:
				view.movie_catalog(movies_for_checkout);
				selection = controller.media_select(movies_for_checkout);
				if (selection == movies.size() + 1)
				{
					movies.push_back(create_movie(&library, medias.size(), movies.size()));
					movies[selection - 1].set_check(true);
					view.checked_out(movies[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(movies[selection - 1]);
				}
				else
				{
					movies[selection - 1].set_check(true);
					view.checked_out(movies_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(movies_for_checkout[selection - 1]);
				}
				break;
			// Check out music album
			case 3:
				view.music_album_catalog(albums_for_checkout);
				selection = controller.media_select(albums_for_checkout);
				if (selection == albums.size() + 1)
				{
					albums.push_back(create_album(&library, medias.size(), albums.size()));
					albums[selection - 1].set_check(true);
					view.checked_out(albums[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(albums[selection - 1]);
				}
				else
				{
					albums[selection - 1].set_check(true);
					view.checked_out(albums_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(albums_for_checkout[selection - 1]);
				}
				break;
			// Check out television show season
			case 4:
				view.television_show_season_catalog(shows_for_checkout);
				selection = controller.media_select(shows_for_checkout);
				if (selection == shows.size() + 1)
				{
					shows.push_back(create_show(&library, medias.size(), shows.size()));
					shows[selection - 1].set_check(true);
					view.checked_out(shows[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(shows[selection - 1]);
				}
				else
				{
					shows[selection - 1].set_check(true);
					view.checked_out(shows_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(shows_for_checkout[selection - 1]);
				}
				break;
			// Check out video game
			case 5:
				view.video_game_catalog(games_for_checkout);
				selection = controller.media_select(games_for_checkout);
				if (selection == games.size() + 1)
				{
					games.push_back(create_game(&library, medias.size(), games.size()));
					games[selection - 1].set_check(true);
					view.checked_out(games[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(games[selection - 1]);
				}
				else
				{
					games[selection - 1].set_check(true);
					view.checked_out(games_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					customers[customer_selection - 1].check_out_media(games_for_checkout[selection - 1]);
				}
				break;
			}
			break;

// ***********CHECK OUT BUNDLE******************
		case 2:
			view.bundle_catalog();
			 bundle_selection = controller.bundle_select();
			 switch (bundle_selection)
			 {
				 // First bundle
			 case 1:
				 // Check out book
				 view.book_catalog(books_for_checkout);
				 selection = controller.media_select(books_for_checkout);
				 if (selection == books_for_checkout.size() + 1)
				 {
					 books.push_back(create_book(&library, medias.size(), books.size()));
					 books[selection - 1].set_check(true);
					 view.checked_out(books[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(books[selection - 1]);
				 }
				 else
				 {
					 books[selection - 1].set_check(true);
					 view.checked_out(books_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(books_for_checkout[selection - 1]);
				 }
				 // Check out movie
				 view.movie_catalog(movies_for_checkout);
				 selection = controller.media_select(movies_for_checkout);
				 if (selection == movies.size() + 1)
				 {
					 movies.push_back(create_movie(&library, medias.size(), movies.size()));
					 movies[selection - 1].set_check(true);
					 view.checked_out(movies[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(movies[selection - 1]);
				 }
				 else
				 {
					 movies[selection - 1].set_check(true);
					 view.checked_out(movies_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(movies_for_checkout[selection - 1]);
				 }
				 // Check out video game
				 view.video_game_catalog(games_for_checkout);
				 selection = controller.media_select(games_for_checkout);
				 if (selection == games.size() + 1)
				 {
					 games.push_back(create_game(&library, medias.size(), games.size()));
					 games[selection - 1].set_check(true);
					 view.checked_out(games[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(games[selection - 1]);
				 }
				 else
				 {
					 games[selection - 1].set_check(true);
					 view.checked_out(games_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(games_for_checkout[selection - 1]);
				 }
				 library.create_new_bundle("Bundle 1", media_bundle);
				 break;
				 // Second bundle
			 case 2:
				 // Check out movie
				 view.movie_catalog(movies_for_checkout);
				 selection = controller.media_select(movies_for_checkout);
				 if (selection == movies.size() + 1)
				 {
					 movies.push_back(create_movie(&library, medias.size(), movies.size()));
					 movies[selection - 1].set_check(true);
					 view.checked_out(movies[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(movies[selection - 1]);
				 }
				 else
				 {
					 movies[selection - 1].set_check(true);
					 view.checked_out(movies_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(movies_for_checkout[selection - 1]);
				 }
				 // Check out music album
				 view.music_album_catalog(albums_for_checkout);
				 selection = controller.media_select(albums_for_checkout);
				 if (selection == albums.size() + 1)
				 {
					 albums.push_back(create_album(&library, medias.size(), albums.size()));
					 albums[selection - 1].set_check(true);
					 view.checked_out(albums[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(albums[selection - 1]);
				 }
				 else
				 {
					 albums[selection - 1].set_check(true);
					 view.checked_out(albums_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(albums_for_checkout[selection - 1]);
				 }
				 // Check out television show season
				 view.television_show_season_catalog(shows_for_checkout);
				 selection = controller.media_select(shows_for_checkout);
				 if (selection == shows.size() + 1)
				 {
					 shows.push_back(create_show(&library, medias.size(), shows.size()));
					 shows[selection - 1].set_check(true);
					 view.checked_out(shows[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(shows[selection - 1]);
				 }
				 else
				 {
					 shows[selection - 1].set_check(true);
					 view.checked_out(shows_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(shows_for_checkout[selection - 1]);
				 }
				 library.create_new_bundle("Bundle 2", media_bundle);
				 break;
				 // Thrid bundle
			 case 3:
				 // Check out movie
				 view.movie_catalog(movies_for_checkout);
				 selection = controller.media_select(movies_for_checkout);
				 if (selection == movies.size() + 1)
				 {
					 movies.push_back(create_movie(&library, medias.size(), movies.size()));
					 movies[selection - 1].set_check(true);
					 view.checked_out(movies[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(movies[selection - 1]);
				 }
				 else
				 {
					 movies[selection - 1].set_check(true);
					 view.checked_out(movies_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(movies_for_checkout[selection - 1]);
				 }
				 // Check out television show season
				 view.television_show_season_catalog(shows_for_checkout);
				 selection = controller.media_select(shows_for_checkout);
				 if (selection == shows.size() + 1)
				 {
					 shows.push_back(create_show(&library, medias.size(), shows.size()));
					 shows[selection - 1].set_check(true);
					 view.checked_out(shows[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(shows[selection - 1]);
				 }
				 else
				 {
					 shows[selection - 1].set_check(true);
					 view.checked_out(shows_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(shows_for_checkout[selection - 1]);
				 }
				 // Check out video game
				 view.video_game_catalog(games_for_checkout);
				 selection = controller.media_select(games_for_checkout);
				 if (selection == games.size() + 1)
				 {
					 games.push_back(create_game(&library, medias.size(), games.size()));
					 games[selection - 1].set_check(true);
					 view.checked_out(games[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(games[selection - 1]);
				 }
				 else
				 {
					 games[selection - 1].set_check(true);
					 view.checked_out(games_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(games_for_checkout[selection - 1]);
				 }
				 library.create_new_bundle("Bundle 3", media_bundle);
				 break;
				 // Fourth bundle
			 case 4:
				 // Check out book
				 view.book_catalog(books_for_checkout);
				 selection = controller.media_select(books_for_checkout);
				 if (selection == books_for_checkout.size() + 1)
				 {
					 books.push_back(create_book(&library, medias.size(), books.size()));
					 books[selection - 1].set_check(true);
					 view.checked_out(books[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(books[selection - 1]);
				 }
				 else
				 {
					 books[selection - 1].set_check(true);
					 view.checked_out(books_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(books_for_checkout[selection - 1]);
				 }
				 // Check out music album
				 view.music_album_catalog(albums_for_checkout);
				 selection = controller.media_select(albums_for_checkout);
				 if (selection == albums.size() + 1)
				 {
					 albums.push_back(create_album(&library, medias.size(), albums.size()));
					 albums[selection - 1].set_check(true);
					 view.checked_out(albums[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(albums[selection - 1]);
				 }
				 else
				 {
					 albums[selection - 1].set_check(true);
					 view.checked_out(albums_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(albums_for_checkout[selection - 1]);
				 }
				 // Check out television show season
				 view.television_show_season_catalog(shows_for_checkout);
				 selection = controller.media_select(shows_for_checkout);
				 if (selection == shows.size() + 1)
				 {
					 shows.push_back(create_show(&library, medias.size(), shows.size()));
					 shows[selection - 1].set_check(true);
					 view.checked_out(shows[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(shows[selection - 1]);
				 }
				 else
				 {
					 shows[selection - 1].set_check(true);
					 view.checked_out(shows_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(shows_for_checkout[selection - 1]);
				 }
				 library.create_new_bundle("Bundle 4", media_bundle);
				 break;
				 // Fifth bundle
			 case 5:
				 // Check out book
				 view.book_catalog(books_for_checkout);
				 selection = controller.media_select(books_for_checkout);
				 if (selection == books_for_checkout.size() + 1)
				 {
					 books.push_back(create_book(&library, medias.size(), books.size()));
					 books[selection - 1].set_check(true);
					 view.checked_out(books[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(books[selection - 1]);
				 }
				 else
				 {
					 books[selection - 1].set_check(true);
					 view.checked_out(books_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(books_for_checkout[selection - 1]);
				 }
				 // Check out music album
				 view.music_album_catalog(albums_for_checkout);
				 selection = controller.media_select(albums_for_checkout);
				 if (selection == albums.size() + 1)
				 {
					 albums.push_back(create_album(&library, medias.size(), albums.size()));
					 albums[selection - 1].set_check(true);
					 view.checked_out(albums[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(albums[selection - 1]);
				 }
				 else
				 {
					 albums[selection - 1].set_check(true);
					 view.checked_out(albums_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(albums_for_checkout[selection - 1]);
				 }
				 // Check out video game
				 view.video_game_catalog(games_for_checkout);
				 selection = controller.media_select(games_for_checkout);
				 if (selection == games.size() + 1)
				 {
					 games.push_back(create_game(&library, medias.size(), games.size()));
					 games[selection - 1].set_check(true);
					 view.checked_out(games[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(games[selection - 1]);
				 }
				 else
				 {
					 games[selection - 1].set_check(true);
					 view.checked_out(games_for_checkout[selection - 1], check_out_date, due_date, customers[customer_selection - 1].get_name());
					 media_bundle.push_back(games_for_checkout[selection - 1]);
				 }
				 library.create_new_bundle("Bundle 5", media_bundle);
				 break;
			 }
				 checked_out_bundles = library.get_bundles();
				 for (int i = 0; i < checked_out_bundles.size(); i++)
					 customers[customer_selection - 1].check_out_bundle(checked_out_bundles[i]);
				 break;

// ********CHECK IN MEDIA*************
		case 3:
			if (customers[customer_selection - 1].get_checked_out_medias().size() == 0)
			{
				cout << endl << customers[customer_selection - 1].get_name() << " currently has no medias checked out." << endl;
				break;
			}
			medias_checked_out = customers[customer_selection - 1].get_checked_out_medias();
			while (medias_checked_out.size() != 0 && check_another == 'Y')
			{
				view.checked_out_medias_list(customers[customer_selection - 1], medias_checked_out);
				selection = controller.media_check_in_select(medias_checked_out);
				if (medias_checked_out[selection - 1].get_genre() == "Book")
				{
					for (int i = 0; i < books.size(); i++)
						if (books[i].get_title() == medias_checked_out[selection - 1].get_title())
							books[i].set_check(false);
				}
				if (medias_checked_out[selection - 1].get_genre() == "Movie")
				{
					for (int i = 0; i < movies.size(); i++)
						if (movies[i].get_title() == medias_checked_out[selection - 1].get_title())
							movies[i].set_check(false);
				}
				if (medias_checked_out[selection - 1].get_genre() == "Music Album")
				{
					for (int i = 0; i < albums.size(); i++)
						if (albums[i].get_title() == medias_checked_out[selection - 1].get_title())
							albums[i].set_check(false);
				}
				if (medias_checked_out[selection - 1].get_genre() == "Television Show Season")
				{
					for (int i = 0; i < shows.size(); i++)
						if (shows[i].get_title() == medias_checked_out[selection - 1].get_title())
							shows[i].set_check(false);
				}
				if (medias_checked_out[selection - 1].get_genre() == "Video Game")
				{
					for (int i = 0; i < games.size(); i++)
						if (games[i].get_title() == medias_checked_out[selection - 1].get_title())
							games[i].set_check(false);
				}
				medias_checked_in.push_back(medias_checked_out[selection - 1]);
				medias_checked_out.erase(medias_checked_out.begin() + (selection - 1));
				if (medias_checked_out.size() > 0)
				{
					cout << endl << "Would you like to check out another item (Y/N)? ";
					cin >> check_another;
					check_another = toupper(check_another);
					while (check_another != 'Y' && check_another != 'N')
					{
						cout << "\nInvalid input." << endl;
						cout << endl << "Would you like to check out another item (Y/N)? ";
						cin >> check_another;
						check_another = toupper(check_another);
					}
				}
			}
			check_in_date = check_in_media();
			library.create_new_transaction(transaction_number, check_out_date, due_date, check_in_date, customers[customer_selection - 1], medias_checked_in, bundles_checked_in);
			price = library.get_transactions()[transaction_number - 1].calculate_fee();
			customers[customer_selection - 1].add_balance(price);
			transaction_number++;
			break;

// ********CHECK IN BUNDLES*************
		case 4:
			if (customers[customer_selection - 1].get_checked_out_bundles().size() == 0)
			{
				cout << endl << customers[customer_selection - 1].get_name() << " currently has no bundles checked out." << endl;
				break;
			}
			checked_out_bundles = customers[customer_selection - 1].get_checked_out_bundles();
			while ((checked_out_bundles.size() - 1) != 0 && check_another == 'Y')
			{
				view.checked_out_bundles_list(customers[customer_selection - 1], checked_out_bundles);
				selection = controller.bundle_check_in_select(checked_out_bundles);
				checked_out_bundles[selection - 1].set_check(false);
				bundles_checked_in.push_back(checked_out_bundles[selection - 1]);
				checked_out_bundles.erase(checked_out_bundles.begin() + (selection - 1));
				if (checked_out_bundles.size() > 0)
				{
					cout << endl << "Would you like to check out another item (Y/N)? ";
					cin >> check_another;
					check_another = toupper(check_another);
					while (check_another != 'Y' && check_another != 'N')
					{
						cout << "\nInvalid input." << endl;
						cout << endl << "Would you like to check out another item (Y/N)? ";
						cin >> check_another;
						check_another = toupper(check_another);
					}
				}
			}
			check_in_date = check_in_media();
			library.create_new_transaction(transaction_number, check_out_date, due_date, check_in_date, customers[customer_selection - 1], medias_checked_in, bundles_checked_in);
			price = library.get_transactions()[transaction_number - 1].calculate_fee();
			customers[customer_selection - 1].add_balance(price);
			transaction_number++;
			break;

// ************GET CUSTOMER BALANCE****************
		case 5:
			cout << endl << "CUSTOMER BALANCE" << endl;
			cout << "-----------------" << endl;
			cout << customers[customer_selection - 1].get_name() << " total balance: " << customers[customer_selection - 1].get_balance() << endl << endl;
			break;

// ************CHECKED OUT ITEMS********************
		case 6:
			view.checked_out_items(customers);
			break;
		}
		cout << "Would you like to continue (Y/N)?  ";
		cin >> go_again;
		go_again = toupper(go_again);
		while (go_again != 'Y' && go_again != 'N')
		{
			cout << "\nInvalid input." << endl;
			cout << "Would you like to continue (Y/N)?  ";
			cin >> go_again;
			go_again = toupper(go_again);
		}
	} while (go_again != 'N');
// End of program
	return 0;
}

Customer create_customer(Library* library, int id)
{
// Variables
	string n;
	string pn;
	string e;
	vector<Customer> c;
// Prompt
	cout << "\nNEW CUSTOMER" << endl;
	cout << "-------------" << endl;
	cout << "Name: ";
	getline(cin, n);
	cout << "Phone Number: ";
	cin >> pn;
	cout << "Email: ";
	cin >> e;
// Create customer
	library->create_new_customer(n, id + 1, pn, e);
	c = library->get_customers();
	return c[c.size() - 1];
}

Media create_book(Library* library, int m_size, int b_size)
{
// Variables
	string t;
	string cn = "B" + to_string(b_size + 1);
	vector<Media> m;
// Prompt
	cout << "\nNEW BOOK" << endl;
	cout << "-----------" << endl;
	cout << "Enter the title of the book: ";
	cin >> t;
// Create new media
	library->create_new_media(m_size + 1, cn, t, "Book");
	m = library->get_medias();
	return m[m.size() - 1];
}

Media create_movie(Library* library, int media_size, int movie_size)
{
// Variables
	string t;
	string cn = "M" + to_string(movie_size + 1);
	vector<Media> m;
// Prompt
	cout << "\nNEW MOVIE" << endl;
	cout << "-----------" << endl;
	cout << "Enter the title of the movie: ";
	cin >> t;
// Create new media
	library->create_new_media(media_size + 1, cn, t, "Movie");
	m = library->get_medias();
	return m[m.size() - 1];
}

Media create_album(Library* library, int m_size, int ma_size)
{
// Variables
	string t;
	string cn = "MA" + to_string(ma_size + 1);
	vector<Media> ma;
// Prompt
	cout << "\nNEW MUSIC ALBUM" << endl;
	cout << "--------------" << endl;
	cout << "Enter the title of the music album: ";
	cin >> t;
// Create new media
	library->create_new_media(m_size + 1, cn, t, "Music Album");
	ma = library->get_medias();
	return ma[ma.size() - 1];
}

Media create_show(Library* library, int m_size, int tss_size)
{
	// Variables
	string t;
	string cn = "TSS" + to_string(tss_size + 1);
	vector<Media> tss;
	// Prompt
	cout << "\nNEW TELEVISON SHOW SEASON" << endl;
	cout << "--------------------" << endl;
	cout << "Enter the title of the television show: ";
	cin >> t;
	// Create new media
	library->create_new_media(m_size + 1, cn, t, "Television Show Season");
	tss = library->get_medias();
	return tss[tss.size() - 1];
}

Media create_game(Library* library, int m_size, int vg_size)
{
	// Variables
	string t;
	string cn = "VG" + to_string(vg_size + 1);
	vector<Media> vg;
	// Prompt
	cout << "\nNEW VIDEO GAME" << endl;
	cout << "---------------" << endl;
	cout << "Enter the title of the video game: ";
	cin >> t;
	// Create new media
	library->create_new_media(m_size + 1, cn, t, "Video Game");
	vg = library->get_medias();
	return vg[vg.size() - 1];
}

Date check_in_media()
{
// Variables
	int year; 
	int month;
	int day;
// Prompt
	cout << endl << "Enter the year the media was checked in (YYYY): ";
	cin >> year;
	cout << "Enter the month the media was checked in (MM): ";
	cin >> month;
	cout << "Enter the day the media was checked in (DD): ";
	cin >> day;
// Create date
	Date cid{ year, month, day };
	return cid;
}