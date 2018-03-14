//---------------------------------------------------------------------------
// main.cpp
//---------------------------------------------------------------------------
// Description: Used to test things.
//---------------------------------------------------------------------------

#include <iostream>
#include "actiondictionary.h"
#include "action/displayinventory.h"

int main() {

	std::set<Action *> set;

	set.insert(new DisplayInventory());

	ActionDictionary ac(set);

	std::cout << ac.isValidAction('I') << std::endl;

	std::cout << ac.isValidAction('1') << std::endl;
	
	std::system("PAUSE");
	return 0;
}
