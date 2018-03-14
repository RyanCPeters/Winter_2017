//============================================================================
// Name        : actiondictionary.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 26, 2018
// Version     : Feb 27, 2018
// Description : The ActionDictionary class is a list of approved Actions that
//				 can be performed on an Inventory.
//============================================================================

#ifndef ACTIONDICTIONARY_H_
#define ACTIONDICTIONARY_H_

#include "action/action.h"
#include "moviedictionary.h"
#include <ostream>
#include <set>

class ActionDictionary {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Action
	*/
	//friend std::ostream& operator<<(std::ostream&, const ActionDictionary&);
private:
	Action* getAction(const char) const;
	const MovieDictionary * const MOVIEDICTIONARY;
public:
	const std::set<Action *> DICTIONARY; //A final set that should be given in
										 //its constructor
	/*
	* Name:
	* 	1-Arg Constructor
	* Description:
	* 	Will assign the input set to the data set
	*/
	ActionDictionary(std::set<Action *>, const MovieDictionary *);

	/*
	* Name:
	*	Copy Constructor
	* Description:
	* 	Will copy the contents of one ActionDictionary to the other
	*/
	//ActionDictionary(const ActionDictionary&);

	/*
	* Name:
	*	Destructor
	* Description:
	* 	Should properly delete the Action object
	*/
	virtual ~ActionDictionary();

	/*
	* Name:
	*	isValidAction
	* Description:
	* 	Checks to see if the given Action is valid
	*	by comparing it with every definitions'
	*	type currently in the dictionary and see
	*	if it exists.
	* Parameter:
	*	The char of the type of Action
	*/
	bool isValidAction(const char&) const;

	/*
	* Name:
	*	parseAction
	* Description:
	* 	Parses the given string into an Action
	*	(if it is parsable) as long as it is a valid
	*	Action (check if it exists in the Dictionary)
	* Parameter:
	*	The string to be parsed
	* Return:
	*	The Action that was created from the Parse.
	*	Returns 0 (or NULL) if it wasn't successful
	*/
	Action* parseAction(std::string, bool) const;
};

#endif /* ACTIONDICTIONARY_H_ */
