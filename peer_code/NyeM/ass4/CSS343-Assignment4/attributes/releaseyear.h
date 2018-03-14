//---------------------ReleaseYear.h-------------------------
//
// Author: Mitchell Nye CSS343 Section B (Team 7)
// Created: 2/26/2018
// Modified: 2/26/2018
//-----------------------------------------------------------
// Purpose: Stores the given string in ReleaseYear
//-----------------------------------------------------------
// Notes: 
//-----------------------------------------------------------

#ifndef RELEASEYEAR_H
#define RELEASEYEAR_H

#include "attributes/movieattribute.h"

class ReleaseYear : public virtual MovieAttribute
{
	/*
	* Name:
		Output stream << overload
	* Description:
		Will output a String-friendly representation of the Attribute
	*/
	friend std::ostream& operator<<(std::ostream&, const ReleaseYear&);

public:
	//------------------------ReleaseYear------------------------
	// Description: Default, takes in the attribute type.
	//-----------------------------------------------------------
	ReleaseYear(const string attritype);

	//---------------------- ~ReleaseYear------------------------
	// Description: Cleans up release date_released.
	//-----------------------------------------------------------
	~ReleaseYear();

	//----------------------- SetData----------------------------
	// Description: Sets the data of this attribute.
	//-----------------------------------------------------------
	void setData(const std::string input);

	//----------------------- GetYear----------------------------
	// Description: Returns the year.
	//-----------------------------------------------------------
	int getYear();

private:
	const std::string type = "Year: ";
	int year;
};
#endif // !RELEASEYEAR_H
