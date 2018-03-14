#include "mediadictionary.h"

MediaDictionary::MediaDictionary(std::set<Media *> mediaSet) : DICTIONARY(mediaSet) {}

MediaDictionary::~MediaDictionary() {
	for (std::set<Media *>::iterator currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		delete * currentIt;
	}
}

bool MediaDictionary::isValid(const char& TOFIND) const {
	std::set<Media *>::iterator currentIt;

	for (currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		Media * currentMedia = *currentIt;

		if (currentMedia != 0 && currentMedia->MEDIA_TYPE == TOFIND) {
			return true;
		}
	}

	return false; //Couldn't find it
}

Media* MediaDictionary::parse(std::string line) const {
	if (line.length() >= 1) {
		std::set<Media *>::iterator currentIt;

		char toFind = line[0];

		for (currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
			Media * currentMedia = *currentIt;

			if (currentMedia != 0 && currentMedia->MEDIA_TYPE == toFind) {
				return currentMedia->copy();
			}
		}

		return 0;
	}
	else {
		return 0;
	}
}