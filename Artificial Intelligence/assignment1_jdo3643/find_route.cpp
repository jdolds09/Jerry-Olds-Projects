#include "node.h"

int main(int argc, char *argv[])
{
// Variables
	vector<Node> nodes;
	vector<Node> fringe;
	vector<string> path;
	vector<string> best_path;
	vector<string> successors;
	vector<string> nodes_generated;
	vector<int> costs;
	vector<int> h_costs;
	vector<int> path_costs;
	string origin = argv[2];
	string destination = argv[3];
	string h_city;
	string city1;
	string city2;	
	bool found = false;
	bool path_exists = false;
	bool best_path_found = false;
	int cost;
	int accumulative_cost = 0;
	int count = 0;
	int counter = 0;
	int nodes_expanded = 0;
	unsigned int max_nodes = 0;
	unsigned int i;

// Input file
	ifstream input_file;
	input_file.open(argv[1]);

// Check if input file failed to open
	if(!input_file)
	{
		cerr << "Unable to open file. Make sure that input file is the second command line argument.";
		exit(1);
	}

// Read node information from file
	while(input_file >> city1)
	{
		if(city1 == "END")
			break;		

		input_file >> city2;
		input_file >> cost;
		
	// Check if source exists and add successor and cost
		for(i = 0; i < nodes.size(); i++)
			if(nodes[i].get_name() == city1)
			{	
				found = true;
				break;
			}

		if(found)
		{
			nodes[i].set_successor(city2);
			nodes[i].set_cost(cost);
		}

		else
		{	
			Node node;
			node.set_name(city1);
			node.set_successor(city2);
			node.set_cost(cost);
			nodes.push_back(node);
		}

		found = false;

	// Check if destination exists and add successor and cost
		for(i = 0; i < nodes.size(); i++)
			if(nodes[i].get_name() == city2)
			{	
				found = true;
				break;
			}

		if(found)
		{
			nodes[i].set_successor(city1);
			nodes[i].set_cost(cost);
		}
		
		else
		{
			Node node;
			node.set_name(city2);
			node.set_successor(city1);
			node.set_cost(cost);
			nodes.push_back(node);			
		}

		found = false;
	}

// Close file
	input_file.close();

// Uninformed Search
	if(argc == 4)
	{
	// Insert origin city in to fringe
		for(i = 0; i < nodes.size(); i++)
			if(nodes[i].get_name() == origin)
			{	
				found = true;
				break;
			}		
		fringe.push_back(nodes[i]);
	
	// Uniform cost algorithm
		while(!path_exists)
		{
		// Update path
			path.push_back(fringe[0].get_name());
			if(!best_path_found)
			{
				if(best_path.size() > 1 && fringe[0].get_name() == best_path[0])
					best_path.clear();
				best_path.push_back(fringe[0].get_name());
			}
		
		// Update max nodes in memory
			if(fringe.size() > max_nodes)
				max_nodes = fringe.size();
		
		// No path exists
			if(fringe.size() == 0)
				break;
		
		// Check if first node in fringe is destination
			if(fringe[0].get_name() == destination)
			{
				path.push_back(fringe[0].get_name());
				path_exists = true;
				break;
			}
	
		// Get successors and cost of node that will be expanded if possible
			successors = fringe[0].get_successors();
			costs = fringe[0].get_costs();
			
		// Sort costs and successors
			for(unsigned int j = 0; j < costs.size() - 1; j++)
				for(unsigned int k = 0; k < costs.size()-j-1; k++)
					if(costs[k] > costs[k+1])
					{
						int temp = costs[k];
						costs.erase(costs.begin() + k);
						costs.insert(costs.begin() + (k+1), temp);
						string temp2 = successors[k];
						successors.erase(successors.begin() + k);
						successors.insert(successors.begin() + (k+1), temp2);
					}

		// Get rid of nodes that have already been visited
			for(unsigned int j = 0; j < successors.size(); j++)
				for(unsigned int k = 0; k < path.size(); k++)
				{
					if(successors[j] == path[k])
					{
						count++;
						successors.erase(successors.begin()+j);
						successors.push_back("");
						costs.erase(costs.begin()+j);
						costs.push_back(-1);
						k = 0;
					}
				}

			while(count != 0)
			{
				successors.pop_back();
				costs.pop_back();
				count--;
			}

		// Update nodes expanded, nodes generated, and check if any successors is destination
			if(successors.size() > 0)
			{
				nodes_expanded++;
			// Nodes generated				
				for(unsigned int j = 0; j < successors.size(); j++)
				{
					for(unsigned int k = 0; k < nodes_generated.size(); k++)
						if(successors[j] == nodes_generated[k])
							found = true;
					if(!found)
						nodes_generated.push_back(successors[j]);
					found = false;
				}
			// Check to see if a successor is a destination
				for(unsigned int j = 0; j < successors.size(); j++)
					if(successors[j] == destination && best_path[best_path.size()-1] != destination)
					{
						best_path.push_back(successors[j]);
						best_path_found = true;
					}
			// Check to see if a successor is a successor of destination
				if(!best_path_found)
				{
				for(i = 0; i < nodes.size(); i++)
					if(destination == nodes[i].get_name())
						break;
				
				for(unsigned int j = 0; j < successors.size(); j++)
					for(unsigned int k = 0; k < nodes[i].get_successors().size(); k++)
						if(successors[j] == nodes[i].get_successors()[k])
						{
							best_path.push_back(successors[j]);
							best_path_found = true;
						}
				}
			}

		// When path reaches dead end and reverts to previous node, set path back to that node
			else
			{	
				if(!best_path_found)
					best_path.pop_back();
			}

		// Insert nodes in to fringe
			for(unsigned int j = 0; j < successors.size(); j++)
				for(unsigned int k = 0; k < nodes.size(); k++)
					if(successors[j] == nodes[k].get_name())
						fringe.insert(fringe.begin()+j, nodes[k]);
		
		// Remove node that was expanded 
			fringe.erase(fringe.begin() + successors.size());
		
		// Clear vectors
			successors.clear();
			costs.clear();
		}

	// Calculate costs
		for(unsigned int j = 1; j < best_path.size(); j++)
		{
			for(unsigned int k = 0; k < nodes.size(); k++)
				if(best_path[j-1] == nodes[k].get_name())
				{
					for(unsigned int c = 0; c < nodes[k].get_successors().size(); c++)
						if(best_path[j] == nodes[k].get_successors()[c])
						{
							path_costs.push_back(nodes[k].get_costs()[c]);
							accumulative_cost += nodes[k].get_costs()[c];
						}
				}
		}
				
	// Display results
		cout << "\nNodes Expanded: " << nodes_expanded << endl;
		cout << "Nodes Generated: " << nodes_generated.size() << endl;
		cout << "Max Nodes in Memory: " << max_nodes << endl;
		if(path_exists)
			cout << "Distance: " << accumulative_cost << ".0 km" << endl;
		else
			cout << "Distance: infinity" << endl;
		cout << "Route:" << endl;
	// If a path exists from origin to destination		
		if(path_exists)
		{
			for(unsigned int j = 1; j < best_path.size(); j++)
				cout << best_path[j-1] << " to " << best_path[j] << ", " << path_costs[j-1] << ".0 km" << endl;
		}
	// If no path exists from origin to destination
		else
			cout << "None" << endl;
	}

// Informed Search
	else if(argc == 5)
	{
	// Heuristic file
		ifstream h_file;
		h_file.open("h_kassel.txt");

	// Read heuristic values
		while(h_file >> h_city)
		{
			if(h_city != "END")
			{
				for(unsigned int j = 0; j < nodes.size(); j++)
				{
					if(h_city == nodes[j].get_name())
					{
						h_file >> cost;
						nodes[j].set_h_value(cost);
						h_city = "";
						break;
					}
				}
			}
		}

	// Insert origin city in to fringe
		for(i = 0; i < nodes.size(); i++)
			if(nodes[i].get_name() == origin)
			{	
				found = true;
				break;
			}		
		fringe.push_back(nodes[i]);
		best_path.push_back(fringe[0].get_name());
		found = false;

	// A* Search
		while(!path_exists)
		{
		// Update path
			path.push_back(fringe[0].get_name());
		
		// Update max nodes in memory
			if(fringe.size() > max_nodes)
				max_nodes = fringe.size();
		
		// No path exists
			if(fringe.size() == 0)
				break;
		
		// Check if first node in fringe is destination
			if(fringe[0].get_name() == destination)
			{
				path.push_back(fringe[0].get_name());
				path_exists = true;
				break;
			}
	
		// Get successors and cost of node that will be expanded if possible
			successors = fringe[0].get_successors();
			costs = fringe[0].get_costs();

		// Get rid of nodes that have already been visited
			for(unsigned int j = 0; j < successors.size(); j++)
				for(unsigned int k = 0; k < path.size(); k++)
				{
					if(successors[j] == path[k])
					{
						count++;
						successors.erase(successors.begin()+j);
						successors.push_back("");
						costs.erase(costs.begin()+j);
						costs.push_back(-1);
						k = 0;
					}
				}
			
			while(count != 0)
			{
				successors.pop_back();
				costs.pop_back();
				count--;
			}
		// Add hueristic values to costs
			for(unsigned int j = 0; j < successors.size(); j++)
				for(unsigned int k = 0; k < nodes.size(); k++)
					if(successors[j] == nodes[k].get_name())
						costs[j] += nodes[k].get_h_value();

		// Update nodes expanded and generated
			if(successors.size() > 0)
			{
				nodes_expanded++;
			// Nodes generated				
				for(unsigned int j = 0; j < successors.size(); j++)
				{
					for(unsigned int k = 0; k < nodes_generated.size(); k++)
						if(successors[j] == nodes_generated[k])
							found = true;
					if(!found)
						nodes_generated.push_back(successors[j]);
					found = false;

			// Check to see if any successors is destination
					for(unsigned int j = 0; j < successors.size(); j++)
					if(successors[j] == destination && best_path[best_path.size()-1] != destination)
					{
						best_path.push_back(successors[j]);
						best_path_found = true;
					}
				}
			}

			else
				if(!best_path_found)
					best_path.pop_back();

		// Insert nodes in to fringe
			for(unsigned int j = 0; j < successors.size(); j++)
				for(unsigned int k = 0; k < nodes.size(); k++)
					if(successors[j] == nodes[k].get_name())
						fringe.insert(fringe.begin()+j, nodes[k]);

		// Remove node that was expanded 
			fringe.erase(fringe.begin() + successors.size());

		// Get rid of hueristic value associated with expanded none
				if(h_costs.size() > 0)
					h_costs.erase(h_costs.begin());

		// 	Hueristic values of nodes in fringe	
			h_costs.insert(h_costs.end(), costs.begin(), costs.end());
	
		// Sort costs and successors
			if(fringe.size() > 1)
			{
			for(unsigned int j = 0; j < h_costs.size() - 1; j++)
				for(unsigned int k = 0; k < h_costs.size()-j-1; k++)
					if(h_costs[k] > h_costs[k+1])
					{
						int temp = h_costs[k];
						h_costs.erase(h_costs.begin() + k);
						h_costs.insert(h_costs.begin() + (k+1), temp);
						Node temp2 = fringe[k];
						fringe.erase(fringe.begin() + k);
						fringe.insert(fringe.begin() + (k+1), temp2);
					}
			}

		// Clear vectors
			successors.clear();
			costs.clear();

		// Update path
			if(!best_path_found)
			{
				successors = fringe[0].get_successors();
				for(unsigned int j = (best_path.size() - 1); j > 0; j--)
				{
					for(unsigned int k = 0; k < successors.size(); k++)
						if(best_path[j] == successors[k])
							found = true;
					if(!found)
						counter++;
				}
			
				if(counter == 0)
					best_path.push_back(fringe[0].get_name());
				else
				{
					if(!found)
						best_path.push_back(fringe[0].get_name());
					else
					{
						while(counter != 0)
						{
							best_path.pop_back();
							counter--;
						}
						best_path.push_back(fringe[0].get_name());
					}
				}
				found = false;
			}
		
		// Clear vectors
			successors.clear();
			costs.clear();
		}

	// Calculate costs
		for(unsigned int j = 1; j < best_path.size(); j++)
		{
			for(unsigned int k = 0; k < nodes.size(); k++)
				if(best_path[j-1] == nodes[k].get_name())
				{
					for(unsigned int c = 0; c < nodes[k].get_successors().size(); c++)
						if(best_path[j] == nodes[k].get_successors()[c])
						{
							path_costs.push_back(nodes[k].get_costs()[c]);
							accumulative_cost += nodes[k].get_costs()[c];
						}
				}
		}
				
	// Display results
		cout << "\nNodes Expanded: " << nodes_expanded << endl;
		cout << "Nodes Generated: " << nodes_generated.size() << endl;
		cout << "Max Nodes in Memory: " << max_nodes << endl;
		if(path_exists)
			cout << "Distance: " << accumulative_cost << ".0 km" << endl;
		else
			cout << "Distance: infinity" << endl;
		cout << "Route:" << endl;
	// If a path exists from origin to destination		
		if(path_exists)
		{
			for(unsigned int j = 1; j < best_path.size(); j++)
				cout << best_path[j-1] << " to " << best_path[j] << ", " << path_costs[j-1] << ".0 km" << endl;
		}
	// If no path exists from origin to destination
		else
			cout << "None" << endl;
			
	}

// Invalid number of command line arguments entered
	else
		cout << "Invalid number of arguments." << endl;


// End of program
	return 0;
}
