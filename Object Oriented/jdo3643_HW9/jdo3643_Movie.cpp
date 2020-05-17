#include "jdo3643_Movie.h"

Movie::Movie()
{

}

Movie::Movie(int ry, string p, string d, vector<string> la)
{
	release_year = ry;
	producer = p;
	director = d;
	leading_actors = la;
}

int Movie::get_year()
{
	return release_year;
}

string Movie::get_producer()
{
	return producer;
}

string Movie::get_director()
{
	return director;
}

vector<string> Movie::get_actors()
{
	return leading_actors;
}