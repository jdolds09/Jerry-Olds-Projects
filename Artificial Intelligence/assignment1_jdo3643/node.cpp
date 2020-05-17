#include "node.h"

// Empty constructor
Node::Node()
{}

// Setters
void Node::set_name(string n)
{
	name = n;
}

void Node::set_successor(string s)
{
	successors.push_back(s);
}

void Node::set_cost(int c)
{
	costs.push_back(c);
}

void Node::set_h_value(int h)
{
	h_value = h;
}

// Getters
string Node::get_name()
{
	return name;
}

vector<string> Node::get_successors()
{
	return successors; 
}

vector<int> Node::get_costs()
{
	return costs;
}

int Node::get_h_value()
{
	return h_value;
}
