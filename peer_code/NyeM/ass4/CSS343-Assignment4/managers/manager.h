// ------------------------------------- manager.h ----------------------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/28/18
// Date of Last Modification: 02/28/18
// ----------------------------------------------------------------------------------------
// Purpose - to serve as an abstract class
//     - to guide child managers
// ----------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
	// Program uses virtual distructor 
// ----------------------------------------------------------------------------------------

#ifndef MANAGER_H_
#define MANAGER_H_

#include <string>
#include <iostream>
#include <fstream>
using namespace std;

class Manager
{
public:

	/*
	* Name:
	*	(no-arg) cunstuctor for Manager
	* Description:
	*	Will initialize a Manager object
	*/
	Manager();


	/*
	* Name:
	*	Destructor
	* Description:z
	*	Will properly delete a Manager object and its children
	*/
	virtual ~Manager();


	/*
	* Name:
		readFile
	* Description:
		Will allow child classes to make their own rules on reading input file
	*/
	virtual bool readFile() = 0;


	/*
	* Name:
		parseLine
	* Description:
		Will allow child classes to make their own parsing algorythms
	*/
	virtual bool parse(string movieString) = 0;
};

#endif /*MANAGER_H_*/