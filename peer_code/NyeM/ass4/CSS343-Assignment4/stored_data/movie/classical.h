// ------------------------------------- classical.h --------------------------------------

// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/28/18
// Date of Last Modification: 02/28/18
// ----------------------------------------------------------------------------------------
// Purpose - to hash the movie by the Classical hash rules
//     - to parse the movie by the Classical parse rules
// ----------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// ----------------------------------------------------------------------------------------

#ifndef CLASSICAL_H_
#define CLASSICAL_H_

#include "movie.h"

class Classical : public Movie
{
public:

	/*
	* Name:
	*	(no-arg) constructor for Classical movie
	* Description:
	*	Will initialize a Classical object
	*/
	Classical();

	/*
	* Name:
	*	Destructor
	* Description:
	*	Will properly delete a Classical object
	*/
	~Classical() override;

	/*
	* Name:
	*	hash()
	* Description:
	*	Will calculate a hash based on the Classical Movie and
	*	return an index at which to insert into the Movie list.
	*	The hash will be an open hash, so collision detection is
	*	not necessary.
	* Return:
	*	The index at which to insert into the Movie list
	*/
	int hash() const override;


	/*
	* Name:
	*	parse()
	* Description:
	*	Since each line from the text file is different for each type of movie, each movie type
	*	will have a parse that is a bit different
	* Return:
	*	Will return true if the parse was successful
	*/
  bool parse(std::string line, bool hasStock) override ;
};



#endif /* CLASSICAL_H_ */
