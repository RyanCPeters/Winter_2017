/**
* A graph is made up of vertices and edges
* A vertex can be connected to other vertices via weighted, directed edge
*/

#ifndef GRAPH_H
#define GRAPH_H

#include <map>
#include <string>
#include <queue>
#include <climits>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <memory>
#include <utility>

#include "vertex.h"
#include "edge.h"

class Graph {
public:
	/** constructor, empty graph */
	Graph();

	/** destructor, delete all vertices and edges
	only vertices stored in map
	no pointers to edges created by graph */
	~Graph();

	/** return number of vertices */
	int getNumVertices() const;

	/** return number of vertices */
	int getNumEdges() const;

	/** add a new edge between start and end vertex
	if the vertices do not exist, create them
	calls Vertex::connect
	a vertex cannot connect to itself
	or have multiple edges to another vertex */
	bool add(const std::string &start, const std::string &end,
             const int &edgeWeight = 0);

	/** return weight of the edge between start and end
	returns INT_MAX if not connected or vertices don't exist */
	int getEdgeWeight(const std::string& start, const std::string& end) const;

	/** read edges from file
	the first line of the file is an integer, indicating number of edges
	each edge line is in the form of "string string int"
	fromVertex  toVertex    edgeWeight */
	void readFile(std::string filename);

	/** depth-first traversal starting from startLabel
	call the function visit on each vertex label */
	void depthFirstTraversal(std::string startLabel,
							 void visit(const std::string&));

	/** breadth-first traversal starting from startLabel
	call the function visit on each vertex label */
	void breadthFirstTraversal(std::string startLabel,
							   void visit(const std::string&));

	/** find the lowest cost from startLabel to all vertices that can be reached
	using Djikstra's shortest-path algorithm
	record costs in the given map weight
	weight["F"] = 10 indicates the cost to get to "F" is 10
	record the shortest path to each vertex using given map previous
	previous["F"] = "C" indicates get to "F" via "C"

	cpplint gives warning to use pointer instead of a non-const map
	which I am ignoring for readability */
	void djikstraCostToAllVertices(
		std::string startLabel,
		std::map<std::string, int>& weight,
		std::map<std::string, std::string>& previous);

private:
	/** number of vertices in graph */
	int numberOfVertices;

	/** number of edges in graph */
	int numberOfEdges;
	
	/** mapping from vertex label to vertex pointer for quick access */
	std::map<std::string, std::shared_ptr<Vertex>> vertices;

	/** find a vertex, if it does not exist return nullptr */
    Vertex findVertex(const std::string &vertexLabel);

	/** find a vertex, if it does not exist create it and return it */
    Vertex * findOrCreateVertex(const std::string &vertexLabel);
    void unvisitAll();
};  // end Graph


#endif  // GRAPH_H
