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
string isOK(const T& got, const T& expected) {
    cout << setw(15) << right << "Got [" << got << "]" << endl
         << setw(15) << right << "expected [" << expected << "]" << endl;

	std::this_thread::sleep_for(std::chrono::milliseconds(50));
	if( got == expected ) {
        return "OK: ";
	}

    return "ERR: ";
}

// visitor function - print out the vertex label
void display(const string& anItem) {
	cout << anItem << " ";
}

// visitor function - add the string to global variable graphOut
void graphVisitor(const string& anItem) {
	graphOut << anItem << " ";
}

// add the path to get to this vertex to global variable global variable
// [A B]
// previous is a map of vertexLabel prevVertexLabel
// need to process it in reverse to get the path
void graphCostDisplayPath(string vertex) {
	vector<string> v;
	auto prevIt = previous.find(vertex);
	while( prevIt != previous.end() ) {
		v.push_back(prevIt->second);
		prevIt = previous.find(prevIt->second);
	}
	// v now has the path
	// oh, avoiding the joy of subtracting from unsigned int!
	int size = static_cast<int>(v.size());
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
void graphCostDisplay() {
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

void testGraph0() {
	cout << "testGraph0" << endl;
	Graph g;
	g.readFile("graph0.txt");
	cout << isOK(g.getNumVertices(), 3) << "3 vertices" << endl;
	cout << isOK(g.getNumEdges(), 3) << "3 edges" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::string abc = "A B C ";

	graphOut.str(string());
	g.depthFirstTraversal("A", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "DFS" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    graphOut.str(string());
	g.breadthFirstTraversal("A", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "BFS" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

	g.djikstraCostToAllVertices("A", weight, previous);
	graphCostDisplay();
    abc = "B(1) C(4) via [B] ";
	cout << isOK(graphOut.str(), abc) << "Djisktra" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
}

void testGraph1() {
	cout << "testGraph1" << endl;
	Graph g;
	g.readFile("graph1.txt");
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

	cout << isOK(g.getNumVertices(), 10) << "10 vertices" << endl;
	cout << isOK(g.getNumEdges(), 9) << "9 edges" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::string abc = "A B C D E F G H "; // "A B C D E F G H "
    graphOut.str(string());
	g.depthFirstTraversal("A", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "DFS" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));

    abc = "A B H C G D E F "; // "A B H C G D E F "
    graphOut.str(string());
	g.breadthFirstTraversal("A", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "BFS" << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));


    g.djikstraCostToAllVertices("A", weight, previous);
	graphCostDisplay();
    abc = "B(1) C(2) via [B] D(3) via [B C] E(4) via [B C D] F(5) via [B C D E] "
          "G(4) via [H] "
          "H(3) ";
	cout << isOK(graphOut.str(),abc) << "Djisktra" << endl;
}

void testGraph2() {
    cout << "testGraph2" << endl;
	Graph g;

	g.readFile("graph2.txt");
	cout << isOK(g.getNumVertices(), 21) << "21 vertices" << endl;
	cout << isOK(g.getNumEdges(), 24) << "24 edges" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    std::string abc = "A B E F J C G K L D H M I N ";// "A B E F J C G K L D H M I N "
    graphOut.str(string());
	g.depthFirstTraversal("A", graphVisitor);
	cout << isOK(graphOut.str(), abc)
		<< "DFS from A" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    abc = "O P R S T U Q "; //"O P R S T U Q "
    graphOut.str(string());
	g.depthFirstTraversal("O", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "DFS from O" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    abc = "A B C D E F G H I J K L M N ";// "A B C D E F G H I J K L M N "
    graphOut.str(string());
	g.breadthFirstTraversal("A", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "BFS from A" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    abc = "D H I M N "; // "D H I M N "
    graphOut.str(string());
	g.breadthFirstTraversal("D", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "BFS from D" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    abc = "U ";
    graphOut.str(string());
	g.depthFirstTraversal("U", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "DFS from U" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    graphOut.str(string());
	g.breadthFirstTraversal("U", graphVisitor);
	cout << isOK(graphOut.str(), abc) << "BFS from U" << endl;

    cout.flush();
	std::this_thread::sleep_for(std::chrono::milliseconds(50));

    abc = "P(5) Q(2) R(3) via [Q] S(6) via [Q R] "
          "T(8) via [Q R S] U(9) via [Q R S] ";
	g.djikstraCostToAllVertices("O", weight, previous);
	graphCostDisplay();
	cout << isOK(graphOut.str(), abc) << "Djisktra O" << endl;
}

int main() {

    cout << setfill('~') << setw(80) << left << "." << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
	cout << endl << setfill(' ');
	testGraph0();
    cout << setfill('~') << setw(80) << left << "." << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout << endl << setfill(' ');
	testGraph1();
    cout << setfill('~') << setw(80) << left << "." << endl;
    cout.flush();
    std::this_thread::sleep_for(std::chrono::milliseconds(50));
    cout << endl << setfill(' ');
	testGraph2();
	return 0;
}