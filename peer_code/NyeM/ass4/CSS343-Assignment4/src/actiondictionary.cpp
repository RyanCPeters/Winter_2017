#include "actiondictionary.h"
#include "action/displayinventory.h"
#include "action/customeraction.h"
#include "action/movieaction.h"

ActionDictionary::ActionDictionary(std::set<Action *> set, const MovieDictionary * movieDict) : DICTIONARY(set), MOVIEDICTIONARY(movieDict) {}

ActionDictionary::~ActionDictionary() {
	for (std::set<Action *>::iterator currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		delete * currentIt;
	}
}

Action * ActionDictionary::getAction(const char toFind) const {
	std::set<Action *>::iterator currentIt;

	for (currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		Action * currentAction = *currentIt;

		if (currentAction != 0 && currentAction->getLetter() == toFind) {
			return currentAction->copy();
		}
	}

	return 0; //Couldn't find it
}

bool ActionDictionary::isValidAction(const char& TO_FIND) const {
	std::set<Action *>::iterator currentIt;

	for (currentIt = DICTIONARY.begin(); currentIt != DICTIONARY.end(); ++currentIt) {
		Action * currentAction = *currentIt;

		if (currentAction != 0 && currentAction->getLetter() == TO_FIND) {
			return true;
		}
	}

	return false; //Couldn't find it
}

//TODO: Comment
Action * ActionDictionary::parseAction(std::string line, bool hasStock) const {
	char actionType = line[0];

	if (isValidAction(actionType)) {
		Action* outAction = getAction(actionType);

		//outAction->parse(line);

		if (dynamic_cast<MovieAction*>(outAction) != 0) {
			MovieAction* outMovieAction = dynamic_cast<MovieAction*>(outAction);

			int customerID = std::stoi(line.substr(2, 2 + 4)); //Ignore the letter and the following space. Only grab the next 4 characters

			outMovieAction->setCustomer(customerID);

			Movie * movie = MOVIEDICTIONARY->parse(line.substr(6), true, hasStock); //The movie string should happen around the 6th index

			outMovieAction->setMovie(movie);

			return outMovieAction;
		}

		else if (dynamic_cast<CustomerAction*>(outAction) != 0) {
			CustomerAction* outCustomerAction = dynamic_cast<CustomerAction*>(outAction);

			int customerID = std::stoi(line.substr(2, 2 + 4)); //Ignore the letter and the following space. Only grab the next 4 characters

			outCustomerAction->setCustomer(customerID);
			
			return outCustomerAction;
		}
		else {
			return outAction;
		}
	}
	else {
		return 0;
	}
}
