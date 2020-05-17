// Jerry Olds
// 1001533643
// CSE-4344-001
// Project 2

// REFERENCE: https://github.com/ppartarr/pyRoute/blob/master/network.py

from tkinter import *
import networkx as nx

# This class sets the intial distances to nodes and sets non_adjacent nodes values to inf
# also has a function to update distances between nodes
class DistanceVectorTable:
    def __init__(self, node):
        self.name = node
        self.distance_vector_table = {adj_node:graph.adj[node][adj_node]['weight'] for adj_node in graph.adj[node]}
        non_adjacent_nodes = list(set(graph.nodes) - set(graph.adj[node]) - set(node))
        self.distance_vector_table.update({non_adjacent_node: float('inf') for non_adjacent_node in non_adjacent_nodes})
        self.distance_vector_table[node] = 0

    def update_edge(self, dest, cost):
        self.distance_vector_table.update({dest: cost})

# Bellman Ford algorithm to find shortest route between to nodes
def bellman_ford(stable):
    for node in graph.nodes:
        for adj_node in graph.adj[node]:
            adj_node_table = graph.nodes[adj_node]['distance_vector_table'].distance_vector_table
            dist_to_adj = graph.nodes[node]['distance_vector_table'].distance_vector_table[adj_node] # Get distance to adjacent nodes
            for dest in adj_node_table:
                dist_to_dest = graph.nodes[node]['distance_vector_table'].distance_vector_table[dest] # Get distance to destination node
                adj_dist_to_dest = adj_node_table[dest]
                
                # Choose minimum between distance to adjacent node then destination or distance straight to destination
                new_dist = min(dist_to_adj + adj_dist_to_dest, dist_to_dest)
                # If there are no changes after full run through Bellman Ford algorithm, system is stable  
                if(new_dist != dist_to_dest):
                    stable = False
                graph.nodes[node]['distance_vector_table'].update_edge(dest, new_dist)
    return stable

def run_with_intervention(graph):
    step = 0
    window = 0
    display = [None] * (int((len(graph.nodes) / 3)) + 1) # Data in windows gets too long, break up into multiple GUI windows
    display[window] = Tk()
    cycle = Label(display[window], text = "------ CYCLE " + str(step) + " ------") 
    cycle.pack()

    # Display initial distances between nodes
    for node in graph.nodes:
        distance_vector_table = graph.nodes[node]['distance_vector_table'].distance_vector_table
        node = Label(display[window], text = node)
        node.pack()
        table = Label(display[window], text = distance_vector_table)
        table.pack()
    step = step + 1

    # Find shortest distances between nodes
    for i in range(len(graph.nodes) - 1):
        stable = True
        stable = bellman_ford(stable)
        #If system is stable, display that system is stable and break out of loop
        if stable == True: 
            stabilize = Label(display[window], text = "System is stable")
            stabilize.pack()
            break

        # Create new window if data is getting too long
        if i > 1 and i % 2 == 0:
            window = window + 1
            display[window] = Tk()

        # Display the cycle number of Bellman Ford algorithm 
        cycle = Label(display[window], text = "------ CYCLE " + str(step) + " ------")
        cycle.pack()

        #Display data
        for node in graph.nodes:
            distance_vector_table = graph.nodes[node]['distance_vector_table'].distance_vector_table
            node = Label(display[window], text = node)
            node.pack()
            table = Label(display[window], text = distance_vector_table)
            table.pack()

        #Increase Bellman Ford cycle number    
        step = step + 1

def run_without_intervention(graph):
    display = Tk()

    #Set timer on Bellman Ford algorithm
    import time
    t = time.time()
    stable = True
    for i in range(len(graph.nodes) - 1):
        bellman_ford(stable)
    elapsed = time.time() - t

    #Display data
    for node in graph.nodes:
        distance_vector_table = graph.nodes[node]['distance_vector_table'].distance_vector_table
        node = Label(display, text = node)
        node.pack()
        table = Label(display, text = distance_vector_table)
        table.pack()
    time = Label(display, text = "Time: " + str(elapsed) + " seconds")
    time.pack()

# Read data from file
infile = open("input.txt", "r")
vertex = []
nodes = []
edges = []
count = 0

for line in infile:
    for c in line:
        if c == ' ' or c == '\n':
            pass
        else:
            count = count + 1
            vertex.append(c)
            if c not in nodes and count % 3 != 0:
                nodes.append(c)
            if count % 3 == 0:
                edges.append((vertex[len(vertex)-3], vertex[len(vertex)-2], {'weight': float(vertex[len(vertex)-1])}))
                count = count - 3

infile.close()

# Create graph from data read from file
graph = nx.Graph()
graph.add_nodes_from(nodes)
graph.add_edges_from(edges)

# Send values to class
for node in graph.nodes:
    graph.nodes[node]['distance_vector_table'] = DistanceVectorTable(node)


# Create initial GUI
gui = Tk()

intervention_run_button = Button(gui, text = "Run with intervention", command = lambda: run_with_intervention(graph))
intervention_run_button.pack()
no_intervention_run_button = Button(gui, text = "Run without intervention", command = lambda: run_without_intervention(graph))
no_intervention_run_button.pack()

gui.mainloop()