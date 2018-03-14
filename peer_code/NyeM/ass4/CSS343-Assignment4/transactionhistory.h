//============================================================================
// Name        : transactionhistory.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 22, 2018
// Version     : Feb 27, 2018
// Description : The TransactionHistory is a Stack of CustomerActions that 
//				 That the customer has performed so far.
//============================================================================

#ifndef TRANSACTIONHISTORY_H_
#define TRANSACTIONHISTORY_H_

#include <stack>

class TransactionHistory {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the TransactionHistory
	*/
	friend std::ostream& operator<<(std::ostream&, const TransactionHistory&);
private:
	std::stack<const CustomerAction> transactHistory;

public:

	/*
	* Name:
	* 	General (No-Args) Constructor
	* Description:
	* 	Will assign root to be 0 (or NULL)
	*/
	TransactionHistory();

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Will copy the contents from the other TransactionHistory
	* Parameter:
	*	The other TransactionHisotry to copy from.
	*/
	TransactionHistory(const TransactionHistory&);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Should (properly) delete every Node in the structure
	*	and set root to 0
	*/
	virtual ~TransactionHistory();

	/*
	* Name:
	* 	addTransaction
	* Description:
	* 	Should push it on the Stack
	* Parameter:
	*	The customer to add to the Stack
	*/
	void addTransaction(const CustomerAction&);
};

#endif /* TRANSACTIONHISTORY_H_ */
