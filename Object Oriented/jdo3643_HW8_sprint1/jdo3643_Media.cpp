#include "jdo3643_Media.h"

Media::Media(int id, string cn, string t, string g)
{
	id_number = id;
	call_number = cn;
	title = t;
	genre = g;
	media_information(genre);
	checked_out = false;
}

void Media::media_information(string g)
{
	if (g == "Television Show Season")
		Television_Show_Season tss{ 2017, "David Benioff", {"David Nutter", "Miguel Sapochnik", "David Benioff", "D.B Weiss"}, {"Emilia Clarke", "Kit Harington", "Lena Headey", "Peter Dinklage"}, 7 };
	if (g == "Music_Album")
		Music_Album ma{ 1982, "Michael Jackson", {"The Girl is Mine", "Billie Jean", "Beat it", "Wanna Be Startin' Somethin", "Human Nature", "P.Y.T", "Thriller"} };
	if (g == "Video Game")
		Video_Game vg{ 2003, "Bioware" };
	if (g == "Movie")
		Movie m{ 1993, "Dale De La Torre", "David Mickey Evans", {"Tom Guiry", "Mike Vitar", "Patrick Renna"} };
	if (g == "Book")
		Book b{ "Mark Twain", 1884 };
}

int Media::get_id_number()
{
	return id_number;
}