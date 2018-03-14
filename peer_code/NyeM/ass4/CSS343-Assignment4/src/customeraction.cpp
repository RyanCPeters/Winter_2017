#include "action/customeraction.h"

CustomerAction::CustomerAction(const char action_type) : Action(action_type) {
	setCustomer(-1);
}

CustomerAction::CustomerAction(const char action_type,
															 const int SELECTED_CUSTOMER)
		: Action(action_type) {
	setCustomer(SELECTED_CUSTOMER);
}

CustomerAction::CustomerAction(const CustomerAction& toCopy)
		: Action(toCopy.getLetter()) {
	setCustomer(toCopy.getCustomer());
}

CustomerAction::~CustomerAction() {}

/*
bool CustomerAction::parse(std::string line) {
	if (line.length() >= 2) { //Has at least the letter

		//Ignore the letter and the following space. Only grab the next 4 characters
		int out = std::stoi(line.substr(2, 2 + 4));

		setCustomer(out); //Set the customerID 

		return true; //Success!
	}
	else {
		return false;
	}
}
*/
int CustomerAction::getCustomer() const {
	return selectedCustomerID;
}

void CustomerAction::setCustomer(const int toCopy) {
	selectedCustomerID = toCopy;
}

bool CustomerAction::operator==(const CustomerAction& other) const {
	return getLetter() == other.getLetter() && getCustomer() == other.getCustomer();
}

bool CustomerAction::operator!=(const CustomerAction& other) const {
	// Y U NO USE:
	// return !(*this == other);
	return getLetter() != other.getLetter() || getCustomer() != other.getCustomer();
}
