#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Node
{
	private:
		string name;
		vector<string> successors;
		vector<int> costs;
		int h_value;
	public:	
		Node();
	// Setters
		void set_name(string n);
		void set_successor(string s);
		void set_cost(int c);
		void set_h_value(int h);
	// Getters
		string get_name();
		vector<string> get_successors();
		vector<int> get_costs();
		int get_h_value();
};
