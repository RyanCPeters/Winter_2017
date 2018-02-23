#include <random>
#include <chrono>
#include <algorithm>
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
Graph::Graph()
        : numberOfVertices(0),
          numberOfEdges(0),
          vertices() {
// by using int (unsigned char) we have a value range between 0 and
// 65535. So we'll just maintain a class level member variable that
// increments by one with each traversal, and reset it to 0 again when it
// reaches 65535. We then pass the trueRef value for a given traversal into the
// visited vertices, thus marking them as visited for the duration of that
// traversal. That stored value is then invalidated upon the beginning of the
// next traversal when trueRef gets incremented again.
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
    Vertex* vPtr, *endPtr;
    vPtr = findOrCreateVertex(start);
    // next we ensure that end is stored in the vertices map
    endPtr = findOrCreateVertex(end);

    // we now establish the edge connection between the two vertices via that
    // Vertex pointer we made.
    if(vPtr->connect(*endPtr, edgeWeight)){
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


/** depth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::depthFirstTraversal(std::string startLabel,
								void visit(const std::string&)) 
{
    unvisitAll();
    if (vertices.count(startLabel) == 0) {
        // the starting label isn't a part of this graph
        return; // so break out of function with an empty return.
    }
//    depthFirstTraversalHelper((findVertex(startLabel)), visit);
    std::string startVertex = findVertex(startLabel).getLabel();
    std::vector<std::string> stk;
    stk.push_back(startVertex);

    
    while (!stk.empty()) {
        auto curVert = vertices.find(stk.back())->second;
        stk.pop_back();
        if(curVert->isVisited())continue;
        curVert->resetReverseNeighbor();
        visit(curVert->getLabel());
        curVert->visit();
        while(curVert->reversePeekNextNeighbor() != curVert->getLabel()){
            auto neighbor = vertices[curVert->reverseGetNextNeighbor()];
            if((neighbor->isVisited()))continue;
            stk.push_back(neighbor->getLabel());
        }
    }
}


/** breadth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::breadthFirstTraversal(std::string startLabel,
								  void visit(const std::string&)) 
{
    unvisitAll();
    if (vertices.count(startLabel) == 0) {
        // the starting label isn't a part of this graph
        return; // so break out of function with an empty return.
    }
//    breadthFirstTraversalHelper((findVertex(startLabel)), visit);
    auto startVertex = std::make_shared<Vertex>(findVertex(startLabel));
    std::queue<std::shared_ptr<Vertex>> qwayway;
    qwayway.push(startVertex);
    
    // establishing the memory address we'll use later when checking if
    // vertices have been visited yet

    
    qwayway.front()->visit();
    auto vPtr = qwayway.front();
    while (!qwayway.empty()) {
        vPtr = qwayway.front();
        qwayway.pop();
        vPtr->resetNeighbor();
        std::unique_ptr<std::string> curVtx, nextVLabel;
        curVtx = std::make_unique<std::string>(vPtr->getLabel());
        visit(*curVtx);
        std::string c = *curVtx;
        while (*curVtx != vPtr->peekNextNeighbor()) {
            nextVLabel = std::make_unique<std::string>(vPtr->getNextNeighbor());
            
            std::string d = *nextVLabel;
            std::shared_ptr<Vertex> item = vertices.find(*nextVLabel)->second;
            if (!(item->isVisited())) {
                item->visit();
                qwayway.push(item);
            }
        }
    }
}


/** This struct is for use inside the dijkstra algo, where it will serve
 * as the comparitor for the priority queue.
*
*/
struct MyGreaterComp {
    MyGreaterComp() = default;
    bool operator() (const std::pair<std::string,int>& lhs,
                     const std::pair<std::string,int>&rhs) const
    { return lhs.second > rhs.second; }
};

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
    
    unvisitAll();
    int theBigOne = 2147483640, lValueRef = 0;
    
//    for(const auto &ele : vertices){
//        if(ele.first != startLabel) {
//// a more portable way to get max int_32
//            weight[ele.first] = theBigOne;
//            previous[ele.first] = "";
//        }
//    }
    typedef std::pair<std::string,int> aPair;
// We'll use a vector to emulate a stack and then we'll comense with a dfs
// traversal of the graph as we update path values¯\_(ツ)_/¯
    std::priority_queue<aPair,std::vector<aPair>, MyGreaterComp> theQwayway;
    aPair pairHandler = std::make_pair(startLabel,lValueRef);
    bool noChangeToWeightMap = false;
    while(!noChangeToWeightMap) {
        noChangeToWeightMap = true;
        theQwayway.push(pairHandler);
        while (!theQwayway.empty()) {
// curVert will be used to get the ajacent vertices that we will
// subsequently be adding to pQwayway.
            auto curPair = theQwayway.top();
            theQwayway.pop();
            curPair.second = weight.find(curPair.first)->second;
            auto curVert = vertices.find(curPair.first)->second;
            curVert->resetNeighbor();
            while (curVert->peekNextNeighbor() != curPair.first) {
                int pathCost = curPair.second;
// neighborLabel will be used to get the cumulative weight along the path
// that has gotten us to the current vertex.
                std::string neighborLabel = (curVert->getNextNeighbor());
// sanity check so we don't try to add start point to the end of path
                if(neighborLabel == startLabel)continue;
// before we get to far ahead of ourselves, we need to make sure our maps are
// consistent with what our curPair data says.
                if(weight.count(neighborLabel) == 0)
                    weight[neighborLabel] = theBigOne;
                if(previous.count(neighborLabel) == 0)
                    previous[neighborLabel] = "";
/*
 Regarding the following if blocks:

 we're going to set pathCost to be the sum of the edge from our current
 vertex location to the next adjacent neighbor plus the cumulative value of
 this path up to the mapped value for our vertex's "previous" counterpart
*/
                if(curVert->getEdgeWeight(neighborLabel) > -1)
                    pathCost += getEdgeWeight(curPair.first, neighborLabel);
/*
  Now we begin the fun stuff!
  Because we are looking for the lowest cost paths to each vertex, we only
  want to update our maps and priority queue when the newly calculated
  pathCost is less than the current recorded cost for the destination vertex.
 */
                if(pathCost < weight[neighborLabel]){
                    noChangeToWeightMap = false;

                    weight[neighborLabel] = pathCost;
                    previous[neighborLabel] = curPair.first;
                    theQwayway.emplace(std::make_pair(neighborLabel, pathCost));
                }
            }// closed while(curVert->nextNeighbor != curVert->label)
        } // closed while(!pQwaway.empty())
    } // closed while(!noChangeToWeightMap)
}


/** find a vertex, if it does not exist return nullptr */
Vertex Graph::findVertex(const std::string &vertexLabel)
{
    return *(vertices[vertexLabel]);

}

/** find a vertex, if it does not exist create it and return it */
Vertex * Graph::findOrCreateVertex(
        const std::string &vertexLabel)
{
    if(vertices.count(vertexLabel) < 1){
        
        std::shared_ptr<Vertex> ptr = std::make_shared<Vertex>(Vertex
                                                                    (vertexLabel));
        vertices.emplace(vertexLabel, ptr);
        ++numberOfVertices;
    }
    
    return &*vertices[vertexLabel];

}

void Graph::unvisitAll() {
    
    for(const auto & ele : vertices)ele.second->unvisit();
    
}
