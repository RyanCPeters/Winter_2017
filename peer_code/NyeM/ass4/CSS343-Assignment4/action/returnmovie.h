//============================================================================
// Name        : returnmovie.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 23, 2018
// Version     : Feb 25, 2018
// Description : The Return Movie will add a Movie from the Inventory
//				 and record the Transaction for the Customer
//============================================================================

#ifndef RETURNMOVIE_H_
#define RETURNMOVIE_H_

#include "action/movieaction.h"

class ReturnMovie : public MovieAction {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the ReturnMovie
	*/
	friend std::ostream& operator<<(std::ostream&, const ReturnMovie&);

public:

	/*
	* Name:
	* 	General (no-Arg) Constructor
	* Description:
	* 	Will call the MovieAction(char) constructor and give it the letter 'R'
	*/
	ReturnMovie();


	/*
	* Name:
	* 	1-Arg (Movie) Constructor
	* Description:
	* 	Will call the MovieAction(char, Movie) constructor and give it the 
	*	letter 'R' and the given Movie.
	* Parameter:
	*	The movie to assign to selected Movie
	*/
	ReturnMovie(Movie*);

	/*
	* Name:
	* 	1-Arg (Customer) Constructor
	* Description:
	* 	Will call the MovieAction(char, Customer) constructor and give it 
	*	the letter 'R' and the given Movie.
	* Parameter:
	*	The Customer to assign to selected Customer
	*/
	ReturnMovie(const int);

	/*
	* Name:
	* 	2-Arg Constructor
	* Description:
	* 	Will call the MovieAction(char, Movie, Customer) constructor 
	*	and give it the letter 'R' and the given Movie and Customer.
	* Parameter:
	*	The Movie to assign to selected Movie
	* Parameter:
	*	The Customer to assign to selected Customer
	*/
	ReturnMovie(Movie*, const int);

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Will copy the contents of the other Return Movie
	*	to the current instance
	* Parameter:
	*	The other Return Movie to copy the contents from
	*/
	ReturnMovie(const ReturnMovie&);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly destroy the object
	*/
	virtual ~ReturnMovie();

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
	virtual Action* copy() const override;

	/*
	* Name:
	*	doAction
	* Description:
	* 	Will add the selected Movie to the Inventory
	*	and then find the Customer object and record the Transaction
	*	in their TransactionHistory
	* Parameter:
	*	The Inventory object that will have Actions performed upon
	* Return:
	*	Whether or not the action performed was successful or not
	*/
	virtual bool doAction(Inventory&) const override;

	/*
	* Name:
	*	operator == overload
	* Description:
	* 	Checks whether or not the BorrowMovies are the same
	* Parameter:
	*	The other BorrowMovie to compare with
	* Return:
	*	Whether or not the the two BorrowMovies are the same
	*/
	bool operator==(const ReturnMovie&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the ReturnMovies are NOT the same
	* Parameter:
	*	The other ReturnMovie to compare with
	* Return:
	*	Whether or not the the two ReturnMovies are NOT the same
	*/
	bool operator!=(const ReturnMovie&) const;
};

#endif /* RETURNMOVIE_H_ */

