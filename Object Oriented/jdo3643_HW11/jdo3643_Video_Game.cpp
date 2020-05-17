#include "jdo3643_Video_Game.h"

Video_Game::Video_Game()
{

}

Video_Game::Video_Game(int ry, string s)
{
	release_year = ry;
	studio = s;
}

int Video_Game::get_year()
{
	return release_year;
}

string Video_Game::get_studio()
{
	return studio;
}