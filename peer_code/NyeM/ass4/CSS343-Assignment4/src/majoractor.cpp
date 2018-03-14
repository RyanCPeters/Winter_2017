#include "attributes/majoractor.h"

std::ostream & operator<<(std::ostream & os, const MajorActor & majAct)
{
	os << majAct.type << majAct.data;
	return os;
}

MajorActor::MajorActor(const string attritype)
{
	setData(attritype);
}

MajorActor::~MajorActor() {}

void MajorActor::setData(const string input)
{
	data = input;
}

string MajorActor::getData()
{
	return data;
}
