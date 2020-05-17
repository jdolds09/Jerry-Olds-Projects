#include "jdo3643_Media.h"

Media::Media()
{

}

Media::Media(int id, string cn, string t, string g)
{
	id_number = id;
	call_number = cn;
	title = t;
	genre = g;
	media_information(genre, title);
}

void Media::media_information(string g, string t)
{
// Variables
	string author;
	string actor;
	string producer;
	string director;
	string artist;
	string track;
	string studio;
	vector<string> la;
	vector<string> tracks;
	vector<string> directors;
	int season_num;
	int year;
// Complete television show information
	if (g == "Television Show Season")
	{
		if (t == "Game of Thrones")
		{
			vector<string> la{ "Kit Harington", "Emilia Clarke", "Peter Dinklage" };
			vector<string> directors{ "Tim Van Patten", "Brian Kirk", "Daniel Minahan", "Alan Taylor" };
			Television_Show_Season tss{ 2011, "David Benioff", directors, la, 1 };
			television_show_season = tss;
		}
		else if (t == "Breaking Bad")
		{
			vector<string> la{ "Bryan Cranston", "Aaron Paul", "Dean Norris" };
			vector<string> directors{ "Vince Gilligan", "Adam Bernstein", "Jim Mckay" };
			Television_Show_Season tss{ 2008, "Stewart A. Lyons", directors, la, 1 };
			television_show_season = tss;
		}
		else if (t == "Westworld")
		{
			vector<string> la{ "Evan Rachel Wood", "Thandie Newton", "Anthony Hopkins" };
			vector<string> directors{ "Jonathan Nolan", "Richard J. Lewis", "Neil Marshall" };
			Television_Show_Season tss{ 2016, "Athena Wickham", directors, la, 1 };
			television_show_season = tss;
		}
		else if (t == "The Walking Dead")
		{
			vector<string> la{ "Andrew Lincoln", "Norman Reedus", "Steven Yeun" };
			vector<string> directors{ "Frank Darabont", "Michelle MacLaren", "Gwyneth Horder-Payton" };
			Television_Show_Season tss{ 2010, "Jolly Dale", directors, la, 1 };
			television_show_season = tss;
		}
		else if (t == "Dexter")
		{
			vector<string> la{ "Michael C. Hall", "Jennifer Carpenter", "Julie Benz" };
			vector<string> directors{ "Michael Cuesta", "Robert Lieberman", "Tony Goldwyn" };
			Television_Show_Season tss{ 2006, "Robert Lloyd Lewis", directors, la, 1 };
			television_show_season = tss;
		}
		else
		{
			cout << "Enter the year the show was released: ";
			cin >> year;
			cout << "Enter the name of the producer: ";
			cin >> producer;
			cout << "Enter the name of 3 directors: ";
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << ". ";
				getline(cin, director);
				directors.push_back(director);
				director = "";
			}
			cout << "Enter the name of 3 leading actors in the movie:" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << ". ";
				getline(cin, actor);
				la.push_back(actor);
				actor = "";
			}
			cout << "Enter the season number: ";
			cin >> season_num;
			Television_Show_Season tss{ year, producer, directors, la, season_num };
			television_show_season = tss;
		}
	}
// Complete music album information
	if (g == "Music Album")
	{
		if (t == "Thriller")
		{
			vector<string> tracks{ "Thriller", "Beat it", "Billie Jean" };
			Music_Album ma{ 1982, "Michael Jackson", tracks };
			music_album = ma;
		}
		else if (t == "Led Zeppelin IV")
		{
			vector<string> tracks{ "Stairway to Heaven", "Rock and Roll", "Black Dog" };
			Music_Album ma{ 1971, "Led Zeppelin", tracks };
			music_album = ma;
		}
		else if (t == "The Wall")
		{
			vector<string> tracks{ "Another Brick in the Wall", "Mother", "The Thin Ice" };
			Music_Album ma{ 1979, "Pink Floyd", tracks };
			music_album = ma;
		}
		else if (t == "Back in Black")
		{
			vector<string> tracks{ "Back in Black", "Hells Bells", "Shoot to Thrill" };
			Music_Album ma{ 1980, "AC/DC", tracks };
			music_album = ma;
		}
		else if (t == "Rumours")
		{
			vector<string> tracks{ "Dreams", "Don't Stop", "Go Your Own Way" };
			Music_Album ma{ 1977, "Fleetwood Mac", tracks };
			music_album = ma;
		}
		else
		{
			cout << "Enter the year the album was released: ";
			cin >> year;
			cout << "Enter the name of the artist: ";
			getline(cin, artist);
			cout << "Enter the name of 3 tracks on the album:" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << ". ";
				getline(cin, track);
				tracks.push_back(track);
				track = "";
			}
			Music_Album ma{ year, artist, tracks };
			music_album = ma;
		}
	}
