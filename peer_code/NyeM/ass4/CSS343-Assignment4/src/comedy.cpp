#include "stored_data/movie/comedy.h"
#include "dvd.h"

Comedy::Comedy() : Movie('F') {}

Comedy::Comedy(int s, std::string ti, std::string dir, int rY)
		: Movie('F', s, ti, dir, rY) {}

Comedy::~Comedy() {}

bool Comedy::parse(std::string line, bool hasStock) {
	if (line[0] != 'F') {
		return false;
	}
	else {
		return Movie::parse(line, hasStock);
	}
}

int Comedy::hash() const {
	return 0;
}
