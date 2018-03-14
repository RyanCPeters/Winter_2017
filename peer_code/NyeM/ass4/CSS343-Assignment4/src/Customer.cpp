#include "customer.h"

Customer::Customer(std::string first, std::string last, int id) : FIRST_NAME(first), LAST_NAME(last), ID(id) {}

Customer::Customer(const Customer & cust) : FIRST_NAME(cust.FIRST_NAME), LAST_NAME(cust.LAST_NAME), ID(cust.ID) {}

Customer::~Customer() {}

void Customer::printHistory() const
{
	DisplayTransactionHistory displayTransHistory = DisplayTransactionHistory(ID);
}

void Customer::addTransaction(const CustomerAction & action)
{
	transactHistory.addTransaction(action);
}

int Customer::hash() const
{
	return ID; //Need to implement hash
}

bool Customer::operator==(const Customer & other) const
{
	return (*this == other);
}

bool Customer::operator!=(const Customer & other) const
{
	return !(*this == other);
}