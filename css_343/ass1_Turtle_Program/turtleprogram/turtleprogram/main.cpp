#include "turtleprogram.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string expectedOut = "Expected Output\ntp1: []\ntp2: [F 10]\ntp1 now as tp2+tp3: [F 10 R 90]\ntp1 now as tp2 * 3: [F 10 F 10 F 10]\ntp4 is a copy of tp1: [F 10 F 10 F 10]\ntp5: [F 10]\ntp2 and tp5 are == to each other: true\ntp2 and tp3 are != to each other: true\nindex 0 of tp2 is F\ntp2 after 2 calls to setIndex: [R 90]\ntp2 and tp3 are == to each other: true\nDone.";
//	ofstream collect_output;
//	collect_output.open("turtleDriverOutput.txt", std::ofstream::app);

	TurtleProgram tp1;
	cout << "tp1: " << tp1 << endl;
	TurtleProgram tp2("F", "10");
	cout << "tp2: " << tp2 << endl;
	TurtleProgram tp3("R", "90");
	tp1 = tp2 + tp3;
	cout << "tp1 now as tp2+tp3: " << tp1 << endl;
	tp1 = tp2 * 3;
	cout << "tp1 now as tp2 * 3: " << tp1 << endl;
	TurtleProgram tp4(tp1);
	cout << "tp4 is a copy of tp1: " << tp4 << endl;
	TurtleProgram tp5("F", "10");
	cout << "tp5: " << tp5 << endl;
	cout << boolalpha;
	cout << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
	cout << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
	cout << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
	tp2.setIndex(0, "R");
	tp2.setIndex(1, "90");
	cout << "tp2 after 2 calls to setIndex: " << tp2 << endl;
	cout << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
	
	
	// need to write additional tests for += *=
	// += and *= are actually tested and showcased in the use of the basic operator* and operator+ overloads.
	
	
//	TurtleProgram * tpPtr = new TurtleProgram();
//	cout << "tpPtr is constructed, and looks like this: " << *tpPtr << endl;
//	cout << "tpPtr is at memory address: " << tpPtr << endl;
//	*tpPtr = tp1;
//	cout << "*tpPtr = tp1; tp1 = " << tp1 << "; *tpPtr = " << *tpPtr << ";\n";
//	tpPtr = &tp2;
//	cout << "tpPtr = &tp2; tp2 = " << tp2 << "; *tpPtr = " << *tpPtr << ";\n";
	cout << "Done." << endl << endl;
//
	cout << expectedOut << endl << endl;
//	delete(tpPtr);

//	collect_output.close();
	return 0;
}