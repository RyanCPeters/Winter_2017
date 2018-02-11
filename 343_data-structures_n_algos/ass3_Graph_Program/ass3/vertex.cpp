#include <climits>

#include "vertex.h"
#include "edge.h"


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


    /**
     * Creates an unvisited vertex, gives it a label, and clears its
     * adjacency list.
	 * NOTE: A vertex must have a unique label that cannot be changed.
     * @param label A reference value for the string to be used as the label
     *              of this vertex.
     */
Vertex::Vertex(const std::string& label): vertexLabel(label), visited(false)
{}

/**
 * just needed for deleting the visPtr used in tracking if a vertex is visited.
 */
Vertex::~Vertex() {
    visPtr = nullptr;
    delete(visPtr);
}

/** @return  The label of this vertex. */
std::string Vertex::getLabel() const 
{ return vertexLabel; }

/** Marks this vertex as visited. */
void Vertex::visit(int* trueRef)
{ visPtr = trueRef;}

/** Marks this vertex as not visited. */
void Vertex::unvisit() 
{ visPtr = nullptr; }

/**
 * Returns the visited status of this vertex.
 * @param trueRef The const pointer used by graph class to track if vertices
 *                have been visited during a traversal of the graph data.
 *
 * @return True if the vertex has been visited, otherwise returns false
 */
bool Vertex::isVisited(const int* const trueRef) const
{ return visPtr == trueRef; }

/** Adds an edge between this vertex and the given vertex.
Cannot have multiple connections to the same endVertex
Cannot connect back to itself
@return  True if the connection is successful. */
bool Vertex::connect(const std::string& endVertex, int const edgeWeight)
{
    if( endVertex == vertexLabel ||
            adjacencyList.find(endVertex) != adjacencyList.end() ) return false;

    adjacencyList.emplace( adjacencyList.end(),endVertex,
                           Edge( endVertex, edgeWeight ));
    return true;
}

/** Removes the edge between this vertex and the given one.
@return  True if the removal is successful. */
bool Vertex::disconnect(const std::string& endVertex) 
{
    auto iter = adjacencyList.find(endVertex);
    if(iter == adjacencyList.end())return false;
    adjacencyList.erase(iter);
    return true;
}

/** Gets the weight of the edge between this vertex and the given vertex.
@return  The edge weight. This value is zero for an unweighted graph and
is negative if the .edge does not exist */
int Vertex::getEdgeWeight(const std::string& endVertex) const
{
    auto iter = adjacencyList.find(endVertex);
    return (iter != adjacencyList.end())? iter->second.getWeight(): -1;
}

/** Calculates how many neighbors this vertex has.
@return  The number of the vertex's neighbors. */
int Vertex::getNumberOfNeighbors() const 
{ return static_cast<int>(adjacencyList.size()); }

/** Sets current neighbor to first in adjacency list. */
void Vertex::resetNeighbor() 
{ currentNeighbor = adjacencyList.begin(); }

/** Gets this vertex's next neighbor in the adjacency list.
Neighbors are automatically sorted alphabetically via map
Returns the vertex label if there are no more neighbors
@return  The label of the vertex's next neighbor. */
std::string Vertex::getNextNeighbor() 
{
    if(currentNeighbor == adjacencyList.end())return vertexLabel;
    std::string ret = currentNeighbor->first;
    ++currentNeighbor;
    return ret;
}

/** Sees whether this vertex is equal to another one.
Two vertices are equal if they have the same label. */
bool Vertex::operator==(const Vertex& rightHandItem) const 
{ return rightHandItem.vertexLabel == vertexLabel; }

/** Sees whether this vertex is < another one.
Compares vertexLabel. */
bool Vertex::operator<(const Vertex& rightHandItem) const 
{ return vertexLabel.compare(rightHandItem.vertexLabel) < 0; }


