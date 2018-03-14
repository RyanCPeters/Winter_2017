//============================================================================
// Name        : Customer.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 22, 2018
// Version     : Feb 25, 2018
// Description : The Customer class is a class that has a first name, last,
//				 Unique ID, and a Transaction History.
//============================================================================

#ifndef CUSTOMER_H_
#define CUSTOMER_H_

#include "storeddata.h"
#include "transactionhistory.h"
#include "displaytransactionhistory.h"
#include "customeraction.h"
#include <string>

class Customer : public StoredData {
private:
	TransactionHistory transactHistory; //The History of Transactions for 
									    //the current instance

public:
	const std::string FIRST_NAME, LAST_NAME; //The first and last 
											 //name of the Customer
	const int ID; //The Customer's unique ID

	/*
	* Name:
	* 	3-Arg Constructor
	* Description:
	* 	Will initialize everything with the given parameters.
	* Parameter:
	*	The first name of the Customer
	* Parameter:
	*	The last name of the Customer
	* Parameter:
	*	The Customer's unique ID
	*/
	Customer(std::string, std::string, int);

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Will copy the contents from the given Customer
	* Parameter:
	*	The other Customer to copy from
	*/
	Customer(const Customer&);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly destroy the Customer Object
	*/
	virtual ~Customer();

	/*
	* Name:
	* 	printHistory
	* Description:
	* 	Will print the TransactionHistory to the console
	*/
	void printHistory() const;

	/*
	* Name:
	* 	addTransaction
	* Description:
	* 	Adds the given CustomerAction to TransactionHistory
	* Parameter:
	*	The CustomerAction to add.
	*/
	void addTransaction(const CustomerAction&);

	/*
	* Name:
	* 	hash()
	* Description:
	* 	Will calculate a hash based on the Customer instance and
	*	return an index at which to insert into the Manager list.
	*	The hash will be an open hash, so collision detection is
	*	not neccessary.
	* Return:
	*	The index at which to insert into the Manager list
	*/
	virtual int hash() const override;

	/*
	* Name:
	*	operator == overload
	* Description:
	* 	Checks whether or not the Customers 
	*	(excluding the TransactionHistories) are the same
	* Parameter:
	*	The other Customer to compare with
	* Return:
	*	Whether or not the the two Customers are the same
	*/
	bool operator==(const Customer&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the Customers 
	*	(excluding the TransactionHistories) are NOT the same
	* Parameter:
	*	The other Customer to compare with
	* Return:
	*	Whether or not the the two Customers are NOT the same
	*/
	bool operator!=(const Customer&) const;
};

#endif /* CUSTOMER_H_ */