//---------------------MajorActor.h--------------------------
//
// Author: Mitchell Nye CSS343 Section B (Team 7)
// Created: 2/26/2018
// Modified: 2/26/2018
//-----------------------------------------------------------
// Purpose: Stores the given string in a major actor.
//-----------------------------------------------------------
// Notes: 
//-----------------------------------------------------------

#ifndef MAJORACTOR_H
#define MAJORACTOR_H

#include "attributes/movieattribute.h"

class MajorActor : public virtual MovieAttribute
{
	/*
	* Name:
		Output stream << overload
	* Description:
		Will output a String-friendly representation of the Attribute
	*/
	friend std::ostream& operator<<(std::ostream&, const MajorActor&);

public:

	//-------------------------MajorActor------------------------
	// Description: Default, takes in the attribute type.
	//-----------------------------------------------------------
	MajorActor(const string attritype);

	//----------------------- ~MajorActor------------------------
	// Description: Cleans up MajorActor.
	//-----------------------------------------------------------
	~MajorActor();

	//----------------------- SetData----------------------------
	// Description: Sets the data of this attribute.
	//-----------------------------------------------------------
	void setData(const string input);

	//----------------------- GetData----------------------------
	// Description: Gets the data of this attribute.
	//-----------------------------------------------------------
	string getData();

private:
	const std::string type = "Major Actor: ";
	std::string data;
};
#endif // !MAJORACTOR_H