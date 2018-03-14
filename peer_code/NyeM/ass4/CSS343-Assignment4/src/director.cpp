#include "director.h"

std::ostream & operator<<(std::ostream & os, const Director & dir)
{
	os << dir.type << dir.getFullName();
	return os;
}

Director::Director(const string inputD)
{
	setData(inputD);
}

Director::~Director() {}

void Director::setData(const string fullName)
{
	stringstream ss;
	ss << fullName;

	ss >> firstName >> lastName;
}

string Director::getFirstName() const
{
	return firstName;
}

string Director::getLastName() const
{
	return lastName;
}

string Director::getFullName() const
{
	return getFirstName() + " " + getLastName();
}