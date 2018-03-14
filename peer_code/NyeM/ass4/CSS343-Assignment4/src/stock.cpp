#include "stock.h"

std::ostream & operator<<(std::ostream & os, const Stock & st)
{
	int stockToInt = st.getStock;
	os << st.type << stockToInt;
	return os;
}

Stock::Stock() {} //Took out parameter const string attritype

Stock::~Stock() {}

void Stock::setData(const std::string input)
{
	stringstream ss(input);
	int result;

	if (!(ss >> result)) //fails to convert
		result = 0;
	stock = result;
}

int Stock::getStock()
{
	return stock;
}