#include "action/movieaction.h"

MovieAction::MovieAction(const char C) : CustomerAction(C) {
	selectedMovie = 0;
}

MovieAction::MovieAction(const char C, Movie* movie) : CustomerAction(C) {
	setMovie(movie);
}

MovieAction::MovieAction(const char C, const int CUSTOMERID) : CustomerAction(C, CUSTOMERID) {
	selectedMovie = 0;
}

MovieAction::MovieAction(const char C, Movie* movie, const int CUSTOMERID) : CustomerAction(C, CUSTOMERID) {
	setMovie(movie);
}

MovieAction::MovieAction(const MovieAction& OTHER) : CustomerAction(OTHER.getLetter(), OTHER.getCustomer()) {
	setMovie(OTHER.getMovie());
}

MovieAction::~MovieAction() {
	delete selectedMovie;
}

/*
//TODO
bool MovieAction::parse(std::string line) {
	if (line.length() >= 2) { //Has at least the letter

	}
	else {
		return false;
	}
}
*/

void MovieAction::setMovie(Movie* MOVIE) {
	selectedMovie = MOVIE;
}

Movie* MovieAction::getMovie() const {
	if (selectedMovie == 0) {
		return 0;
	}
	else {
		return selectedMovie->copy();
	}
}

bool MovieAction::operator==(const MovieAction& OTHER) const {
	return getMovie() == OTHER.getMovie()
		&& getCustomer() == OTHER.getCustomer()
		&& getLetter() == OTHER.getLetter();
}

bool MovieAction::operator!=(const MovieAction& OTHER) const {
	return !(*this == OTHER);
}
