#ifndef JDO3643_MOVIE_H
#define JDO3643_MOVIE_H

#include <iostream>
#include <vector>
using namespace std;

class Movie
{
private:
	int release_year;
	string producer;
	string director;
	vector<string> leading_actors;
public:
	Movie(int ry, string p, string d, vector<string> la);
};

#endif