#include "jdo3643_Library.h"
#include "jdo3643_View.h"
#include "jdo3643_Controller.h"
#include "jdo3643_Customer_Window.h"
#include "jdo3643_Librarian_Window.h"
#include "jdo3643_Book_Window.h"
#include "jdo3643_Movie_Window.h"
#include "jdo3643_Music_Album_Window.h"
#include "jdo3643_Television_Show_Season_Window.h"
#include "jdo3643_Video_Game_Window.h"
#include "jdo3643_Payment_Window.h"
#include "jdo3643_Check_In_Window.h"
#include "jdo3643_Main_Window.h"
#include <fstream>
#include <gtkmm.h>
#include <iomanip>

// Function prototype
Customer create_customer(Library* library, int id, vector<string> details);
Librarian create_librarian(Library* library, int id, string n);
Media create_book(Library* library, int m_size, int b_size, vector<string> book_details);
Media create_movie(Library* library, int media_size, int movie_size, vector<string> movie_details);
Media create_album(Library* library, int m_size, int ma_size, vector<string> album_details);
Media create_show(Library* library, int m_size, int tss_size, vector<string> show_details);
Media create_game(Library* library, int m_size, int vg_size, vector<string> game_details);
Date check_in_media(vector<string> check_in_details);
void data_to_file(vector<Media> m, vector<Bundle> b, int selection, int customer_selection);
void read_data(Library* library, int selection, vector<Customer>* customers, vector<Librarian>* librarians, vector<Media>* books, vector<Media>* movies, vector<Media>* albums, vector<Media>* shows, vector<Media>* games, vector<Media>* medias);

