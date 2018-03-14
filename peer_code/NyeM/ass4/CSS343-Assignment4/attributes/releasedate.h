//---------------------ReleaseDate.h-------------------------
//
// Author: Mitchell Nye CSS343 Section B (Team 7)
// Created: 2/26/2018
// Modified: 2/26/2018
//-----------------------------------------------------------
// Purpose: Stores the given string in ReleaseDate
//-----------------------------------------------------------
// Notes: 
//-----------------------------------------------------------

#ifndef RELEASEDATE_H
#define RELEASEDATE_H

#include "attributes/movieattribute.h"

class ReleaseDate : public virtual MovieAttribute
{
	/*
	* Name:
	 	Output stream << overload
	* Description:
	 	Will output a String-friendly representation of the Attribute
	*/
	friend std::ostream& operator<<(std::ostream&, const ReleaseDate&);

public:
	//------------------------ReleaseDate------------------------
	// Description: Default, takes in the attribute type.
	//-----------------------------------------------------------
	ReleaseDate(const string attritype);

	//---------------------- ~ReleaseDate------------------------
	// Description: Cleans up release date_released.
	//-----------------------------------------------------------
	~ReleaseDate();

	//----------------------- SetData----------------------------
	// Description: Sets the data of this attribute.
	//-----------------------------------------------------------
	void setData(const std::string input);

	//----------------------- GetMonth---------------------------
	// Description: Returns the month.
	//-----------------------------------------------------------
	int getMonth();

	//----------------------- GetYear----------------------------
	// Description: Returns the year.
	//-----------------------------------------------------------
	int getYear();

	//----------------------- GetDate----------------------------
	// Description: Returns the month and year together
	//-----------------------------------------------------------
	string getDate();

private:
	const std::string type = "Release Date: ";
	int month;
	int year;
};
#endif // !RELEASEDATE_H
