#include <string>

#include "edge.h"


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////

/** Edge::Edge(const std::string& end, const int weight = 0): endVertex(end),
 *                                                        edgeWeight(weight)
 * constructor with label and weight
 * @param end
 * @param weight
 */
Edge::Edge(const std::string& end, int weight = 0): endVertex(end),
                                                          edgeWeight(weight) {}
/** std::string Edge::getEndVertex() const
 * return the vertex this edge connects to
 * @return
 */
std::string Edge::getEndVertex() const { return endVertex; }

/** int Edge::getWeight() const
 * return the weight/cost of travlleing via this edge
 * @return
 */
int Edge::getWeight() const { return edgeWeight; }