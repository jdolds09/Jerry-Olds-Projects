// Author: Jerry Olds
// Date of completion: 12/17/2018

#ifndef HEADER_PLAYER_H_
#define HEADER_PLAYER_H_

#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Player
{
  private:
    string first_name;
    string last_name;
    string team;
    string batting_average;
	int games_played;
    int zero_hits;

  public:
// Default empty constructor
    Player();

// Constructor
    Player(string fn, string ln, string t, string ba);

// Setters
    void set_games_played(int gp);
    void set_zero_hits(int zh);

// Getters
    string get_first_name();
    string get_last_name();
    string get_team();
    string get_batting_average();
    int get_games_played();
    int get_zero_hits();

};

#endif
