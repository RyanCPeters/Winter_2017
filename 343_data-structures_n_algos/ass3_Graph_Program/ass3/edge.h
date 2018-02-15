/**
* Used by vertex to keep track of all the vertices it connects to
* Each edge has a weight, possibly 0
* Edge is a simple container class, no interesting functions
*/

#ifndef EDGE_H
#define EDGE_H

#include <string>
#include <memory>

template<typename T>
class Edge {
public:
	/** empty edge constructor */
	Edge() = default;

	/** Edge::Edge(const std::string& end, const int weight = 0): endVertex(end),
	 *                                                        edgeWeight(weight)
	 * constructor with label and weight
	 * @param end
	 * @param weight
	 */
	Edge(std::shared_ptr<T> end, int weight = 0)
			: endVertex(std::move(end)), edgeWeight(weight) {}

	/** std::string Edge::getEndVertex() const
	 * return the vertex this edge connects to
	 * @return
	 */
	std::shared_ptr<T> &getEndVertex() const { return endVertex; }

	/** int Edge::getWeight() const
	 * return the weight/cost of travlleing via this edge
	 * @return
	 */
	int getWeight() const { return edgeWeight; }

private:
	/** end vertex, cannot be changed */
	std::shared_ptr<T> endVertex { nullptr };

	/** edge weight, cannot be changed */
	int edgeWeight { 0 };
};  //  end Edge








#endif  // EDGE_H