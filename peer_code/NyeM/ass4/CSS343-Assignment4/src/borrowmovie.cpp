#include "action/borrowmovie.h"

BorrowMovie::BorrowMovie() : MovieAction('B') {}

BorrowMovie::BorrowMovie(Movie* movie) : MovieAction('B', movie) {}

BorrowMovie::BorrowMovie(const int CUSTOMERID) : MovieAction('B', CUSTOMERID) {}

BorrowMovie::BorrowMovie(Movie* movie, const int CUSTOMERID) : MovieAction('B', movie, CUSTOMERID) {}

BorrowMovie::BorrowMovie(const BorrowMovie& OTHER) : MovieAction('B', OTHER.getMovie(), OTHER.getCustomer()) {}

BorrowMovie::~BorrowMovie() {}

/*
bool BorrowMovie::parse(std::string line) {
	if (line.length() >= 2) {
		if (line[0] == 'B') {
			return false;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
}
*/

Action* BorrowMovie::copy() const {
	return new BorrowMovie(*this);
}

//TODO
bool BorrowMovie::doAction(Inventory& inv) const {
	return false;
}
