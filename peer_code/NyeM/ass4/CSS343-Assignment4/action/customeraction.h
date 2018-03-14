//============================================================================
// Name        : customeraction.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 22, 2018
// Version     : Feb 28, 2018
// Description : This is an Action that requires a Customer object to perform
//				 the Action on the Inventory object.
//============================================================================

#ifndef CUSTOMERACTION_H_
#define CUSTOMERACTION_H_

#include "action.h"


class CustomerAction : public Action {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Customer Action
	*/
	//friend std::ostream& operator<<(std::ostream&, const CustomerAction&);

private:
	int selectedCustomerID; //Selected customer to perform the action on
protected:

public:


	/*
	* Name:
	* 	1-Arg Constructor
	* Description:
	* 	Will call the Action(char) constructor and give it the given Letter
	* Parameter:
	*	The Letter to be assigned to the Letter Representation
	*/
	CustomerAction(const char action_type);

	/*
	* Name:
	* 	2-Arg Constructor
	* Description:
	* 	Will call the Action(char) constructor and give it the given Letter.
	*	Also, will set the given Customer to the selected Customer
	* Parameter:
	*	The Letter to be assigned to the Letter Reperesentation
	* Parameter:
	*	The Customer to be set to selected Customer
	*/
	CustomerAction(const char action_type, const int SELECTED_CUSTOMER);

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Will copy the contents of the given Customer Action
	* Parameter:
	*	The given Customer Action to copy from
	*/
	CustomerAction(const CustomerAction&);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly destroy the object
	*/
	virtual ~CustomerAction();

	/*
	* Name:
	* 	getCustomer
	* Description:
	* 	Gets a copy of the current Customer.
	* Return:
	*	A copy of the current Customer instance.
	*/
	int getCustomer() const;

	/*
	* Name:
	* 	setCustomer
	* Description:
	* 	Sets the Customer to the given Customer object
	* Parameter:
	*	The Customer object to assign selected Customer to.
	*/
	void setCustomer(const int);


	/*
	* Name:
	* 	parse
	* Description:
	* 	Populates the given Action based on the string input.
	*	If the string is invalid, the Action will not parse it
	*	and return false. The string that is inputed should
	*	include the letter of the Action followed by
	*	a unique customer id (represented as int)
	* Parameter:
	*	The string to parse into the Action
	* Return:
	* Whether or not the String was actually parsed.
	*/
	//virtual bool parse(std::string) override;

	/*
	* Name:
	* 	copy
	* Description:
	* 	Copies the current Action and returns
	*	a pointer to the newly constructed Action.
	* Return:
	* A pointer to the newly constructed Customer Action.
	* Returns 0 (or NULL) if it wasn't able to copy.
	*/
	virtual Action* copy() const override = 0;

	/*
	* Name:
	*	doAction
	* Description:
	* 	The instructions for what should happen to the inventory object
	* Parameter:
	*	The Inventory object that will have Actions performed upon
	* Return:
	*	Whether or not the action performed was successful or not
	*/
	virtual bool doAction(Inventory&) const override = 0;

	/*
	* Name:
	*	operator == overload
	* Description:
	* 	Checks whether or not the Actions are the same
	* Parameter:
	*	The other Action to compare with
	* Return:
	*	Whether or not the two Actions are the same
	*/
	bool operator==(const CustomerAction&) const;

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
	bool operator!=(const CustomerAction&) const;
};

#endif /* CUSTOMERACTION_H_ */

