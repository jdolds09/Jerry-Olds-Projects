#ifndef JDO3643_TELEVISION_SHOW_SEASON
#define JDO3643_TELEVISION_SHOW_SEASON

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Television_Show_Season
{
private:
	int release_year;
	string producer;
	vector<string> director;
	vector<string> leading_actors;
	int season_number;
public:
	Television_Show_Season(int ry, string p, vector<string> d, vector<string> la, int s);
};

#endif