// Complete video game information
	if (g == "Video Game")
	{
		if (t == "Star Wars: Knights of the Old Republic")
		{
			Video_Game vg{ 2003, "Bioware" };
			video_game = vg;
		}
		else if (t == "The Witcher 3: Wild Hunt")
		{
			Video_Game vg{ 2015, "CD Projekt RED" };
			video_game = vg;
		}
		else if (t == "Red Dead Redemption")
		{
			Video_Game vg{ 2010, "Rockstar Games" };
			video_game = vg;
		}
		else if (t == "The Elder Scrolls IV: Oblivion")
		{
			Video_Game vg{ 2006, "Bethesda" };
			video_game = vg;
		}
		else if (t == "Fallout 4")
		{
			Video_Game vg{ 2015, "Bethesda" };
			video_game = vg;
		}
		else
		{
			cout << "Enter the year the game was released: ";
			cin >> year;
			cout << "Enter the name of the studio that produced the game: ";
			getline(cin, studio);
			Video_Game vg{ year, studio };
			video_game = vg;
		}
	}
// Complete movie information
	if (g == "Movie")
	{
		if (t == "The Godfather")
		{
			vector<string> leading_actors{ "Marlon Brando", "Al Pacino", "James Caan" };
			Movie m{ 1972, "Albert S. Ruddy", "Francis Ford Coppola", leading_actors };
			movie = m;
		}
		else if (t == "The Shawshank Redemption")
		{
			vector<string> leading_actors{ "Tim Robbins", "Morgan Freeman", "Bob Gunton" };
			Movie m{ 1994, "Niki Marvin", "Frank Darabont", leading_actors };
			movie = m;
		}
		else if (t == "Forrest Gump")
		{
			vector<string> leading_actors{ "Tom Hanks", "Robin Wright", "Gary Sinise" };
			Movie m{ 1994, "Steve Tisch", "Robert Zemeckis", leading_actors };
			movie = m;
		}
		else if (t == "Gladiator")
		{
			vector<string> leading_actors{ "Russell Crowe", "Joaquin Phoenix", "Connie Nielsen" };
			Movie m{ 2000, "David Franzoni", "Ridley Scott", leading_actors };
			movie = m;
		}
		else if (t == "Titanic")
		{
			vector<string> leading_actors{ "Leonardo DiCaprio", "Kate Winslet", "Billy Zane" };
			Movie m{ 1997, "Jon Landau", "James Cameron", leading_actors };
			movie = m;
		}
		else
		{
			cout << "Enter the year the movie was released: ";
			cin >> year;
			cout << "Enter the name of the producer: ";
			getline(cin, producer);
			cout << "Enter the name of the director: ";
			getline(cin, director);
			cout << "Enter the name of 3 leading actors in the movie:" << endl;
			for (int i = 0; i < 3; i++)
			{
				cout << i + 1 << ". ";
				getline(cin, actor);
				la.push_back(actor);
				actor = "";
			}
			Movie m{ year, producer, director, la };
			movie = m;
		}
	}
// Complete book information
	if (g == "Book")
	{
		if (t == "To Kill a Mockingbird")
		{
			Book b{ "Harper Lee", 1960 };
			book = b;
		}
		else if (t == "Adventures of Huckleberry Finn")
		{
			Book b{ "Mark Twain", 1884 };
			book = b;
		}
		else if (t == "Moby Dick")
		{
			Book b{ "Herman Melville", 1851 };
			book = b;
		}
		else if (t == "Odyssey")
		{
			Book b{ "Homer", 725 };
			book = b;
		}
		else if (t == "Oliver Twist")
		{
			Book b{ "Charles Dickens", 1838 };
			book = b;
		}
		else
		{
			cin.ignore();
			cout << "Enter the name of the author: ";
			getline(cin, author);
			cout << "Enter the copyright year: ";
			cin >> year;
			Book b{ author, year };
			book = b;
		}
	}
}

int Media::get_id_number()
{
	return id_number;
}

string Media::get_title()
{
	return title;
}

string Media::get_genre()
{
	return genre;
}

void Media::set_check(bool b)
{
	checked_out = b;
}

Book Media::get_book()
{
	return book;
}

Movie Media::get_movie()
{
	return movie;
}

Music_Album Media::get_music_album()
{
	return music_album;
}

Television_Show_Season Media::get_television_show_season()
{
	return television_show_season;
}

Video_Game Media::get_video_game()
{
	return video_game;
}

bool Media::get_checked_out()
{
	return checked_out;
}