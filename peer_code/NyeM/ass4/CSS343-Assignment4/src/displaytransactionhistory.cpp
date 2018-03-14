#include "displaytransactionhistory.h"

DisplayTransactionHistory::DisplayTransactionHistory() : CustomerAction('H') {}

DisplayTransactionHistory::DisplayTransactionHistory(const int CUSTOMER_ID) : CustomerAction('H', CUSTOMER_ID) {}

DisplayTransactionHistory::DisplayTransactionHistory(const DisplayTransactionHistory& OTHER) : CustomerAction('H', OTHER.getCustomer()) {}

DisplayTransactionHistory::~DisplayTransactionHistory() {}

//TODO
bool DisplayTransactionHistory::doAction(Inventory& inv) const {
	return false;
}

/*
bool DisplayTransactionHistory::parse(std::string line) {
	//if (line.length() >= 1) {
	//	if (line[0] == 'H') {
	//		int out = std::stoi(line.substr(2, 2 + 4)); //Ignore the letter and the following space. Only grab the next 4 characters

	//		return out;
	//	}
	//	else {
	//		return false;
	//	}
	//}
	//else {
	//	return false;
	//}

	if (line[0] == 'H') {
		return CustomerAction::parse(line);
	}
	else {
		return false;
	}
}
*/

Action* DisplayTransactionHistory::copy() const {
	return new DisplayTransactionHistory(*this);
}

bool DisplayTransactionHistory::operator==(const DisplayTransactionHistory& other) const {
	return getLetter() == other.getLetter() && getCustomer() == other.getCustomer();
}

bool DisplayTransactionHistory::operator!=(const DisplayTransactionHistory& other) const {
	return getLetter() != other.getLetter() || getCustomer() != other.getCustomer();
}