// ------------------------------------- customermanager.h -------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/28/18
// Date of Last Modification: 02/28/18
// ---------------------------------------------------------------------------
// Purpose - to keep track of customers and their count
	//     - to navigate file streams and parse the lines for customers
	//	   - which will then be used to initialized customer objects
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
	// Program uses virtual distructor 
// ---------------------------------------------------------------------------

#ifndef CUSTOMERMANAGER_H_
#define CUSTOMERMANAGER_H_

#include "manager.h"
#include "stored_data/customer.h"

class CustomerManager: public virtual Manager
{
public:

	/*
	* Name:
	*	Only cunstuctor for CustomerManager
	* Description:
	*	Will initialize a CustomerManager object using a file stream which 
	*   will be used to build the customers
	*/
	CustomerManager(ifstream &customersIn);

	/*
	* Name:
	*	Destructor
	* Description:z
	*	Will properly delete a CustomerManager object
	*/
	~CustomerManager();


	/*
	* Name:
	*	readFile()
	* Description:
	*	This method will simply keep navigating the input file stream
	* Return:
	*	Will return true if the file was successfully traversed
	*/
	bool readFile();


	/*
	* Name:
	*	parseType()
	* Description:
	*	This parse method will look at the first character of the movie line
	*	and then it will call the appropriate constructor of the movie type
	* Return:
	*	Will return true if the parse was succesfful
	*/
	bool parse(string movieString);

	//TODO: Document
	Customer * getCustomer(const int);

private:
	Customer * customers;	// a dynamic 1D array that will store customers
	int arraySize;			// dinmaic array size control

	int customerCount;		// counter
};

#endif /* CUSTOMERMANAGER_H_ */
