#include "action/action.h"

//TODO
//std::ostream& operator<<(std::ostream& out, const Action&) {

//}

//TODO
Action::Action(const char c) : LETTER_REPRESENTATION(c) {}

//TODO
Action::Action(const Action& other) : LETTER_REPRESENTATION(other.getLetter()) {}

//TODO
Action::~Action() {}

//TODO
char Action::getLetter() const { return LETTER_REPRESENTATION; }

//TODO
bool Action::operator==(const Action& other) const {
	return LETTER_REPRESENTATION == other.LETTER_REPRESENTATION;
}

//TODO
bool Action::operator!=(const Action& other) const {
	return LETTER_REPRESENTATION != other.LETTER_REPRESENTATION;
}
