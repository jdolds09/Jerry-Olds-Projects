// Author: Jerry Olds
// Date of completion: 12/17/2018

#include "/home/student/Desktop/Baseball_Project/header/Player.h"

// Function prototype
void output_data(vector<Player> p);

int main()
{ 
// Variables
    vector<Player> players;
    bool valid = true;
// Create file variable and open input file for reading
    ifstream inFile; 
    inFile.open("/home/student/Desktop/Baseball_Project/input/290stats.txt"); 

// Read data from input file
    do
    {
    // Player variables
        string first_name;
        string last_name;
        string team;
        string batting_average;
        int games_played = 0;
        int zero_hits = 0;
        char hits;
        bool valid2 = true;
    
    // Read in data to player variables
        inFile >> first_name;
        if(first_name == "x")
            valid = false;
        else
        {
		    inFile >> last_name;
		    inFile >> team;
		    inFile >> batting_average;

		// Create Player object
		    Player player(first_name, last_name, team, batting_average);

		// Count how many games played and how many times the player got 0 hits
		    while(valid2)
		    {
		        inFile >> hits;
		        if(hits == '|')
		            valid2 = false;
		        else
		        {
		            if(hits == '0')
		                zero_hits++;
		            games_played++;
		        }
		    }
		    
		// Send data to Player class
		    player.set_games_played(games_played);
		    player.set_zero_hits(zero_hits);
	  
		// Add Player object to vector
		    players.push_back(player);
        }
    }while(valid);

// Close file
    inFile.close();

// Output data
    output_data(players);

// End of program
    return 0;
}

void output_data(vector<Player> p)
{
// Variables
    Player douche;
    vector<Player> douches;
    int most_ofers = 0;
    int max_name_size = 22;
    int max_team_name = 8;
    string bar = "---------------------------------------------------------";
    string table = R"(
---------------------------------------------------------
|       Player         | Team    |  G  |  AVG |  O'fers  |
---------------------------------------------------------)";

// Output table
    cout << table << endl;

// Output each player's data
    for(unsigned int i = 0; i < p.size(); i++)
    {
    // Variables
        int name_size;
        int spaces;
    
    // Output player name
        cout << "|";
        cout << p[i].get_first_name() << " " << p[i].get_last_name();
        name_size = p[i].get_first_name().size() + p[i].get_last_name().size() + 1;
        spaces = max_name_size - name_size;
        for(int j = 0; j < spaces; j++)
            cout << " ";
        cout << "| ";

    // Output player team
        cout << p[i].get_team();
        spaces = max_team_name - p[i].get_team().size();
        for(int j = 0; j < spaces; j++)
            cout << " ";
        cout << "| ";

    // Output games played in which the player registered an offical at-bat
        cout << p[i].get_games_played() << " | ";

    // Output player batting average
        cout << p[i].get_batting_average() << " |    ";

    // Output the number of times the player got 0 hits in a game with atleast 1 offical at-bat
        if(p[i].get_zero_hits() < 10)
            cout << "0" << p[i].get_zero_hits() << "    |" << endl;
        else
            cout << p[i].get_zero_hits() << "    |" << endl;
    
    // Output bottom bar
        cout << bar << endl;

    // Determine player with most games with 0 hits
        if(p[i].get_zero_hits() == most_ofers)
        {
            if(douches.size() >= 2)
                douches.push_back(p[i]);
            else
            {
                douches.push_back(douche);
                douches.push_back(p[i]);
            }
        }
        
        if(p[i].get_zero_hits() > most_ofers)
        {
            most_ofers = p[i].get_zero_hits();
            douches.clear();
            douche = p[i];
        }   
    }

// Output result
    if(douches.size() > 0)
    {
        cout << "The douches with the most O'fers are ";
        for(unsigned int i = 0; i < douches.size(); i++)
        {
            if(i == douches.size() - 2)
                cout << douches[i].get_first_name() << " " << douches[i].get_last_name() << " and ";
            if(i == douches.size() - 1)
                cout << douches[i].get_first_name() << " " << douches[i].get_last_name() << " with " << douches[i].get_zero_hits() 
                     << " O'fers." << endl << endl;
            else
                cout << douches[i].get_first_name() << " " << douches[i].get_last_name() << ", ";
        }
    }

    else
        cout << "The douche with the most 0'fers is " << douche.get_first_name() << " " 
             << douche.get_last_name() << " with " << douche.get_zero_hits() << " O'fers." << endl << endl;  
}
