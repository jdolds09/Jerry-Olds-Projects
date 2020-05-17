#include "jdo3643_Music_Album.h"

Music_Album::Music_Album()
{

}

Music_Album::Music_Album(int ry, string a, vector<string> t)
{
	release_year = ry;
	artist = a;
	tracks = t;
}

int Music_Album::get_year()
{
	return release_year;
}

string Music_Album::get_artist()
{
	return artist;
}

vector<string> Music_Album::get_tracks()
{
	return tracks;
}