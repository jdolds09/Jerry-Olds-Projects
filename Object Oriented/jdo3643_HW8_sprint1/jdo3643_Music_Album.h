#ifndef JDO3643_MUSIC_ALBUM
#define JDO3643_MUSIC_ALBUM

#include <iostream>
#include <vector>
using namespace std;

class Music_Album
{
private:
	int release_year;
	string artist;
	vector<string> tracks;
public:
	Music_Album(int ry, string a, vector<string> tracks);
};

#endif