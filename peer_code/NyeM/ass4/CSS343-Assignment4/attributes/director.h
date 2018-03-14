// ---------------------------------- Director.h -------------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/26/18
// Date of Last Modification: 02/27/18
// -----------------------------------------------------------------------------
// Purpose - to store movie directors
//     - to put limits on the director name length
// -----------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
	// setData() for director uses a string, the string can't be longer than 
// -----------------------------------------------------------------------------

#ifndef DIRECTOR_H_
#define DIRECTOR_H_

#include "attributes/movieattribute.h"

class Director : public virtual MovieAttribute
{
	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Attribute
	*/
	friend std::ostream& operator<<(std::ostream&, const Director&);

public:

	/*
	* Name:
		input initialized Director
	* Description:
		Will initialize a Director object and use setData() to fill
	* Parameter(s):
		the input string will be a full name, given by movieManager parser. 
		the constructor will pass the full string to setData() and it will
		take care of separating into first 
		and last names
	*/
	Director(const string inputD);


	/*
	* Name:
		Destructor
	* Description:
		Will properly delete a Title object and go on to the parent
	*/
	~Director();


	/*
	* Name:
	*	setData
	* Description:
	*	Works with strings to fill in the first and last name of the Director
	* Parameter(s):
	*	the input string will be a full name, given by constructor or parser.
	*   he function will split
	*	the full name into first and last name and assign them.
	*/
	void setData(const string fullName);	


	/*
	* Name:
		getFirstName
	* Description:
		returns just the first name as a string
	*/
	string getFirstName() const;


	/*
	* Name:
		getLastName
	* Description:
		returns just the last name as a string
	*/
	string getLastName() const;


	/*
	* Name:
		getFullName
	* Description:
		returns the concatination of first and last name as a string
	*/
	string getFullName() const;


private:
	const string type = "Director: ";	// will always be the same
	string firstName;	// will store the first name
	string lastName;	// will store the last name
};

#endif