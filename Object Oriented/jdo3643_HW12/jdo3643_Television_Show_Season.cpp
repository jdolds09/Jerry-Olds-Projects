#include "jdo3643_Television_Show_Season.h"

Television_Show_Season::Television_Show_Season()
{

}

Television_Show_Season::Television_Show_Season(int ry, string p, vector<string> d, vector<string> la, int s)
{
	release_year = ry;
	producer = p;
	directors = d;
	leading_actors = la;
	season_number = s;
}

int Television_Show_Season::get_year()
{
	return release_year;
}

string Television_Show_Season::get_producer()
{
	return producer;
}

vector<string> Television_Show_Season::get_directors()
{
	return directors;
}

vector<string> Television_Show_Season::get_actors()
{
	return leading_actors;
}

int Television_Show_Season::get_season_num()
{
	return season_number;
}