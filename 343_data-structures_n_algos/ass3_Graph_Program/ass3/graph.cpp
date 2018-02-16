#include <random>
#include <chrono>
#include <climits>
#include "graph.h"

/**
* A graph is made up of vertices and edges
* A vertex can be connected to other vertices via weighted, directed edge
 *
 * Assumptions:
 *  1) Time is linear and there is no spoon
*/


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


/** constructor, empty graph */
Graph::Graph(): numberOfVertices(0), numberOfEdges(0),vertices() {
    // creating void pointers that will point to random places in memory. Not
    // for the data saved in the memory, but to acquire random hex values at
    // low cost that we will later use as a control reference for marking
    // visited nodes as we perform different graph traversals.
    trueRefA = (uint8_t*)this+1;
    trueRefB = trueRefA+1;
    return;
}

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
    std::shared_ptr<Vertex> vPtr, endPtr;
    vPtr = findOrCreateVertex(start);
    // next we ensure that end is stored in the vertices map
    endPtr = findOrCreateVertex(end);

    // we now establish the edge connection between the two vertices via that
    // Vertex pointer we made.
    if(vPtr->connect(endPtr, edgeWeight)){
        ++numberOfEdges;
        return true;
    }
    return false;

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
//    filename = ".\\" + filename;
    ifile.open(filename);
    if(!ifile.is_open()){
        std::cerr << "B0rK3d!1!!1!one!! tried to read "
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
        add(start,end,weight);
    }
    ifile.close();
}

/** used with the private class level member variables trueRefA and trueRefB
 * in ensuring high probability of unique reference address for each traversal.
 *
 * Using code pulled from:
http://www.cplusplus.com/reference/random/uniform_int_distribution/operator%28%29/
 *
 * @return a random number from 1 to 7 that represents the offset that should
 * be used from the previous memory position.
 */
int Graph::generateRandomOffset() {

    auto seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine generator(seed);

    std::uniform_int_distribution<int> distribution(1, 7);
    return distribution(generator);
}

