// -------------------------------------- comedy.h ----------------------------------------

// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/28/18
// Date of Last Modification: 02/28/18
// ----------------------------------------------------------------------------------------
// Purpose - to hash the movie by the comedy hash rules
	//     - to parse the movie by the comedy parse rules
// ----------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// ----------------------------------------------------------------------------------------

#ifndef COMEDY_H_
#define COMEDY_H_

#include "movie.h"

class Comedy : public Movie
{
public:

	/*
	* Name:
	*	(no-arg) cunstuctor for Comedy movie
	* Description:
	*	Will initialize a Comedy object
	*/
	Comedy();


	Comedy(int, std::string, std::string, int);

	/*
	* Name:
	*	Destructor
	* Description:
	*	Will properly delete a Comedy object
	*/
	~Comedy() override;

	/*
	* Name:
	*	hash()
	* Description:
	*	Will calculate a hash based on the Comedy Movie and
	*	return an index at which to insert into the Movie list.
	*	The hash will be an open hash, so collision detection is
	*	not neccessary.
	* Return:
	*	The index at which to insert into the Movie list
	*/
	//int hash() const;


	/*
	* Name:
	*	parse()
	* Description:
	*	Since each line from the txt file is different for each type of movie, each movie type
	*	will have a parse that is a bit different
	* Return:
	*	Will return true if the parse was succesfful
	*/
	bool parse(std::string line, bool hasStock) override;

	int hash() const override;
};

#endif /* COMEDY_H_ */
