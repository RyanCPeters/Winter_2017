//============================================================================
// Name        : mediadictionary.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : March 2, 2018
// Version     : Marhc 2, 2018
// Description : The ActionDictionary class is a list of approved Actions that
//				 can be performed on an Inventory.
//============================================================================

#ifndef MEDIADICTIONARY_H_
#define MEDIADICTIONARY_H_

#include "media.h"
#include<ostream>
#include <set>

class MediaDictionary {
public:
	const std::set<Media *> DICTIONARY; //A final set that should be given in
										 //its constructor
	/*
	* Name:
	* 	1-Arg Constructor
	* Description:
	* 	Will assign the input set to the data set
	*/
	MediaDictionary(std::set<Media *>);

	/*
	* Name:
	*	Copy Constructor
	* Description:
	* 	Will copy the contents of one ActionDictionary to the other
	*/
	//MediaDictionary(const MediaDictionary&);

	/*
	* Name:
	*	Destructor
	* Description:
	* 	Should properly delete the Action object
	*/
	virtual ~MediaDictionary();

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
	bool isValid(const char&) const;

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
	*	Returns 0 (or NULL) if it wasn't sucessful
	*/
	Media* parse(std::string) const;
};

#endif /* MEDIADICTIONARY_H_ */