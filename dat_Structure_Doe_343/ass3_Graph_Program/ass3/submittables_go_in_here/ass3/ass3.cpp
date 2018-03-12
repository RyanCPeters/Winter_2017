#include <iostream>
#include <climits>
#include <map>
#include <sstream>
#include <vector>
#include <iomanip>
#include <chrono>
#include <thread>


#include "graph.h"

////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////

using namespace std;

// global variable - need better method, but works for testing
// used by graphVisitor
ostringstream graphOut;

// global variable for Djikstra
map<string, int> weight;
map<string, string> previous;

// OK or ERR for tests
template <typename T>
string isOK(std::ostream &os, const T& got, const T& expected) {
    os << setw(15) << right << "Got [" << got << "]\n"
         << setw(15) << right << "expected [" << expected << "]" << endl;

	if( got == expected ) {
        return "OK: ";
	}

    return "ERR: ";
}

// visitor function - print out the vertex label
void display(std::ostream& os, const string& anItem) {
	os << anItem << " ";
}

// visitor function - add the string to global variable graphOut
void graphVisitor(const string& anItem) {
	graphOut << anItem << " ";
}

// add the path to get to this vertex to global variable global variable
// [A B]
// previous is a map of vertexLabel prevVertexLabel
// need to process it in reverse to get the path
void graphCostDisplayPath( const string& vertex) {
	vector<string> v;
	auto prevIt = previous.find(vertex);
	while( prevIt != previous.end() ) {
		v.push_back(prevIt->second);
		prevIt = previous.find(prevIt->second);
	}
	// v now has the path
	// oh, avoiding the joy of subtracting from unsigned int!
	auto size = static_cast<int>(v.size());
	// return if we did we not go through any other vertex
	if( size <= 1 ) {
		return;
	}
	// add space between entries
	graphOut << "via [";
	// all entries except the first and last one in reverse
	// v[size-1] is the starting vertex, skipping it
	for( int i { size - 2 }; i > 0; --i )
		graphOut << v[i] << " ";
	// add the second to last entry without space after it
	// last entry is the destination vertex, not needed
	if( size > 0 )
		graphOut << v[0];
	graphOut << "] ";
}

// unreachable nodes should not even be in weight
// but if they are,
// skip them as they should have weight of INT_MAX
// C(8) via [A B]
// getting to C has a cost of 8, we can get to C via A->B->C
void graphCostDisplay(std::ostream &os) {
    graphOut.str(string());
	for( auto it : weight ) {
		int cost = it.second;
		if( cost == INT_MAX )
			continue;
		string vertex = it.first;
		graphOut << vertex << "(" << cost << ") ";
		graphCostDisplayPath(vertex);
	}
}