int main(int argc, char *argv[])
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
	auto main_app = Gtk::Application::create(argc, argv, "Main Menu");
	auto app = Gtk::Application::create(argc, argv, "Customer Prompt");
	auto library_app = Gtk::Application::create(argc, argv, "Librarian Prompt");
	auto book_app = Gtk::Application::create(argc, argv, "Book Prompt");
	auto movie_app = Gtk::Application::create(argc, argv, "Movie Prompt");
	auto album_app = Gtk::Application::create(argc, argv, "Album Prompt");
	auto tss_app = Gtk::Application::create(argc, argv, "Show Prompt");
	auto game_app = Gtk::Application::create(argc, argv, "Show Prompt");
	auto payment_app = Gtk::Application::create(argc, argv, "Payment Prompt");
	auto check_in_app = Gtk::Application::create(argc, argv, "Check in Prompt");
	Main_Window main_window;
	Customer_Window customer_window;
	Librarian_Window librarian_window;
	Book_Window book_window;
	Movie_Window movie_window;
	Music_Album_Window album_window;
	Television_Show_Season_Window tss_window;
	Video_Game_Window game_window;
	Payment_Window payment_window;
	Check_In_Window check_in_window;
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
	ifstream libraries_file;
	ofstream library_database;
	vector<Customer> customers = library.get_customers();
	vector<Librarian> librarians = library.get_librarians();
	vector<Media> medias = library.get_medias();
	vector<string> customer_names;
	vector<Media> books;
	vector<Media> movies;
	vector<Media> albums;
	vector<Media> shows;
	vector<Media> games;
	vector<Media> file_medias;
	vector<Bundle> file_bundles;
	string n;
	string file_name;
	bool library_chosen = false;
	double price = 0;
	double payment_num;
	int num_libraries;
	int transaction_number = 1;
	int customer_selection;
	int librarian_selection = 1;
	int library_selection = 1;
	int menu_selection;
	int media_selection;
	int bundle_selection;
	int selection;
	char existing_customer;
	char go_again = 'Y';
	char check_another = 'Y';
	libraries_file.open("libraries");
	libraries_file >> num_libraries;
	libraries_file.close();
	cout << num_libraries << endl << endl;
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
	// Variables that clear every iteration of loop
		main_app = Gtk::Application::create(argc, argv, "");
		app = Gtk::Application::create(argc, argv, "");
		library_app = Gtk::Application::create(argc, argv, "");
		book_app = Gtk::Application::create(argc, argv, "");
		movie_app = Gtk::Application::create(argc, argv, "");
		album_app = Gtk::Application::create(argc, argv, "");
		tss_app = Gtk::Application::create(argc, argv, "");
		game_app = Gtk::Application::create(argc, argv, "");
		payment_app = Gtk::Application::create(argc, argv, "");
		check_in_app = Gtk::Application::create(argc, argv, "");
		string librarian_name;
		string payment;
        vector<string> customer_details;
		vector<string> book_details;
		vector<string> movie_details;
		vector<string> album_details;
		vector<string> show_details;
		vector<string> game_details;
		vector<string> check_in_details;
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
	// Choose library
		if(num_libraries != 0 && !library_chosen)
		{
			cout << "\nChoose library:" << endl;
			cout << "--------------" << endl;
			for(int i = 0; i < num_libraries; i++)
				cout << i + 1 << ") Library " << i + 1 << endl;
			cout << num_libraries + 1 << ") New library" << endl;
			cout << "--------------" << endl;
			cout << "Selection: ";
			cin >> library_selection;
		// Input validation
			while(library_selection < 1 || library_selection > num_libraries + 1)
			{
				cout << "Invalid input." << endl;
				cout << "Selection: ";
				cin >> library_selection;
			}
		// Read data in from libraries
			read_data(&library, library_selection, &customers, &librarians, &books, &movies, &albums, &shows, &games, &medias);	
		}
		
		library_chosen = true;

	// Create customer if no customer exists
		if (customers.size() == 0)
		{
			cout << "\nCREATE NEW CUSTOMER" << endl;
			cout << "---------------------" << endl << endl;
			app->run(customer_window);
			customer_details = customer_window.get_entries();
			customers.push_back(create_customer(&library, customers.size(), customer_details));
			customer_selection = customers.size();
			num_libraries++;
			file_name = "library" + to_string(num_libraries);
			library_database.open(file_name);
			library_database << "1 " << customer_details[0] << endl;
			library_database << customer_details[1] << endl;
			library_database << customer_details[2] << endl << endl;
			library_database.close();
			library_database.open("libraries");
			library_database << num_libraries;
			library_database.close();
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
				cout << "\nCREATE NEW CUSTOMER" << endl;
				cout << "---------------------" << endl << endl;
				app->run(customer_window);
				customer_details = customer_window.get_entries();
				customers.push_back(create_customer(&library, customers.size(), customer_details));
				customer_selection = customers.size();
				file_name = "library" + to_string(library_selection);
				library_database.open(file_name, ios::app);
				library_database << "1 " << customer_details[0] << endl;
				library_database << customer_details[1] << endl;
				library_database << customer_details[2] << endl << endl;
				library_database.close();
			}
		// Choose existing customer
			else
			{
				view.customer_list(customers);
				customer_selection = controller.customer_select(customers);
			}
		}
	 //Create librarian if no customer exists
		if (librarians.size() == 0)
		{
			cout << "\nCREATE NEW LIBRARIAN" << endl;
			cout << "------------------------" << endl << endl;
			library_app->run(librarian_window);
			librarian_name = librarian_window.get_name();
			librarians.push_back(create_librarian(&library, librarians.size(), librarian_name));
			librarian_selection = librarians.size();
			file_name = "library" + to_string(num_libraries);
			library_database.open(file_name, ios::app);
			library_database << "2 " << librarian_name << endl << endl;
			library_database.close();
		}
	// Create or choose existing librarian
		else
		{
			cout << "\nWould you like to choose an existing librarian (Y/N)? ";
			cin >> existing_customer;
			cin.ignore();
			existing_customer = toupper(existing_customer);
		// Input validation
			while (existing_customer != 'Y' && existing_customer != 'N')
			{
				cout << "\nInvalid input." << endl;
				cout << "\nWould you like to choose an existing librarian (Y/N)? ";
				cin >> existing_customer;
				existing_customer = toupper(existing_customer);
			}
		// Create new librarian
			if (existing_customer == 'N')
			{
				cout << "\nCREATE NEW LIBRARIAN" << endl;
				cout << "------------------------" << endl << endl;
				library_app->run(librarian_window);
				librarian_name = librarian_window.get_name();
				librarians.push_back(create_librarian(&library, librarians.size(), librarian_name));
				librarian_selection = librarians.size();
				file_name = "library" + to_string(library_selection);
				library_database.open(file_name, ios::app);
				library_database << "2 " << librarian_name << endl << endl;
				library_database.close();
			}
		// Choose existing librarian
			else
			{
				view.librarian_list(librarians);
				librarian_selection = controller.librarian_select(librarians);
			}
		}
	
	// Choose action
		main_app->run(main_window);
		menu_selection = main_window.get_selection();
	
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
			// Create new book
				if (selection == books_for_checkout.size() + 1)
				{
					cout << "\nNEW BOOK" << endl;
					cout << "-----------" << endl << endl;
					book_app->run(book_window);
					book_details = book_window.get_entries();
					books.push_back(create_book(&library, medias.size(), books.size(), book_details));
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
		// Create new movie
				if (selection == movies.size() + 1)
				{
					cout << "\nNEW MOVIE" << endl;
					cout << "-----------" << endl << endl;
					movie_app->run(movie_window);
					movie_details = movie_window.get_entries();
					movies.push_back(create_movie(&library, medias.size(), movies.size(), movie_details));
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
		// Create new music album
				if (selection == albums.size() + 1)
				{
					cout << "\nNEW MUSIC ALBUM" << endl;
					cout << "------------------" << endl << endl;
					album_app->run(album_window);
					album_details = album_window.get_entries();
					albums.push_back(create_album(&library, medias.size(), albums.size(), album_details));
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
			// Create new show
				if (selection == shows_for_checkout.size() + 1)
				{
					cout << "\nNEW TELEVISION SHOW SEASON" << endl;
					cout << "-----------------------------" << endl << endl;
					tss_app->run(tss_window);
					show_details = tss_window.get_entries();
					shows.push_back(create_show(&library, medias.size(), shows.size(), show_details));
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
		// Create new game
				if (selection == games.size() + 1)
				{
					cout << "\nNEW VIDEO GAME" << endl;
					cout << "-----------------" << endl << endl;
					game_app->run(game_window);
					game_details = game_window.get_entries();
					games.push_back(create_game(&library, medias.size(), games.size(), game_details));
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
			// Create new book
				
				 if (selection == books_for_checkout.size() + 1)
				 {
					cout << "\nNEW BOOK" << endl;
					cout << "-----------" << endl << endl;
					book_app->run(book_window);
					book_details = book_window.get_entries();
					books.push_back(create_book(&library, medias.size(), books.size(), book_details));
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
			// Create new movie
				 if (selection == movies.size() + 1)
				 {
					cout << "\nNEW MOVIE" << endl;
					cout << "-----------" << endl << endl;
					movie_app->run(movie_window);
					movie_details = movie_window.get_entries();
					movies.push_back(create_movie(&library, medias.size(), movies.size(), movie_details));
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
				// Create new game
				if (selection == games.size() + 1)
				{
					cout << "\nNEW VIDEO GAME" << endl;
					cout << "-----------------" << endl << endl;
					game_app->run(game_window);
					game_details = game_window.get_entries();
					games.push_back(create_game(&library, medias.size(), games.size(), game_details));
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
			// Create new movie
				 if (selection == movies.size() + 1)
				 {
					cout << "\nNEW MOVIE" << endl;
					cout << "-----------" << endl << endl;
					movie_app->run(movie_window);
					movie_details = movie_window.get_entries();
					movies.push_back(create_movie(&library, medias.size(), movies.size(), movie_details));
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
			// Create new album
				 if (selection == albums.size() + 1)
				 {
					cout << "\nNEW MUSIC ALBUM" << endl;
					cout << "------------------" << endl << endl;
					album_app->run(album_window);
					album_details = album_window.get_entries();
					albums.push_back(create_album(&library, medias.size(), albums.size(), album_details));
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
			// Create new show
				if (selection == shows_for_checkout.size() + 1)
				{
					cout << "\nNEW TELEVISION SHOW SEASON" << endl;
					cout << "-----------------------------" << endl << endl;
					tss_app->run(tss_window);
					show_details = tss_window.get_entries();
					shows.push_back(create_book(&library, medias.size(), shows.size(), show_details));
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
			// Create new movie
				 if (selection == movies.size() + 1)
				 {
					cout << "\nNEW MOVIE" << endl;
					cout << "-----------" << endl << endl;
					movie_app->run(movie_window);
					movie_details = movie_window.get_entries();
					movies.push_back(create_movie(&library, medias.size(), movies.size(), movie_details));
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
			// Create new show
				if (selection == shows_for_checkout.size() + 1)
				{
					cout << "\nNEW TELEVISION SHOW SEASON" << endl;
					cout << "-----------------------------" << endl << endl;
					tss_app->run(tss_window);
					show_details = tss_window.get_entries();
					shows.push_back(create_book(&library, medias.size(), shows.size(), show_details));
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
				 // Create new game
				if (selection == games.size() + 1)
				{
					cout << "\nNEW VIDEO GAME" << endl;
					cout << "-----------------" << endl << endl;
					game_app->run(game_window);
					game_details = game_window.get_entries();
					games.push_back(create_game(&library, medias.size(), games.size(), game_details));
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
			  // Create new book
				 if (selection == books_for_checkout.size() + 1)
				 {
					cout << "\nNEW BOOK" << endl;
					cout << "-----------" << endl << endl;
					book_app->run(book_window);
					book_details = book_window.get_entries();
					books.push_back(create_book(&library, medias.size(), books.size(), book_details));
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
			// Create new album
				 if (selection == albums.size() + 1)
				 {
					cout << "\nNEW MUSIC ALBUM" << endl;
					cout << "------------------" << endl << endl;
					album_app->run(album_window);
					album_details = album_window.get_entries();
					albums.push_back(create_album(&library, medias.size(), albums.size(), album_details));
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
			// Create new show
				if (selection == shows_for_checkout.size() + 1)
				{
					cout << "\nNEW TELEVISION SHOW SEASON" << endl;
					cout << "-----------------------------" << endl << endl;
					tss_app->run(tss_window);
					show_details = tss_window.get_entries();
					shows.push_back(create_book(&library, medias.size(), shows.size(), show_details));
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
			// Create new book
				 if (selection == books_for_checkout.size() + 1)
				 {
					cout << "\nNEW BOOK" << endl;
					cout << "-----------" << endl << endl;
					book_app->run(book_window);
					book_details = book_window.get_entries();
					books.push_back(create_book(&library, medias.size(), books.size(), book_details));
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
			// Create new album
				 if (selection == albums.size() + 1)
				 {
					cout << "\nNEW MUSIC ALBUM" << endl;
					cout << "------------------" << endl << endl;
					album_app->run(album_window);
					album_details = album_window.get_entries();
					albums.push_back(create_album(&library, medias.size(), albums.size(), album_details));
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
				 // Create new game
				if (selection == games.size() + 1)
				{
					cout << "\nNEW VIDEO GAME" << endl;
					cout << "-----------------" << endl << endl;
					game_app->run(game_window);
					game_details = game_window.get_entries();
					games.push_back(create_game(&library, medias.size(), games.size(), game_details));
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
				customers[customer_selection - 1].check_in_media(medias_checked_out[selection - 1]);
				if (medias_checked_out.size() > 0)
				{
					cout << endl << "Would you like to check in another item (Y/N)? ";
					cin >> check_another;
					check_another = toupper(check_another);
					while (check_another != 'Y' && check_another != 'N')
					{
						cout << "\nInvalid input." << endl;
						cout << endl << "Would you like to check in another item (Y/N)? ";
						cin >> check_another;
						check_another = toupper(check_another);
					}
				}
			}
			check_in_app->run(check_in_window);
			check_in_details = check_in_window.get_entries();
			check_in_date = check_in_media(check_in_details);
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
			
			check_in_app->run(check_in_window);
			check_in_details = check_in_window.get_entries();
			check_in_date = check_in_media(check_in_details);
			library.create_new_transaction(transaction_number, check_out_date, due_date, check_in_date, customers[customer_selection - 1], medias_checked_in, bundles_checked_in);
			price = library.get_transactions()[transaction_number - 1].calculate_fee();
			customers[customer_selection - 1].add_balance(price);
			transaction_number++;
			break;

// ************MAKE A PAYMENT****************
		case 5:
			cout << endl << "PAYMENT" << endl;
			cout << "-----------" << endl;
			if(customers[customer_selection -1].get_balance() == 0)
				cout << customers[customer_selection -1].get_name() << " does not currently have any fees to pay." << endl << endl;
			else
			{
				cout << customers[customer_selection - 1].get_name() << " total balance: $" << customers[customer_selection - 1].get_balance() << endl;
				payment_app->run(payment_window);
				payment = payment_window.get_entry();
				payment_num = stof(payment);
				if(payment_num > 0)
					payment_num -= (2 * payment_num);
				customers[customer_selection - 1].add_balance(payment_num);
				cout << customers[customer_selection - 1].get_name() << " total balance after payment: $" << customers[customer_selection - 1].get_balance() << endl << endl;
			}
			break;

// ***********CHECKED OUT ITEMS***************
		case 6:
			cout << endl << "CHECKED OUT ITEMS" << endl;
			cout << "------------------" << endl << endl;
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

// **********SEND DATA TO FILE*****************
	bool contains = false;
	for(int i = 0; i < customers[customer_selection - 1].get_checked_out_medias().size(); i++)
	{
		for(int j = 0; j < file_medias.size(); j++)
		{
			if(file_medias[j].get_title() == customers[customer_selection - 1].get_checked_out_medias()[i].get_title())
			{
				contains = true;
				file_medias.erase(file_medias.begin() + j);
			}
		}
		if(!contains)
			file_medias.push_back(customers[customer_selection - 1].get_checked_out_medias()[i]);
		contains = false;
	}
	for(int i = 0; i < customers[customer_selection - 1].get_checked_out_bundles().size(); i++)
	{
		for(int j = 0; j < file_bundles.size(); j++)
		{
			if(file_bundles[j].get_bundle_name() == customers[customer_selection - 1].get_checked_out_bundles()[i].get_bundle_name())
			{
				contains = true;
				file_bundles.erase(file_bundles.begin() + j);
			}
		}
		if(!contains)
			file_bundles.push_back(customers[customer_selection - 1].get_checked_out_bundles()[i]);
		contains = false;
	}
	data_to_file(file_medias, file_bundles, library_selection, customer_selection);

	} while (go_again != 'N');

// End of program
	return 0;
}

// CREATE CUSTOMER

Customer create_customer(Library* library, int id, vector<string> details)
{
// Vector
	vector<Customer> c;
// Create customer
	library->create_new_customer(details[0], id + 1, details[1], details[2]);
	c = library->get_customers();
	return c[c.size() - 1];
}

// CREATE LIBRARIAN

Librarian create_librarian(Library* library, int id, string n)
{
// Vector
	vector<Librarian> l;
// Create customer
	library->create_new_librarian(n, id + 1);
	l = library->get_librarians();
	return l[l.size() - 1];
}

// CREATE BOOK

Media create_book(Library* library, int m_size, int b_size, vector<string> book_details)
{
// Variables
	Media media;
	string cn = "B" + to_string(b_size + 1);
	int y = stoi(book_details[2]);
	vector<Media> m;
// Create new media
	library->create_new_media(m_size + 1, cn, book_details[0], "Book");
	Book b {book_details[1], y };
	media.set_book(b);
	m = library->get_medias();
	return m[m.size() - 1];
}

// CREATE MOVIE

Media create_movie(Library* library, int media_size, int movie_size, vector<string> movie_details)
{
// Variables
	Media media;
	int y = stoi(movie_details[1]);
	vector<string> actors;
	actors.push_back(movie_details[4]);
	actors.push_back(movie_details[5]);
	actors.push_back(movie_details[6]);
	string cn = "M" + to_string(movie_size + 1);
	vector<Media> m;
// Create new media
	library->create_new_media(media_size + 1, cn, movie_details[0], "Movie");
	Movie movie {y, movie_details[2], movie_details[3], actors};
	media.set_movie(movie);
	m = library->get_medias();
	return m[m.size() - 1];
}

// CREATE MUSIC ALBUM

Media create_album(Library* library, int m_size, int ma_size, vector<string> album_details)
{
// Variables
	Media media;
	int y = stoi(album_details[1]);
	vector<string> tracks;
	tracks.push_back(album_details[3]);
	tracks.push_back(album_details[4]);
	tracks.push_back(album_details[5]);
	string cn = "MA" + to_string(ma_size + 1);
	vector<Media> ma;
// Create new media
	library->create_new_media(m_size + 1, cn, album_details[0], "Music Album");
	Music_Album music_album {y, album_details[2], tracks};
	media.set_album(music_album);
	ma = library->get_medias();
	return ma[ma.size() - 1];
}

// CREATE TELEVISION SHOW SEASON

Media create_show(Library* library, int m_size, int tss_size, vector<string> show_details)
{
	// Variables
	Media media;
	int y = stoi(show_details[1]);
	int sn = stoi(show_details[9]);
	vector<string> d;
	vector<string> la;
	d.push_back(show_details[3]);
	d.push_back(show_details[4]);
	d.push_back(show_details[5]);
	la.push_back(show_details[6]);
	la.push_back(show_details[7]);
	la.push_back(show_details[8]);
	string cn = "TSS" + to_string(tss_size + 1);
	vector<Media> tss;
	// Create new media
	library->create_new_media(m_size + 1, cn, show_details[0], "Television Show Season");
	Television_Show_Season television_show_season {y, show_details[2], d, la, sn};
	media.set_show(television_show_season);
	tss = library->get_medias();
	return tss[tss.size() - 1];
}

// CREATE VIDEO GAME

Media create_game(Library* library, int m_size, int vg_size, vector<string> game_details)
{
	// Variables
	Media media;
	int y = stoi(game_details[1]);
	string cn = "VG" + to_string(vg_size + 1);
	vector<Media> vg;
	// Create new media
	library->create_new_media(m_size + 1, cn, game_details[0], "Video Game");
	Video_Game video_game {y, game_details[2]};
	media.set_game(video_game);
	vg = library->get_medias();
	return vg[vg.size() - 1];
}

// CHECK IN MEDIA

Date check_in_media(vector<string> check_in_details)
{
// Variables
	int year = stoi(check_in_details[0]); 
	int month = stoi(check_in_details[1]);
	int day = stoi(check_in_details[2]);
// Create date
	Date cid{ year, month, day };
	return cid;
}

// SEND DATA TO FILE

void data_to_file(vector<Media> m, vector<Bundle> b, int selection, int customer_selection)
{
// File
	ofstream outFile;
	string file_name = "library" + to_string(selection);
	outFile.open(file_name, ios::app);
	for(int i = 0; i < b.size(); i++)
	{
		for(int j = 0; j < 3; j++)
			m.push_back(b[i].get_medias()[j]);
	}
// Write medias to file
	for(int i = 0; i < m.size(); i++)
	{
		outFile << "3" << endl;
		outFile << customer_selection << endl;
		outFile << m[i].get_id_number() << endl;
		outFile << m[i].get_call_number() << endl;
		outFile << m[i].get_title() << endl;
		outFile << m[i].get_genre() << endl;
		if(m[i].get_genre() == "Book")
		{
			Book book = m[i].get_book();
			outFile << book.get_author() << endl;
			outFile << book.get_year() << endl << endl;
		}
		if(m[i].get_genre() == "Movie")
		{
			Movie movie = m[i].get_movie();
			outFile << movie.get_year() << endl;
			outFile << movie.get_producer() << endl;
			outFile << movie.get_director() << endl;
			outFile << movie.get_actors()[0] << endl;
			outFile << movie.get_actors()[1] << endl;
			outFile << movie.get_actors()[2] << endl << endl;
		}
		if(m[i].get_genre() == "Music Album")
		{
			Music_Album music_album = m[i].get_music_album();
			outFile << music_album.get_year() << endl;
			outFile << music_album.get_artist() << endl;
			outFile << music_album.get_tracks()[0] << endl;
			outFile << music_album.get_tracks()[1] << endl;
			outFile << music_album.get_tracks()[2] << endl << endl;
		}
		if(m[i].get_genre() == "Television Show Season")
		{
			Television_Show_Season tss = m[i].get_television_show_season();
			outFile << tss.get_year() << endl;
			outFile << tss.get_producer() << endl;
			outFile << tss.get_directors()[0] << endl;
			outFile << tss.get_directors()[1] << endl;
			outFile << tss.get_directors()[2] << endl;
			outFile << tss.get_actors()[0] << endl;
			outFile << tss.get_actors()[1] << endl;
			outFile << tss.get_actors()[2] << endl;
			outFile << tss.get_season_num() << endl << endl; 
		}
		if(m[i].get_genre() == "Video Game")
		{
			Video_Game video_game = m[i].get_video_game();
			outFile << video_game.get_year() << endl;
			outFile << video_game.get_studio() << endl << endl;
		}
	}
// Close file
	outFile.close();
}

// READ
void read_data(Library* library, int selection, vector<Customer>* customers, vector<Librarian>* librarians, vector<Media>* books, vector<Media>* movies, vector<Media>* albums, vector<Media>* shows, vector<Media>* games, vector<Media>* medias)
{
// Variables
	ifstream inFile;
	string temp;
	string file_name = "library" + to_string(selection);
	inFile.open(file_name);
	vector<string> customer_details;
	vector<string> book_details;
	vector<string> movie_details;
	vector<string> album_details;
	vector<string> show_details;
	vector<string> game_details;
	int type;
	int customer_selection;
	int id;
	int cn;
	string title;
	string genre;
// Read data
	while(inFile >> type)
	{
		if(type == 1)
		{
			getline(inFile, temp);
			customer_details.push_back(temp);
			temp = "";
			inFile >> temp;
			customer_details.push_back(temp);
			temp = "";
			inFile >> temp;
			customer_details.push_back(temp);
			temp = "";
			customers->push_back(create_customer(library, customers->size(), customer_details));
		}
		if(type == 2)
		{
			getline(inFile, temp);
			librarians->push_back(create_librarian(library, librarians->size(), temp));
			temp = "";
		}
		if(type == 3)
		{
			inFile >> customer_selection;
			inFile >> id;
			inFile >> cn;
			inFile >> title;
			inFile >> genre;
			if(genre == "Book")
			{
				inFile >> temp;
				book_details.push_back(temp);
				temp = "";
				inFile >> temp;
				book_details.push_back(temp);
				temp = "";
				books->push_back(create_book(library, medias->size(), books->size(), book_details));
				(*books)[books->size() - 1].set_check(true);
				(*customers)[customer_selection - 1].check_out_media((*books)[books->size() - 1]);
			}
			if(genre == "Movie")
			{
				inFile >> temp;
				movie_details.push_back(temp);
				temp = "";
				inFile >> temp;
				movie_details.push_back(temp);
				temp = "";
				inFile >> temp;
				movie_details.push_back(temp);
				temp = "";
				inFile >> temp;
				movie_details.push_back(temp);
				temp = "";
				inFile >> temp;
				movie_details.push_back(temp);
				temp = "";
				inFile >> temp;
				movie_details.push_back(temp);
				temp = "";
				movies->push_back(create_movie(library, medias->size(), movies->size(), movie_details));
				(*movies)[movies->size() - 1].set_check(true);
				(*customers)[customer_selection - 1].check_out_media((*movies)[movies->size() - 1]);
			}
			if(genre == "Music Album")
			{
				inFile >> temp;
				album_details.push_back(temp);
				temp = "";
				inFile >> temp;
				album_details.push_back(temp);
				temp = "";
				inFile >> temp;
				album_details.push_back(temp);
				temp = "";
				inFile >> temp;
				album_details.push_back(temp);
				temp = "";
				inFile >> temp;
				album_details.push_back(temp);
				temp = "";
				albums->push_back(create_album(library, medias->size(), albums->size(), album_details));
				(*albums)[albums->size() - 1].set_check(true);
				(*customers)[customer_selection - 1].check_out_media((*albums)[albums->size() - 1]);
			}
			if(genre == "Television Show Season")
			{
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				inFile >> temp;
				show_details.push_back(temp);
				temp = "";
				shows->push_back(create_show(library, medias->size(), shows->size(), show_details));
				(*shows)[shows->size() - 1].set_check(true);
				(*customers)[customer_selection - 1].check_out_media((*shows)[shows->size() - 1]);
			}
			if(genre == "Video Game")
			{
				inFile >> temp;
				game_details.push_back(temp);
				temp = "";
				inFile >> temp;
				game_details.push_back(temp);
				temp = "";
				games->push_back(create_game(library, medias->size(), games->size(), game_details));
				(*games)[games->size() - 1].set_check(true);
				(*customers)[customer_selection - 1].check_out_media((*games)[games->size() - 1]);
			}
		}
	}
// Close file
	inFile.close();
}













