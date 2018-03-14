// ------------------------------------- inventory.h --------------------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/27/18
// Date of Last Modification: 02/28/18
// ----------------------------------------------------------------------------------------
// Purpose - to take in the customer, movie, and comand files
	//     - to initialize the two managers and the dictionary
// ----------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
	// uses smart reusable functions that can help to change to a new set of customers
	// and movies, and then it can be given a new set of commands whenever needed.
// ----------------------------------------------------------------------------------------

#ifndef INVENTORY_H_
#define INVENTORY_H_

#include "managers/moviemanager.h"
#include "actiondictionary.h"
#include "managers/customermanager.h"
using namespace std;

class Inventory
{

	friend std::ostream& operator<<(std::ostream&, const Inventory&);
public:
	/*
	* Name:
		(no-arg) cunstuctor for Inventory
	* Description:
		Will initialize an Inventory object
	*/
	Inventory();


	/*
	* Name:
		Cunstuctor for Inventory
	* Description:
		Will initialize an Inventory object with the two files given
		The constructor will pass the files to the respective feed functions
		which will then create the movie and customer managers
	*/
	Inventory(ifstream &moviesIn, ifstream &customersIn);


	/*
	* Name:
		Destructor
	* Description:z
		Will properly delete an Inventory object
	*/
	~Inventory();


	/*
	* Name:
	*	feedMovies()
	* Description:
	*	Will build the entire movie manager
	* Parameter(s):
	*	the input is a file stream which can be passed dirrectly through main or 
	*	by the constructor
	*/
	void feedMovies(ifstream &moviesIn);


	/*
	* Name:
	*	feedCustomers()
	* Description:
	*	Will build the entire customer manager
	* Parameter(s):
	*	the input is a file stream which can be passed dirrectly through main or
	*	by the constructor
	*/
	void feedCustomers(ifstream &customersIn);


	/*
	* Name:
	*	executeCommands()
	* Description:
	*	Will build the entire actionDictionary and start executing each command
	* Parameter(s):
	*	the input is a file stream which can be passed dirrectly through main
	*	it is a very handy function because it can be given new command files anytime
	*/
	void executeCommands(ifstream &commands);

private:
	MovieManager movieMg;
	CustomerManager customerMg;
	ActionDictionary actionDict;
};

#endif /* INVENTORY_H_ */
