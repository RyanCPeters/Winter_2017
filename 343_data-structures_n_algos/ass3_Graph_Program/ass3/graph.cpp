#include <queue>
#include <climits>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>

#include "graph.h"

/**
* A graph is made up of vertices and edges
* A vertex can be connected to other vertices via weighted, directed edge
*/


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


/** constructor, empty graph */
Graph::Graph(): numberOfVertices(0), numberOfEdges(0),vertices() {}

/** destructor, delete all vertices and edges
only vertices stored in map
no pointers to edges created by graph */
Graph::~Graph() {
    vertices.clear();
}

/** return number of vertices */
int Graph::getNumVertices() const 
{ return numberOfVertices; }

/** return number of vertices */
int Graph::getNumEdges() const 
{ return numberOfEdges; }

/** add a new edge between start and end vertex
if the vertices do not exist, create them
calls Vertex::connect
a vertex cannot connect to itself
nor have multiple edges connecting to another singular vertex */
bool Graph::add(const std::string& start, const std::string& end,
                const int& edgeWeight)
{
    // we are going to first create a pointer to the vertex that has the
    // value store in `start` as its vertexLabel.
    auto vPtr = findOrCreateVertex(start);
    // next we ensure that end is stored in the vertices map
    findOrCreateVertex(end);

    // we now establish the edge connection between the two vertices via that
    // Vertex pointer we made.
    return vPtr->connect(end, edgeWeight);

    // we don't need to worry about deleting our pointer, as the data being
    // stored at its pointed memory address is managed by the vertices map.
    // vPtr itself will be deleted, non-recursively,  upon the end of the
    // function's scope.
} // end of add function (here is where vPtr dies)

/** return weight of the edge between start and end
returns INT_MAX if not connected or vertices don't exist */
int Graph::getEdgeWeight(const std::string& start,const std::string& end)const
{
    auto iter = vertices.find(start);
    if(iter == vertices.end())return INT_MAX;
    int ret = iter->second->getEdgeWeight(end);
    return (ret >= 0)? ret : INT_MAX;
}

/** read edges from file
the first line of the file is an integer, indicating number of edges
each edge line is in the form of "string string int"
fromVertex  toVertex    edgeWeight */
void Graph::readFile(std::string filename) 
{
    std::ifstream ifile;
    filename = "..\\" + filename;
    ifile.open(filename);
    if(!ifile.is_open()){
        std::cerr << "shits B0rK3d!1!!1!one!! tried to read "
                "from file but it shit the bed" << std::endl;
        std::cerr << "\tWe were given the following file name to open: "
                  << filename << " but we obviosly didn't get it open..."
                  << std::endl;
    }
    int len = 0;
    ifile >> len;
    for(int i = 0; i < len; ++i){
        std::string start, end;
        int weight = 0;
        ifile >> start;
        ifile >> end;
        ifile >> weight;
        if( add(start,end,weight) )++numberOfEdges;
    }

    ifile.close();
}

/** depth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::depthFirstTraversal(std::string startLabel,
								void visit(const std::string&)) 
{
    // We use numberOfVertices%122 in order to generate
    void *trueRef = nullptr;
    auto iter = vertices.find(startLabel);
    if(iter == vertices.end())return; // this is more of an err state... but
                                      // we can deal with that later.
    std::stack<Vertex> stk;
    stk.push(*(iter->second));
    std::string curVtx = iter->first;
    while(curVtx != stk.top().getLabel()){
        // In the following `if` statement we need to check adjacent edges
        // of stk.top() against unvisited nodes in the vertices map.
        if(!(stk.top().isVisited(trueRef))){
            // pushing, in reverse alphabetical order, the vertices that we have
            // yet to visit.

        }
    }
    free(trueRef);

}

/** breadth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::breadthFirstTraversal(std::string startLabel,
								  void visit(const std::string&)) 
{}

/** find the lowest cost from startLabel to all vertices that can be reached
using Djikstra's shortest-path algorithm
record costs in the given map weight
weight["F"] = 10 indicates the cost to get to "F" is 10
record the shortest path to each vertex using given map previous
previous["F"] = "C" indicates get to "F" via "C"

cpplint gives warning to use pointer instead of a non-const map
which I am ignoring for readability */
void Graph::djikstraCostToAllVertices(
	std::string startLabel,
	std::map<std::string, int>& weight,
	std::map<std::string, std::string>& previous) {}

/** helper for depthFirstTraversal */
void Graph::depthFirstTraversalHelper(Vertex* startVertex,
									  void visit(const std::string&)) 
{}

/** helper for breadthFirstTraversal */
void Graph::breadthFirstTraversalHelper(Vertex*startVertex,
										void visit(const std::string&)) 
{}

/** mark all verticies as unvisited */
void Graph::unvisitVertices() {}

/** find a vertex, if it does not exist return nullptr */
Vertex* Graph::findVertex(const std::string& vertexLabel) const 
{ return nullptr; }

/** find a vertex, if it does not exist create it and return it */
Vertex* Graph::findOrCreateVertex(const std::string& vertexLabel) 
{
    if (vertices.count(vertexLabel) == 0) {
        ++numberOfVertices;
        /*in the following return statement, we are building a new Vertex* in
         * place in the vertices map, then we're getting the iterator for
         * that new vertex via .first, then we call ->second in order to
         * return the actual Vertex pointer*/
        return vertices.emplace( vertexLabel, new Vertex(vertexLabel))
                         .first->second;
    }
    return vertices.find(vertexLabel)->second;
}