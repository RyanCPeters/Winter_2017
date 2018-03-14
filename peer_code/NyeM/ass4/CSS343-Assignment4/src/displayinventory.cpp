#include "action/displayinventory.h"

DisplayInventory::DisplayInventory() : Action('I') {}

DisplayInventory::DisplayInventory(const DisplayInventory& other) : Action(other.getLetter()) {}

DisplayInventory::~DisplayInventory() {}

//TODO
bool DisplayInventory::doAction(Inventory& inv) const {
	//cout << inv << endl;
	return false;
}

Action* DisplayInventory::copy() const{
	return new DisplayInventory();
}
/*
bool DisplayInventory::parse(std::string line) {
	if (line.length() == 0 || line.length() > 1) {
		return false;
	}
	else {
		if (line[0] == 'I') {
			return true;
		}
		else {
			return false;
		}
	}
}
*/
