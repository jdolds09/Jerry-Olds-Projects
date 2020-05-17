#include "jdo3643_Movie.h"

Movie::Movie(int ry, string p, string d, vector<string> la)
{
	release_year = ry;
	producer = p;
	director = d;
	leading_actors = la;
}