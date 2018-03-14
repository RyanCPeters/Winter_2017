//============================================================================
// Name        : moviedictionary.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : March 5, 2018
// Version     : Marhc 5, 2018
// Description : The ActionDictionary class is a list of approved Actions that
//				 can be performed on an Inventory.
//============================================================================

#ifndef MOVIEDICTIONARY_H_
#define MOVIEDICTIONARY_H_

#include "stored_data/movie/movie.h"
#include "mediadictionary.h"
#include<ostream>
#include <set>

class MovieDictionary {
private:
	MediaDictionary mediaDict;
public:
	const std::set<Movie *> DICTIONARY; //A final set that should be given in
										//its constructor
										/*
										* Name:
										* 	1-Arg Constructor
										* Description:
										* 	Will assign the input set to the data set
										*/
	MovieDictionary(std::set<Movie *>, std::set<Media *>);

	/*
	* Name:
	*	Copy Constructor
	* Description:
	* 	Will copy the contents of one ActionDictionary to the other
	*/
	//MovieDictionary(const MovieDictionary&);

	/*
	* Name:
	*	Destructor
	* Description:
	* 	Should properly delete the Action object
	*/
	virtual ~MovieDictionary();

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
	Movie* parse(std::string, bool, bool) const;
};

#endif /* MOVIEDICTIONARY_H_ */
