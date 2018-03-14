//============================================================================
// Name        : movielist.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : March 2, 2018
// Version     : March 2, 2018
// Description : TODO
//============================================================================

#ifndef MOVIELIST_H_
#define MOVIELIST_H_

#include <string>
#include <list>
#include "movie/movie.h"

class MovieList {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Action
	*/
	friend std::ostream& operator<<(std::ostream&, const MovieList&);

private:
	const char LETTER_REPRESENTATION; //The letter that represents the Action.
									  //Each derived class should have their 
									  //own unique letter
	std::list<Movie *> list;
protected:

public:

	/*
	* Name:
	* 	General (No-Args) Constructor
	* Description:
	* 	Will assign the Letter Representation to the appropriate letter.
	*	This constructor should be called everytime.
	*/
	MovieList(const char);

	/*
	* Name:
	*	Copy Constructor
	* Description:
	* 	Will copy the contents of one Action to the other
	*/
	MovieList(const MovieList&);

	/*
	* Name:
	*	Destructor
	* Description:
	* 	Should properly delete the Action object
	*/
	virtual ~MovieList();

	/*
	* Name:
	*	getLetter
	* Description:
	* 	Gets the letter of the current instance
	* Return:
	*	The letter of the current MovieList instance
	*/
	char getLetter() const;

	bool addMovie(const Movie&);
	int getStockpile(const Movie&) const;
	bool removeMovie(const Movie&);

	/*
	* Name:
	*	isSameType
	* Description:
	* 	Checks to see whether or not they have the same letter
	* Parameter:
	*	The other Movie to check the letter of
	* Return:
	*	Whether or not they are the same type (with the same letter)
	*/
	bool isSameType(const Movie&) const;
};

#endif /* MOVIELIST_H_ */

