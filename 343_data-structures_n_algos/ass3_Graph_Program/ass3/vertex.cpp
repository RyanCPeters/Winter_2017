#include <climits>
#include <memory>

#include "vertex.h"


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
Vertex::Vertex(const std::string& label)
        : vertexLabel(label), visPtr(nullptr)
{}

/**
 * just needed for deleting the visPtr used in tracking if a vertex is visited.
 */
Vertex::~Vertex() {
    // we set visPtr to nullptr before deleting it because
    // we aren't trying to modify the control reference from Vertex.
    visPtr = nullptr;
    free(visPtr);
}

/** @return  The label of this vertex. */
std::string Vertex::getLabel() const 
{ return vertexLabel; }

/** Marks this vertex as visited. */
void Vertex::visit(void *trueRef)
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
bool Vertex::isVisited(const void *const trueRef) const
{ return visPtr == trueRef; }

/** Adds an edge between this vertex and the given vertex.
Cannot have multiple connections to the same endVertex
Cannot connect back to itself
@return  True if the connection is successful. */
bool Vertex::connect(std::weak_ptr<Vertex> const endVertex,
                     int const edgeWeight)
{
    std::string endLabel = (endVertex.lock()->getLabel());

    if(endLabel == vertexLabel ||
            adjacencyList.count(endLabel) > 0 ) {
        return false;
    }
    adjacencyList[endLabel] = Edge<Vertex>(endVertex.lock(),edgeWeight);
    resetNeighbor();
    resetReverseNeighbor();
    return true;
}

/** Removes the edge between this vertex and the given one.
@return  True if the removal is successful. */
bool Vertex::disconnect(const std::string& endVertex) 
{
    if (adjacencyList.count(endVertex) == 0)return false;
    adjacencyList.erase(endVertex);
    resetNeighbor();
    resetReverseNeighbor();
    return true;
}

/** Gets the weight of the edge between this vertex and the given vertex.
@return  The edge weight. This value is zero for an unweighted graph and
is negative if the .edge does not exist */
int Vertex::getEdgeWeight(const std::string& endVertex) const
{
    auto iter = adjacencyList.find(endVertex);
    return (iter != adjacencyList.end() && iter->first != vertexLabel)?
           iter->second.getWeight():-1;
}

/** Calculates how many neighbors this vertex has.
@return  The number of the vertex's neighbors. */
int Vertex::getNumberOfNeighbors() const 
{ return static_cast<int>(adjacencyList.size()); }

/** Sets current neighbor to first in adjacency list. */
void Vertex::resetNeighbor() 
{ currentNeighbor = adjacencyList.begin(); }

void Vertex::resetReverseNeighbor()
{ reverseCurNeighbor = adjacencyList.rbegin(); }

/** Gets this vertex's next neighbor in the adjacency list.
Neighbors are automatically sorted alphabetically via map
Returns the vertex label if there are no more neighbors
@return  The label of the vertex's next neighbor. */
std::string Vertex::getNextNeighbor()
{
    if(currentNeighbor == adjacencyList.end())return vertexLabel;
    return (currentNeighbor++)->first;
}

std::string Vertex::reverseGetNextNeighbor()
{
    if (reverseCurNeighbor == adjacencyList.rend())return vertexLabel;
    return (reverseCurNeighbor++)->first;
}

std::string Vertex::peekNextNeighbor() const {
    if (currentNeighbor == adjacencyList.end())return vertexLabel;
    return currentNeighbor->first;
}

std::string Vertex::reversePeekNextNeighbor() const {
    if (reverseCurNeighbor == adjacencyList.rend())return vertexLabel;
    return reverseCurNeighbor->first;
}

/** Sees whether this vertex is equal to another one.
Two vertices are equal if they have the same label. */
bool Vertex::operator==(const std::shared_ptr<Vertex> &rightHandItem) const
{ return rightHandItem->vertexLabel == vertexLabel; }

/** Sees whether this vertex is < another one.
Compares vertexLabel. */
bool Vertex::operator<(const std::shared_ptr<Vertex> &rightHandItem) const
{ return vertexLabel.compare(rightHandItem->vertexLabel) < 0; }


