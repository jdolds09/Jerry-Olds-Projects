#ifndef JDO3643_VIDEO_GAME_H
#define JDO3643_VIDEO_GAME_H

#include <iostream>
using namespace std;

class Video_Game
{
private:
	int release_year;
	string studio;
public:
	Video_Game();
	Video_Game(int ry, string s);
	int get_year();
	string get_studio();
};

#endif