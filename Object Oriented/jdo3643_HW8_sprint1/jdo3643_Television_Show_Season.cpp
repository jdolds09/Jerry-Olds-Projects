#include "jdo3643_Television_Show_Season.h"

Television_Show_Season::Television_Show_Season(int ry, string p, vector<string> d, vector<string> la, int s)
{
	release_year = ry;
	producer = p;
	director = d;
	leading_actors = la;
	season_number = s;
}