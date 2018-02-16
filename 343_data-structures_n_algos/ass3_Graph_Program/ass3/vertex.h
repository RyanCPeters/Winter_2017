/**
* Each vertex has a unique label
* Can be connected to other vertices via weighted edges
* Cannot be connected to itself
* Used by depth-first search and breadth-first search
* to keep track of if it has been visited or not
*/

#ifndef VERTEX_H
#define VERTEX_H

#include <functional>
#include <map>
#include <string>
#include <memory>

#include "edge.h"

class Vertex {
public:
    /**
     * Creates an unvisited vertex, gives it a label, and clears its
     * adjacency list.
	 * NOTE: A vertex must have a unique label that cannot be changed.
     * @param label A reference value for the string to be used as the label
     *              of this vertex.
     */
	explicit Vertex(const std::string& label);

    /**
     * just needed for deleting the visPtr used in tracking if a vertex is visited.
     */
    virtual ~Vertex();

    /** @return  The label of this vertex. */
	std::string getLabel() const;

	/** Marks this vertex as visited. */
	void visit(void *trueRef);

	/** Marks this vertex as not visited. */
	void unvisit();


    /**
     * Returns the visited status of this vertex.
     * @param trueRef
     * @return True if the vertex has been visited, otherwise returns false
     */
	bool isVisited(const void *const trueRef) const;

	/** Adds an edge between this vertex and the given vertex.
	Cannot have multiple connections to the same endVertex
	Cannot connect back to itself
	@return  True if the connection is successful. */
	bool connect(std::weak_ptr<Vertex> endVertex,
                 const int edgeWeight = 0);

	/** Removes the edge between this vertex and the given one.
	@return  True if the removal is successful. */
	bool disconnect(const std::string& endVertex);

	/** Gets the weight of the edge between this vertex and the given vertex.
	@return  The edge weight. This value is zero for an unweighted graph and
	is negative if the .edge does not exist */
	int getEdgeWeight(const std::string& endVertex = 0) const;

	/** Calculates how many neighbors this vertex has.
	@return  The number of the vertex's neighbors. */
	int getNumberOfNeighbors() const;

	/** Sets current neighbor to first in adjacency list. */
	void resetNeighbor();

    /** Sets current neighbor to last in adjacency list.
     * Used in depth-first-search that utilizes a stack to track
     * unvisited nodes.
     * */
    void resetReverseNeighbor();

	/** Gets this vertex's next neighbor in the adjacency list.
	Neighbors are automatically sorted alphabetically via map
	Returns the vertex label if there are no more neighbors
	@return  The label of the vertex's next neighbor. */
	std::string getNextNeighbor();

    /**
     *
     * @return
     */
    std::string reverseGetNextNeighbor();

    /**
     *
     * @return
     */
    std::string peekNextNeighbor() const;

    /**
     *
     * @return
     */
    std::string reversePeekNextNeighbor() const;

    /** Sees whether this vertex is equal to another one.
	Two vertices are equal if they have the same label. */
	bool operator==(const std::shared_ptr<Vertex> &rightHandItem) const;

	/** Sees whether this vertex is < another one.
	Compares vertexLabel. */
	bool operator<(const std::shared_ptr<Vertex> &rightHandItem) const;



private:
	/** the unique label for the vertex */
	std::string vertexLabel;

	/** True if the vertex is visited */
	bool visited { false };

    /** Used in conditional checks that compare the memory address pointed to
     * by this pointer to see if it matches the current traversal's
     * assigned reference address when checking if this vertex has been visited.
     *
     * After graph is traversed and nodes need to be set back to "not visited"
     * status, the memory address pointed to by all visited nodes is deleted
     * and reclaimed.
     */
	void* visPtr;

	/** adjacencyList as an ordered map, in alphabetical order */
	std::map<std::string, Edge<Vertex>, std::less<>> adjacencyList;

	/** iterator showing which neighbor we are currently at */
	std::map<std::string, Edge<Vertex>>::iterator currentNeighbor;

    std::map<std::string, Edge<Vertex>>::reverse_iterator reverseCurNeighbor;
};

#endif  // VERTEX_H