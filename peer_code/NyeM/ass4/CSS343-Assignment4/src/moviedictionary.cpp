#include "moviedictionary.h"
#include "dvd.h"

MovieDictionary::MovieDictionary(std::set<Movie *> movieSet, std::set<Media *> mediaSet) : DICTIONARY(movieSet), mediaDict(mediaSet) {}

MovieDictionary::~MovieDictionary() {
	for (std::set<Movie *>::iterator currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		delete * currentIt;
	}
}

bool MovieDictionary::isValid(const char& TOFIND) const {
	std::set<Movie *>::iterator currentIt;

	for (currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		Movie * currentMovie = *currentIt;

		if (currentMovie != 0 && currentMovie->getType() == TOFIND) {
			return true;
		}
	}

	return false; //Couldn't find it
}

Movie* MovieDictionary::parse(std::string line, bool hasMediaType, bool hasStock) const {
	//if (line.length() >= 3) {
	if (!hasMediaType || (hasMediaType && mediaDict.isValid(line[0]))) {
		std::set<Movie *>::iterator currentIt;

		char toFind = (hasMediaType) ? line[2] : line[0];

		for (currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
			Movie * currentMovie = *currentIt;

			if (currentMovie != 0 && currentMovie->getType() == toFind) {
				Movie * out = currentMovie->copy(); 
				
				if (hasMediaType) {
					out->setMedia(mediaDict.parse(line.substr(0, 1)));
					out->parse(line.substr(2), hasStock);
				}
				else {
					out->setMedia(new DVD());
					out->parse(line, hasStock);
				}

				return out;
			}
		}
			
		return 0;
	}
	else {
		return 0;
	}
}