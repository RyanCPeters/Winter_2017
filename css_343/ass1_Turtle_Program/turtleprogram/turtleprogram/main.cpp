#include "turtleprogram.h"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
	string expectedOut = "Expected Output\ntp1: []\ntp2: [F 10]\ntp1 now as tp2+tp3: [F 10 R 90]\ntp1 now as tp2 * 3: [F 10 F 10 F 10]\ntp4 is a copy of tp1: [F 10 F 10 F 10]\ntp5: [F 10]\ntp2 and tp5 are == to each other: true\ntp2 and tp3 are != to each other: true\nindex 0 of tp2 is F\ntp2 after 2 calls to setIndex: [R 90]\ntp2 and tp3 are == to each other: true\nDone.";
	ofstream collect_output;
	collect_output.open("turtleDriverOutput.txt", std::ofstream::app);

	TurtleProgram tp1;
	collect_output << "tp1: " << tp1 << endl;
	TurtleProgram tp2("F", "10");
	collect_output << "tp2: " << tp2 << endl;
	TurtleProgram tp3("R", "90");
	tp1 = tp2 + tp3;
	collect_output << "tp1 now as tp2+tp3: " << tp1 << endl;
	tp1 = tp2 * 3;
	collect_output << "tp1 now as tp2 * 3: " << tp1 << endl;
	TurtleProgram tp4(tp1);
	collect_output << "tp4 is a copy of tp1: " << tp4 << endl;
	TurtleProgram tp5("F", "10");
	collect_output << "tp5: " << tp5 << endl;
	collect_output << boolalpha;
	collect_output << "tp2 and tp5 are == to each other: " << (tp2 == tp5) << endl;
	collect_output << "tp2 and tp3 are != to each other: " << (tp2 != tp3) << endl;
	collect_output << "index 0 of tp2 is " << tp2.getIndex(0) << endl;
	tp2.setIndex(0, "R");
	tp2.setIndex(1, "90");
	collect_output << "tp2 after 2 calls to setIndex: " << tp2 << endl;
	collect_output << "tp2 and tp3 are == to each other: " << (tp2 == tp3) << endl;
	// need to write additional tests for += *=
	TurtleProgram * tpPtr = new TurtleProgram();
	collect_output << "tpPtr is constructed, and looks like this: " << *tpPtr << endl;
	collect_output << "tpPtr is at memory address: " << tpPtr << endl;
	*tpPtr = tp1;
	collect_output << "*tpPtr = tp1; tp1 = " << tp1 << "; *tpPtr = " << *tpPtr << ";\n";
	tpPtr = &tp2;
	collect_output << "tpPtr = &tp2; tp2 = " << tp2 << "; *tpPtr = " << *tpPtr << ";\n";
	collect_output << "Done." << endl << endl;

	collect_output << expectedOut << endl << endl;

	collect_output.close();
	return 0;
}