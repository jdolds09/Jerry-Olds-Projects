// Author: Jerry Olds
// Date of completion: 12/17/2018

#include "/home/student/Desktop/Baseball_Project/header/Player.h"

// Default empty constructor
Player::Player() {}

// Constructor
Player::Player(string fn, string ln, string t, string ba)
{
    first_name = fn;
    last_name = ln;
    team = t;
    batting_average = ba;
}

// Setters
void Player::set_games_played(int gp)
{
    games_played = gp;
}

void Player::set_zero_hits(int zh)
{
    zero_hits = zh;
}

// Getters
string Player::get_first_name()
{
    return first_name;
}

string Player::get_last_name()
{
    return last_name;
}

string Player::get_team()
{
    return team;
}

string Player::get_batting_average()
{
    return batting_average;
}

int Player::get_games_played()
{
    return games_played;
}

int Player::get_zero_hits()
{
    return zero_hits;
}
