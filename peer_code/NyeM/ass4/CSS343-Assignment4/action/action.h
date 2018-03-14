//============================================================================
// Name        : action.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 22, 2018
// Version     : Feb 28, 2018
// Description : The Action class defines different Actions (or commands)
//				 that can be performed on Inventory.
//============================================================================

#ifndef ACTION_H_
#define ACTION_H_

//#include "inventory.h"
class Inventory {}; //Declared here for testing purposes

#include <string>

class Action {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Action
	*/
	//friend std::ostream& operator<<(std::ostream&, const Action&);

private:
	const char LETTER_REPRESENTATION; //The letter that represents the Action.
									  //Each derived class should have their 
									  //own unique letter
protected:

public:

	/*
	* Name:
	* 	General (No-Args) Constructor
	* Description:
	* 	Will assign the Letter Representation to the appropriate letter.
	*	This constructor should be called everytime.
	*/
	Action(const char);

	/*
	* Name:
	*	Copy Constructor
	* Description:
	* 	Will copy the contents of one Action to the other
	*/
	Action(const Action&);

	/*
	* Name:
	*	Destructor
	* Description:
	* 	Should properly delete the Action object
	*/
	virtual ~Action();

	/*
	* Name:
	*	getLetter
	* Description:
	* 	Gets the letter of the current instance
	* Return:
	*	The letter of the current Action instance
	*/
	char getLetter() const;

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
	virtual bool doAction(Inventory&) const = 0;

	/*
	* Name:
	* 	parse
	* Description:
	* 	Populates the given Action based on the string input.
	*	If the string is invalid, the Action will not parse it
	*	and return false.
	* Parameter:
	*	The string to parse into the Action
	* Return:
	* Whether or not the String was actually parsed.
	*/
	//virtual bool parse(std::string) = 0;

	/*
	* Name:
	* 	copy
	* Description:
	* 	Copies the current Action and returns
	*	a pointer to the newly constructed Action.
	* Return:
	* A pointer to the newly constructed Action.
	* Returns 0 (or NULL) if it wasn't able to copy.
	*/
	virtual Action* copy() const = 0;

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
	virtual bool operator==(const Action&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the Actions are NOT the same
	* Parameter:
	*	The other Action to compare with
	* Return:
	*	Whether or not the the two Actions are NOT the same
	*/
	virtual bool operator!=(const Action&) const;

	/*
	* Name:
	*	isSameType
	* Description:
	* 	Checks to see whether or not they have the same letter
	* Parameter:
	*	The other Action to check the letter of
	* Return:
	*	Whether or not they are the same type (with the same letter)
	*/
	//bool isSameType(const Action&) const;
};

#endif /* ACTION_H_ */