/** depth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::depthFirstTraversal(std::string startLabel,
								void visit(const std::string&)) 
{
    if (vertices.count(startLabel) == 0) {
        // the starting label isn't a part of this graph
        return; // so break out of function with an empty return.
    }
//    depthFirstTraversalHelper((findVertex(startLabel)), visit);
    auto startVertex = findVertex(startLabel);
    std::vector<std::weak_ptr<Vertex>> stk;
    stk.push_back(startVertex);
    
    // establishing the memory address we'll use later when checking if
    // vertices have been visited yet
    trueRefB = trueRefA+ generateRandomOffset();
    trueRefA += generateRandomOffset();
    auto* trueRef = trueRefB;
    
    while (!stk.empty()) {
        while(!stk.empty() && stk.back().lock()->isVisited(trueRef)){
            stk.pop_back();
        }
        if(stk.empty())break;
        auto vPtr = stk.back().lock();
        stk.pop_back();
        vPtr->visit(trueRef);
        vPtr->resetReverseNeighbor();
        std::unique_ptr<std::string> curVtx, nextVLabel;
        curVtx = std::make_unique<std::string>(vPtr->getLabel());
        visit(*curVtx);
        while (*curVtx != vPtr->reversePeekNextNeighbor()) {
            
            nextVLabel =
                    std::make_unique<std::string>(
                            vPtr->reverseGetNextNeighbor());
            
            std::weak_ptr<Vertex> item = vertices.find(*nextVLabel)->second;
            if(!(item.lock()->isVisited(trueRef))){
                stk.push_back(item.lock());
            }
        }
    }
}

/** breadth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::breadthFirstTraversal(std::string startLabel,
								  void visit(const std::string&)) 
{
    if (vertices.count(startLabel) == 0) {
        // the starting label isn't a part of this graph
        return; // so break out of function with an empty return.
    }
//    breadthFirstTraversalHelper((findVertex(startLabel)), visit);
    auto startVertex = findVertex(startLabel);
    std::queue<std::weak_ptr<Vertex>> qwayway;
    qwayway.push(startVertex);
    
    // establishing the memory address we'll use later when checking if
    // vertices have been visited yet
    trueRefB = trueRefA + generateRandomOffset();
    trueRefA += generateRandomOffset();
    auto *trueRef = trueRefB;
    
    
    qwayway.front().lock()->visit(trueRef);
    auto vPtr = qwayway.front().lock();
    while (!qwayway.empty()) {
        vPtr = qwayway.front().lock();
        qwayway.pop();
        vPtr->resetNeighbor();
        std::unique_ptr<std::string> curVtx, nextVLabel;
        curVtx = std::make_unique<std::string>(vPtr->getLabel());
        visit(*curVtx);
        std::string c = *curVtx;
        while (*curVtx != vPtr->peekNextNeighbor()) {
            nextVLabel = std::make_unique<std::string>(vPtr->getNextNeighbor());
            
            std::string d = *nextVLabel;
            std::weak_ptr<Vertex> item = vertices.find(*nextVLabel)->second;
            if (!(item.lock()->isVisited(trueRef))) {
                item.lock()->visit(trueRef);
                qwayway.push(item.lock());
            }
        }
    }
}

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
	std::map<std::string, std::string>& previous) {

    for(const auto &ele : vertices){
        if(ele.first != startLabel) {
            weight[ele.first] = INT_MAX;
            previous[ele.first] = "";
        }
    }

    /* A note about struct DijkstraData that's being used inside of pQwayway:
     *      This struct contains 2 string pointers and one ine pointer.
     *
     *      -- The first string pointer is for the vertex label that will be
     *      used to map us back to the corresponding Vertex object inside of
     *      our vertices map.
     *
     *      -- The second string pointer tracks the string used as the key
     *      inside of the map named "previous".
     *
     *      -- The int pointer tracks the accumulated weight for a given
     *      vertex's min cost inside of the map "weight".
     * */
    std::priority_queue<DijkstraData,
            std::vector<DijkstraData>, std::greater<>> pQwayway;

    bool noChangeToWeightMap = false;


    while(!noChangeToWeightMap) {
        noChangeToWeightMap = true;
        pQwayway.emplace(DijkstraData(startLabel));
        while (!pQwayway.empty()) {
// vPtr will be used to get the ajacent vertices that we will
// subsequently be adding to pQwayway.
            auto dijkPtr = pQwayway.top();
            pQwayway.pop();
            dijkPtr.weight = weight.find(dijkPtr.vert)->second;
            auto vPtr = vertices.find(dijkPtr.vert)->second;
            vPtr->resetNeighbor();
            int pathCost;
            while (vPtr->peekNextNeighbor() != dijkPtr.vert) {
                pathCost = weight.find(dijkPtr.vert)->second;
// neighborLabel will be used to get the cumulative weight along the path
// that has gotten us to the current vertex.
                std::string neighborLabel = (vPtr->getNextNeighbor());
                if(neighborLabel == startLabel)continue;
/*
 Regarding the following if blocks:

 we're going to set pathCost to be the sum of the edge from our current
 vertex location to the next adjacent neighbor plus the cumulative value of
 this path up to the mapped value for our vertex's "previous" counterpart
*/
                if(vPtr->getEdgeWeight(neighborLabel) > -1)
                    pathCost += getEdgeWeight(dijkPtr.vert, neighborLabel);
/*
  Now we begin the fun stuff!
  Because we are looking for the lowest cost paths to each vertex, we only
  want to update our maps and priority queue when the newly calculated
  pathCost is less than the current recorded cost for the destination vertex.
 */
                if(pathCost < weight[neighborLabel]){
                    noChangeToWeightMap = false;
                    
                    weight[neighborLabel] = pathCost;
                    previous[neighborLabel] = dijkPtr.vert;
                    pQwayway.emplace(DijkstraData(neighborLabel, pathCost));
                }
            }// closed while(vPtr->nextNeighbor != vPtr->label)
        } // closed while(!pQwaway.empty())
    }
}



/** mark all verticies as unvisited */
void Graph::unvisitVertices() {}

/** find a vertex, if it does not exist return nullptr */
std::shared_ptr<Vertex> Graph::findVertex(const std::string &vertexLabel) const
{
    return (vertices.count(vertexLabel) > 0)?
                vertices.find(vertexLabel)->second : nullptr;

}

/** find a vertex, if it does not exist create it and return it */
std::shared_ptr<Vertex> Graph::findOrCreateVertex(
        const std::string &vertexLabel)
{
    auto aPair = vertices.emplace(vertexLabel,
                                std::make_shared<Vertex>(Vertex(vertexLabel)));
    if(aPair.second)++numberOfVertices;
    return aPair.first->second;

}