// ----------------------------------- moviemanager.h -------------------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/27/18
// Date of Last Modification: 02/27/18
// ----------------------------------------------------------------------------------------
// Purpose - to keep track of movies and their counts
	//     - to navigate file streams and parse the type of movie
	//	   - which will then be used to initialized a specific type movie
// ----------------------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// ----------------------------------------------------------------------------------------

#ifndef MOVIEMANAGER_H_
#define MOVIEMANAGER_H_

#include "manager.h"
/*
#include "movie.h"
#include "comedy.h"
#include "drama.h"
*/
#include "movielist.h"
#include "mediadictionary.h"

class MovieManager: public virtual Manager
{
public:

	/*
	* Name:
	*	Only constructor for MovieManager
	* Description:
	*	Will initialize a MovieManager object using a file stream which will be used
	*	to build the movies
	*/
	MovieManager(ifstream &moviesIn);

	/*
	* Name:
	*	Destructor
	* Description:z
	*	Will properly delete a MovieManager object
	*/
	~MovieManager();


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
	*	Will return true if the parse was successful
	*/
	bool parse(string) override;

	//TODO: Document
	bool canAddMovie(const Movie&) const;

	//TODO: Document
	Movie * getMovie();

	//Used 
	bool compare(std::string myKey, std::string mapKey) 
	{
		return (myKey.compare(mapKey) < 0);
	}


private:
	/*
	Movie * movies;		// a dynamic 2D array
	int rowSize;		// row control
	int columnSize;		// column control

	int movieCount;
	int comedyCount;	//counters
	int dramaCount;
	int classicCount;
	*/
	vector<MovieList> movies;
	MediaDictionary mediaDic;



	//add map for holding movies
};

#endif /* MOVIEMANAGER_H_ */
