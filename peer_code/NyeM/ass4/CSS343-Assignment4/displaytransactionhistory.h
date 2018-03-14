//============================================================================
// Name        : displaytransactionhistory.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 25, 2018
// Version     : Feb 25, 2018
// Description : The DisplayTransactionHistory will print out the selected
//				 customer inside the Inventory (if it's contained within
//				 Inventory).
//============================================================================

#ifndef DISPLAYTRANSACTIONHISTORY_H_
#define DISPLAYTRANSACTIONHISTORY_H_

#include "action/customeraction.h"

class DisplayTransactionHistory : public CustomerAction {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the 
	*   DisplayTransactionHistory
	*/
	//friend std::ostream& operator<<(std::ostream&, const 
	//	DisplayTransactionHistory&);
public:

	/*
	* Name:
	* 	General (no-Arg) Constructor
	* Description:
	* 	Will call the CustomerAction(char) constructor and give it the 
	*   letter 'H'
	*/
	DisplayTransactionHistory();

	/*
	* Name:
	* 	1-Arg Constructor
	* Description:
	* 	Will call the CustomerAction(char, const Customer&) constructor 
	*	and give it the letter 'H'.
	*	Also, will set the given Customer to the selected Customer
	* Parameter:
	*	The customer id to find
	*/
	DisplayTransactionHistory(const int);

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Copies the contents of one DisplayTransactionHistory
	*	To the other.
	* Parameter:
	*	The DisplayTransactionHistory to copy the contents from.
	*/
	DisplayTransactionHistory(const DisplayTransactionHistory&);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly destroy the object
	*/
	virtual ~DisplayTransactionHistory();

	/*
	* Name:
	*	doAction
	* Description:
	* 	Should find the selectedCustomer and print out the TransactionHistory
	*	(Unless the selectedCustomer was not found)
	* Parameter:
	*	The Inventory object that will have Actions performed upon
	* Return:
	*	Whether or not the action performed was successful or not
	*/
	virtual bool doAction(Inventory&) const;

	//virtual bool parse(std::string) override;

	virtual Action* copy() const override;

	/*
	* Name:
	*	operator == overload
	* Description:
	* 	Checks whether or not the Actions are the same
	* Parameter:
	*	The other Action to compare with
	* Return:
	*	Whether or not the the two Actions are the same
	*/
	bool operator==(const DisplayTransactionHistory&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the Actions are NOT the same
	* Parameter:
	*	The other Action to compare with
	* Return:
	*	Whether or not the two Actions are NOT the same
	*/
	bool operator!=(const DisplayTransactionHistory&) const;
};

#endif /* DISPLAYTRANSACTIONHISTORY_H_ */

