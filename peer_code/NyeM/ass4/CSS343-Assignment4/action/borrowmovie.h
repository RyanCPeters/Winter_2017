//============================================================================
// Name        : borrowmovie.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 23, 2018
// Version     : Feb 25, 2018
// Description : The Borrow Movie will remove a Movie from the Inventory
//				 and record the Transaction for the Customer
//============================================================================

#ifndef BORROWMOVIE_H_
#define BORROWMOVIE_H_

#include "movieaction.h"

class BorrowMovie : public MovieAction {


public:

	// should this be made private?
	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the BorrowMovie
	*/
	friend std::ostream& operator<<(std::ostream&, const BorrowMovie&);


	/*
	* Name:
	* 	General (no-Arg) Constructor
	* Description:
	* 	Will call the MovieAction(char) constructor and give it the letter 'B'
	*/
	BorrowMovie();

	/*
	* Name:
	* 	1-Arg (Movie) Constructor
	* Description:
	* 	Will call the MovieAction(char, Movie) constructor and give it the 
	*   letter 'B' and the given Movie.
	* Parameter: movie
	*	The movie to assign to selected Movie
	*/
	BorrowMovie(Movie* movie);

	/*
	* Name:
	* 	1-Arg (Customer) Constructor
	* Description:
	* 	Will call the MovieAction(char, Customer) constructor 
	*	and give it the letter 'B' and the given Movie.
	* Parameter: CUSTOMERID
	*	The Customer to assign to selected Customer
	*/
	BorrowMovie(const int CUSTOMERID);

	/*
	* Name:
	* 	2-Arg Constructor
	* Description:
	* 	Will call the MovieAction(char, Movie, Customer) constructor and
	*	 give it the letter 'B' and the given Movie and Customer.
	* Parameter: movie
	*	The Movie to assign to selected Movie
	* Parameter: CUSTOMERID
	*	The Customer to assign to selected Customer
	*/
	BorrowMovie(Movie* movie, const int CUSTOMERID);

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Will copy the contents of the other Borrow Movie
	*	to the current instance
	* Parameter: OTHER
	*	The other Borrow Movie to copy the contents from
	*/
	BorrowMovie(const BorrowMovie& OTHER);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly destroy the object
	*/
	virtual ~BorrowMovie();

	/*
	* Name:
	* 	parse
	* Description:
	* 	Populates the given Action based on the string input.
	*	If the string is invalid, the Action will not parse it
	*	and return false. The string that is inputed should
	*	include the letter of the Action followed by
	*	a unique customer id (represented as int)
	*	followed by the details of the Movie
	*	(which should be parsed by the Movie class)
	* Parameter: line
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
	virtual Action* copy() const override;


	/*
	* Name:
	*	doAction
	* Description:
	* 	Will find the Movie object in storage, remove 1,
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
	bool operator==(const BorrowMovie&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the BorrowMovies are NOT the same
	* Parameter:
	*	The other BorrowMovie to compare with
	* Return:
	*	Whether or not the the two BorrowMovies are NOT the same
	*/
	bool operator!=(const BorrowMovie&) const;
};

#endif /* BORROWMOVIE_H_ */

