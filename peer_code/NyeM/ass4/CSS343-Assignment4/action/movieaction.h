//============================================================================
// Name        : movieaction.h
// Author(s)   : Team 7 (Brady Pascoe)
// Created     : Feb 22, 2018
// Version     : Feb 28, 2018
// Description : The Movie Action is a Customer Action that requires a 
//				 selected Movie object in order to perform the action.
//============================================================================

#ifndef MOVIEACTION_H_
#define MOVIEACTION_H_

#include "customeraction.h"
#include "stored_data/movie/movie.h"

class MovieAction : public CustomerAction {

	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the MovieAction
	*/
	//friend std::ostream& operator<<(std::ostream&, const MovieAction&);
private:
	Movie* selectedMovie; //Selected Movie to find in inventory

protected:
public:

	/*
	* Name:
	* 	1-Arg Constructor
	* Description:
	* 	Will call the CustomerAction(char) constructor and give it the given 
	*   Letter
	* Parameter:
	*	The Letter to be assigned to the Letter Reperesentation
	*/
	MovieAction(const char);

	/*
	* Name:
	* 	2-Arg (const char, const Movie&) Constructor
	* Description:
	* 	Will call the CustomerAction(char) constructor
	*	and give it the given Letter
	*	Also, will set the selected Movie to the given Movie
	* Parameter:
	*	The Letter to be assigned to the Letter Reperesentation
	* Parameter:
	*	The Movie to be set to selected Movie
	*/
	MovieAction(const char, Movie*);

	/*
	* Name:
	* 	2-Arg (const char, const Customer&) Constructor
	* Description:
	* 	Will call the CustoemrAction(char, const Customer&) constructor 
	*	and give it the given Letter and Customer
	*	Also, will set the selected Movie to default
	* Parameter:
	*	The Letter to be assigned to the Letter Reperesentation
	* Parameter:
	*	The Customer to be set to selected Customer
	*/
	MovieAction(const char, const int);

	/*
	* Name:
	* 	3-Arg Constructor
	* Description:
	* 	Will call the CustoemrAction(char, const Customer&) constructor
	*	and give it the given Letter and Customer
	*	Also, will set the selected Movie to the given Movie
	* Parameter:
	*	The Letter to be assigned to the Letter Reperesentation
	* Parameter:
	*	The Movie to be assigned to selected Movie
	* Parameter:
	*	The Customer to be set to selected Customer
	*/
	MovieAction(const char, Movie*, const int);

	/*
	* Name:
	* 	Copy Constructor
	* Description:
	* 	Will copy the contents of the given Movie Action
	* Parameter:
	*	The given Movie Action to copy from
	*/
	MovieAction(const MovieAction&);

	/*
	* Name:
	* 	Destructor
	* Description:
	* 	Will properly destroy the object
	*/
	virtual ~MovieAction();

	/*
	* Name:
	* 	setMovie
	* Description:
	* 	Sets the Movie to the given Movie object
	* Parameter:
	*	The Movie object to assign selected Movie to.
	*/
	void setMovie(Movie*);

	/*
	* Name:
	* 	getMovie
	* Description:
	* 	Gets a copy of the current Movie.
	* Return:
	*	A copy of the current Movie instance.
	*/
	Movie* getMovie() const;

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
	* 	Checks whether or not the MovieActions are the same
	* Parameter:
	*	The other MovieAction to compare with
	* Return:
	*	Whether or not the the two MovieActions are the same
	*/
	bool operator==(const MovieAction&) const;

	/*
	* Name:
	*	operator != overload
	* Description:
	* 	Checks whether or not the MovieActions are NOT the same
	* Parameter:
	*	The other MovieAction to compare with
	* Return:
	*	Whether or not the the two MovieActions are NOT the same
	*/
	bool operator!=(const MovieAction&) const;
};

#endif /* MOVIEACTION_H_ */

