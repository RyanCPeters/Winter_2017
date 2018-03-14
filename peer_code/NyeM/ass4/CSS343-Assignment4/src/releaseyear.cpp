#include "releaseyear.h"

ReleaseYear::ReleaseYear(const string attritype)
{
	setData(attritype);
}

ReleaseYear::~ReleaseYear() {}

void ReleaseYear::setData(const std::string input)
{
	stringstream ss(input);
	int result;

	if (!(ss >> result)) //fails to convert
		result = 0;
	year = result;
}

int ReleaseYear::getYear()
{
	return year;
}

std::ostream & operator<<(std::ostream & os, const ReleaseYear & relYear)
{
	os << relYear.type;
	return os;
}