// ------------------------------- MovieAttribute.h --------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/26/18
// Date of Last Modification: 02/27/18
// ---------------------------------------------------------------------------
// Purpose - to serve as an abstract class
	//     - to guide child attributes
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
	// Program uses virtual distructor 
// ---------------------------------------------------------------------------

#ifndef MOVIEATTRIBUTE_H_
#define MOVIEATTRIBUTE_H_

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

class MovieAttribute
{

public:

	/*
	* Name:
		(no-arg) cunstuctor for MovieAttribute
	* Description:
		Will initialize a MovieAttribute object
	*/
	MovieAttribute();

	/*
	* Name:
		Destructor
	* Description:z
		Will properly delete a MovieAttribute object and its children
	*/
	virtual ~MovieAttribute();

	/*
	* Name:
		setData
	* Description:
		Will allow child classes to make their own rules on the data stored
	*/
	virtual void setData(const string input) = 0;
};

#endif /* MOVIEATTRIBUTE_H_ */