void testGraph0(std::ostream &os) {
	os << "testGraph0\n";
	Graph g;
	g.readFile("graph0.txt");
	os << isOK(os,g.getNumVertices(), 3) << "3 vertices\n";
	os << isOK(os,g.getNumEdges(), 3) << "3 edges\n";

    std::string abc = "A B C ";

	graphOut.str(string());
	g.depthFirstTraversal("A", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "DFS\n";

    graphOut.str(string());
	g.breadthFirstTraversal("A", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "BFS\n";

	g.djikstraCostToAllVertices("A", weight, previous);
	graphCostDisplay(os);
    abc = "B(1) C(4) via [B] ";
	os << isOK(os,graphOut.str(), abc) << "Djisktra\n";
}

void testGraph1(std::ostream &os) {
	os << "testGraph1\n";
	Graph g;
	g.readFile("graph1.txt");

	os << isOK(os,g.getNumVertices(), 10) << "10 vertices\n";
	os << isOK(os,g.getNumEdges(), 9) << "9 edges\n";

    std::string abc = "A B C D E F G H "; // "A B C D E F G H "
    graphOut.str(string());
	g.depthFirstTraversal("A", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "DFS\n";

    abc = "A B H C G D E F "; // "A B H C G D E F "
    graphOut.str(string());
	g.breadthFirstTraversal("A", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "BFS\n";


    g.djikstraCostToAllVertices("A", weight, previous);
	graphCostDisplay(os);
    abc = "B(1) C(2) via [B] D(3) via [B C] E(4) via [B C D] F(5) via [B C D E] "
          "G(4) via [H] "
          "H(3) ";
	os << isOK(os,graphOut.str(),abc) << "Djisktra\n";
}

void testGraph2(std::ostream &os) {
    os << "testGraph2\n";
	Graph g;
    std::string abc;
    g.readFile("graph2.txt");
	os << isOK(os,g.getNumVertices(), 21) << "21 vertices\n";
	os << isOK(os,g.getNumEdges(), 24) << "24 edges\n";


    abc = "A B E F J C G K L D H M I N ";// "A B E F J C G K L D H M I N "
    graphOut.str(string());
	g.depthFirstTraversal("A", graphVisitor);
	os << isOK(os,graphOut.str(), abc)
		<< "DFS from A\n";


    abc = "O P R S T U Q "; //"O P R S T U Q "
    graphOut.str(string());
	g.depthFirstTraversal("O", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "DFS from O\n";


    abc = "A B C D E F G H I J K L M N ";// "A B C D E F G H I J K L M N "
    graphOut.str(string());
	g.breadthFirstTraversal("A", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "BFS from A\n";


    abc = "D H I M N "; // "D H I M N "
    graphOut.str(string());
	g.breadthFirstTraversal("D", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "BFS from D\n";


    abc = "U ";
    graphOut.str(string());
	g.depthFirstTraversal("U", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "DFS from U\n";


    graphOut.str(string());
	g.breadthFirstTraversal("U", graphVisitor);
	os << isOK(os,graphOut.str(), abc) << "BFS from U\n";


    abc = "P(5) Q(2) R(3) via [Q] S(6) via [Q R] "
          "T(8) via [Q R S] U(9) via [Q R S] ";
	g.djikstraCostToAllVertices("O", weight, previous);
	graphCostDisplay(os);
	os << isOK(os,graphOut.str(), abc) << "Djisktra O\n";
    os.flush();
}

/** In case you can't tell, I've had a hell of a time figuring out why my
 * dijkstra algrithm is producing such messed up path lengths.
 *
 * @param os
 */
void justTestGraph2Dijkstra(std::ostream &os) {
    os << "justTestGraph2Dijkstra\n";
    Graph g;
    std::string abc;
    g.readFile("graph2.txt");
    
    abc = "P(5) Q(2) R(3) via [Q] S(6) via [Q R] "
            "T(8) via [Q R S] U(9) via [Q R S] ";
    g.djikstraCostToAllVertices("O", weight, previous);
    graphCostDisplay(os);
    os << isOK(os,graphOut.str(), abc) << "Djisktra O\n";
    os.flush();
}


/** For the sake of my personal convenience I redirected the outputs for
 * ass3.cpp to go to an output file instead of the console.
 *
 * That said, it's easy enough to switch between the output file and the
 * console; simply comment/uncomment the function calls bellow as you please.
 *
 * @return
 */
int main() {
    
    std::ofstream oFile("dumpFile.txt", ofstream::trunc);
    
    
    for(auto i = 0; i < 1; ++i){
//        oFile << setfill('~') << setw(80) << "." << endl;
//        oFile << setfill(' ');
//        justTestGraph2Dijkstra(oFile);
        
        oFile << setfill('~') << setw(80) << "." << endl;
        oFile << std::endl;
        oFile << setfill(' ');
        
//        testGraph0(oFile);
        testGraph0(cout);
    
        oFile << setfill('~') << setw(80) << "." << endl;
        oFile << std::endl;
        oFile << setfill(' ');
    
//        testGraph1(oFile);
        testGraph1(cout);
    
        oFile << setfill('~') << setw(80) << "." << endl;
        oFile << std::endl;
        oFile << setfill(' ');
    
//        testGraph2(oFile);
        testGraph2(cout);
        
        oFile << std::endl;
    }
    oFile.close();
	return 0;
}
