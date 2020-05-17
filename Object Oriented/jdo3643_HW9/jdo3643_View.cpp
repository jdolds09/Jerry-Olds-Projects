#include "jdo3643_View.h"

void View::title()
{
	cout << "LIBRARY DATABASE" << endl;
	cout << "=================" << endl;
}

void View::customer_list(vector<Customer> c)
{
	cout << "\nPlease select from list of existing customers: " << endl << endl;
	for (int i = 0; i < c.size(); i++)
	{
		cout << i + 1 << ") " << c[i].get_name() << endl;
	}
	cout << "----------------" << endl;
	cout << "Selection: ";
}

void View::librarian_list(vector<Librarian> l)
{
	cout << "\nPlease select from list of existing librarians: " << endl << endl;
	for (int i = 0; i < l.size(); i++)
	{
		cout << i + 1 << ") " << l[i].get_name() << endl;
	}
	cout << "----------------" << endl;
	cout << "Selection: ";
}

void View::menu()
{
	cout << "\nMENU" << endl;
	cout << "------" << endl;
	cout << "1) Check out media" << endl;
	cout << "2) Check out bundle" << endl;
	cout << "3) Check in media" << endl;
	cout << "4) Check in bundle" << endl;
	cout << "5) Make a payment" << endl;
	cout << "6) Exit" << endl;
	cout << "------------------------" << endl;
	cout << "Selection: ";
}

void View::media_catalog()
{
	cout << "\nMEDIA CATALOG" << endl;
	cout << "---------------" << endl;
	cout << "1) Book" << endl;
	cout << "2) Movie" << endl;
	cout << "3) Music Album" << endl;
	cout << "4) Television Show Season" << endl;
	cout << "5) Video Game" << endl;
	cout << "---------------------------" << endl;
	cout << "Selection: ";
}

void View::bundle_catalog()
{
	cout << "\nBUNDLE CATALOG" << endl;
	cout << "---------------" << endl;
	cout << "1) Book, Movie, Video Game" << endl;
	cout << "2) Movie, Music Album, Television Show Season" << endl;
	cout << "3) Movie, Television Show Season, Video Game" << endl;
	cout << "4) Book, Music Album, Television Show Season" << endl;
	cout << "5) Book, Music Album, Video Game" << endl;
	cout << "----------------------------------------" << endl;
	cout << "Selection: ";
}

void View::book_catalog(vector<Media> b)
{
// Book object
	Book book;
	int i = 0;
	int count = 1;
// Book Catalog
	cout << "\nBOOK CATALOG" << endl;
	cout << "--------------" << endl;
	for (i; i < b.size(); i++)
	{
		if (b[i].get_checked_out() == false)
		{
			book = b[i].get_book();
			cout << count << ") " << b[i].get_title() << " (" << book.get_author() << ", " << book.get_year() << ")" << endl;
			count++;
		}
	}
	cout << count << ") Other (GUI)" << endl;
	cout << "----------------------" << endl;
	cout << "Selection: ";
}

void View::movie_catalog(vector<Media> m)
{
// Movie object
	Movie movie;
// Variables
	vector<string> actors;
	int i = 0;
	int count = 1;
	// Movie Catalog
	cout << "\nMOVIE CATALOG" << endl;
	cout << "--------------";
	for (i; i < m.size(); i++)
	{
		if (m[i].get_checked_out() == false)
		{
			movie = m[i].get_movie();
			actors = movie.get_actors();
			cout << endl << count << ") " << m[i].get_title() << " (" << movie.get_year() << ")";
			count++;
		}
	}
	cout << endl << count << ") Other (GUI)" << endl;
	cout << "----------------------" << endl;
	cout << "Selection: ";
}

void View::music_album_catalog(vector<Media> ma)
{
// Music album object
	Music_Album music_album;
// Variables
	int i = 0;
	int count = 1;
// Music album catalog
	cout << "\nMUSIC ALBUM CATALOG" << endl;
	cout << "--------------";
	for (i; i < ma.size(); i++)
	{
		if (ma[i].get_checked_out() == false)
		{
			music_album = ma[i].get_music_album();
			cout << endl << count << ") " << ma[i].get_title() << " (" << music_album.get_artist() << ", " << music_album.get_year() << ")";
			count++;
		}
	}
	cout << endl << count << ") Other (GUI)" << endl;
	cout << "----------------------" << endl;
	cout << "Selection: ";
}

void View::television_show_season_catalog(vector<Media> tss)
{
// Television show season object
	Television_Show_Season television_show_season;
// Variables
	int i = 0;
	int count = 1;
// Television show season catalog
	cout << "\nTELEVISION SHOW SEASON CATALOG" << endl;
	cout << "------------------------------";
	for (i; i < tss.size(); i++)
	{
		if (tss[i].get_checked_out() == false)
		{
			television_show_season = tss[i].get_television_show_season();
			cout << endl << count << ") " << tss[i].get_title() << "(Season " << television_show_season.get_season_num() << ", " << television_show_season.get_year() << ")";
			count++;
		}
	}
	cout << endl << count << ") Other (GUI)" << endl;
	cout << "----------------------" << endl;
	cout << "Selection: ";
}

void View::video_game_catalog(vector<Media> vg)
{
// Video game object
	Video_Game video_game;
// Variables
	int i = 0;
	int count = 1;
	// Video game catalog
	cout << "\nVIDEO GAME CATALOG" << endl;
	cout << "-------------------";
	for (i; i < vg.size(); i++)
	{
		if (vg[i].get_checked_out() == false)
		{
			video_game = vg[i].get_video_game();
			cout << endl << count << ") " << vg[i].get_title() << " (" << video_game.get_studio() << ", " << video_game.get_year() << ")";
			count++;
		}
	}
	cout << endl << count << ") Other (GUI)" << endl;
	cout << "----------------------" << endl;
	cout << "Selection: ";
}

void View::checked_out(Media m, Date cod, Date dd, string n)
{
	cout << "\n" << n << " has sucessfully checked out " << m.get_title() << " on (" << cod.get_month() << "/" << cod.get_day() << "/" << cod.get_year() << "). Due date is (" << dd.get_month() << "/" << dd.get_day() << "/" << dd.get_year() << ")." << endl << endl;;
}

void View::checked_out_medias_list(Customer c, vector<Media> m)
{
// Prompt
	cout << endl << c.get_name() << " currently has these medias checked out: " << endl << endl;
	for (int i = 0; i < m.size(); i++)
		cout << i + 1 << ") " << m[i].get_title() << endl;
	cout << "------------------------------" << endl;
	cout << "Please choose one to check in: ";
}

void View::checked_out_bundles_list(Customer c, vector<Bundle> b)
{
// Prompt
	cout << endl << c.get_name() << " currently has these bundles checked out: " << endl << endl;
	for (int i = 1; i < b.size(); i++)
		cout << i << ") " << b[i].get_bundle_name() << endl;
	cout << "------------------------------" << endl;
	cout << "Please choose one to check in: ";
}
