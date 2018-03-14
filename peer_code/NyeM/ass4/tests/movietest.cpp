#include "comedy.h"
#include <iostream>

int main() {
	Comedy* comedy = new Comedy();
	std::string testParse = "F, 10, Nora Ephron, Sleepless in Seattle, 1993";

	comedy->parse(testParse, true);

	std::cout << *comedy << std::endl;

	return 0;
}