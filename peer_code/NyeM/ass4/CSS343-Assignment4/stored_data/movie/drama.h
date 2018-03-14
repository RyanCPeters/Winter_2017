// --------------------------------------- drama.h ----------------------------------------

// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/28/18
// Date of Last Modification: 02/28/18
// ----------------------------------------------------------------------------------------
// Purpose - to hash the movie by the drama hash rules
//     - to parse the movie by the drama parse rules
// ----------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// ----------------------------------------------------------------------------------------

#ifndef DRAMA_H_
#define DRAMA_H_

#include "movie.h"

class Drama : public Movie
{
public:

	/*
	* Name:
	*	(no-arg) cunstuctor for Drama movie
	* Description:
	*	Will initialize a Drama object
	*/
	Drama();

	/*
	* Name:
	*	Destructor
	* Description:
	*	Will properly delete a Drama object
	*/
	~Drama() override;

	/*
	* Name:
	*	hash()
	* Description:
	*	Will calculate a hash based on the Drama Movie and
	*	return an index at which to insert into the Movie list.
	*	The hash will be an open hash, so collision detection is
	*	not neccessary.
	* Return:
	*	The index at which to insert into the Movie list
	*/
	int hash() const override;


	/*
	* Name:
	*	parse()
	* Description:
	*	Since each line from the txt file is different for each type of movie, each movie type
	*	will have a parse that is a bit different
	* Return:
	*	Will return true if the parse was succesfful
	*/
  bool parse(const std::string line, bool hasStock);
};

#endif /* DRAMA_H_ */
