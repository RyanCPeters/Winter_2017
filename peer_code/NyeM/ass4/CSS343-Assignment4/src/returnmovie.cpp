#include "returnmovie.h"

ReturnMovie::ReturnMovie() : MovieAction('B') {}

ReturnMovie::ReturnMovie(Movie* movie) : MovieAction('B', movie) {}

ReturnMovie::ReturnMovie(const int CUSTOMERID) : MovieAction('B', CUSTOMERID) {}

ReturnMovie::ReturnMovie(Movie* movie, const int CUSTOMERID) : MovieAction('B', movie, CUSTOMERID) {}

ReturnMovie::ReturnMovie(const ReturnMovie& OTHER) : MovieAction('B', OTHER.getMovie(), OTHER.getCustomer()) {}

ReturnMovie::~ReturnMovie() {}

Action* ReturnMovie::copy() const {
	return new ReturnMovie(*this);
}

//TODO
bool ReturnMovie::doAction(Inventory& inv) const {
	return false;
}