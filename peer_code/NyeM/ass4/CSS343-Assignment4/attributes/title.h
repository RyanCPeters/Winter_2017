// --------------------------- Title.h --------------------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/26/18
// Date of Last Modification: 02/27/18
// --------------------------------------------------------------------------
// Purpose - to store movie titles
	//     - to put limits on the title length
// --------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
	// setData() for title uses a string, but the string can't be longer than 
// --------------------------------------------------------------------------

#ifndef TITLE_H_
#define TITLE_H_

#include "attributes/movieattribute.h"

class Title: public virtual MovieAttribute
{
	/*
	* Name:
	* 	Output stream << overload
	* Description:
	* 	Will output a String-friendly representation of the Attribute
	*/
	friend std::ostream& operator<<(std::ostream&, const Title&);

public:

	/*
	* Name:
		input initialized Title
	* Description:
		Will initialize a Title object and use setData() to fill
	* Parameter(s):
		the input string will be a full title, given by movieManager parser. 
		the constructor will pass the full string to setData() and it will 
		take care of filling the data string
	*/
	Title(const string inputD);


	/*
	* Name:
		Destructor
	* Description:
		Will properly delete a Title object and go on to the parent
	*/
	~Title();

	/*
	* Name:
		setData
	* Description:
		Works with strings to fill in the title
	*/
	void setData(const string inputD); 

	/*
	* Name:
		getFirstName
	* Description:
		returns just the title as a string
	*/
	string getTitle() const;

private:
	const string type = "Title: ";	// will always be the same
	string title;					// will store the title
};

#endif