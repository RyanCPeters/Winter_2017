// -------------------------------------- movie.h ----------------------------
// 
// Programmer Name Course Section Number: Team 7 (Daniel Bragaru - CSS 343 B)
// Creation Date: 02/28/18
// Date of Last Modification: 02/28/18
// ---------------------------------------------------------------------------
// Purpose - This is the design for the Movie class, which is used as the
	//     - stored data within the Manager class.
	//	   - its essential properties are the attributes and counters
	//	   - and the compare methods
// ---------------------------------------------------------------------------
// Notes on specifications, special algorithms, and assumptions.
// ---------------------------------------------------------------------------

#ifndef MOVIE_H_
#define MOVIE_H_

#include <string>

#include "media.h"
//#include "movieattribute.h"
#include <vector>
#include "stored_data/storeddata.h"


enum class MType {COMEDY = 0, DRAMA = 1, CLASSICAL = 2, DEFAULT = -1};

class Movie : public StoredData
{
	friend std::ostream& operator<<(std::ostream& , const Movie&);
public:

	/*
	* Name:
		(no-arg) constructor for Movie
	* Description:
		Will initialize a Movie object
	*/
	explicit Movie(char movieType);

/**
 *
 * @param genre
 * @param init_stock
 * @param title mebbe
 * @param director
 * @param releaseY
 */
	Movie(std::string genre, int init_stock, std::string title,
        std::string director, std::string releaseY, std::string actor = "");


  /*
  * Name:
    Destructor
  * Description:
    Will properly delete a Movie object and its children
  */
  ~Movie() override;

	std::string getType() const;

	int getStock() const;

	Media getMedia() const;

	void setMedia(Media media);

	bool setStock(int);
//
//	bool setReleaseYear(std::string);

	/*
	* Name:
	 	hash()
	* Description:
	 	Will calculate a hash based on the Movie instance and
		return an index at which to insert into the Movie list.
		The hash will be an open hash, so collision detection is
		not necessary. It will be overridden by child classes
	* Return:
		The index at which to insert into the Movie list
	*/
	//virtual int hash() const override = 0;


	/*
	* Name:
		getAttributes
	* Description:
		Gets a copy of the Movie Attributes
	* Return:
		A vector of MovieAttributes
	*/
	//std::vector<MovieAttribute *> getAttributes() const;

//	/*
//	* Name:
//		parse
//	* Description:
//		Parses the input string and populates the current movie instance
//	* Parameter:
//		A string that will be parsed into the Movie instance (if successfull)
//	* Return:
//		Whether or not the string was actually parsed.
//	*/
//	virtual bool parse(std::string, bool hasStock);

//	//TODO: Document
//	virtual Movie* copy() const;

	//TODO: Document
	virtual std::string toString() const;

	/*
	* Name:
	operator == overload
	* Description:
	Checks whether or not the Movies are equal
	* Parameter:
	Another movie
	* Return:
	A boolean based whether or not the the two Movies are equal
	*/
	virtual bool operator==(const Movie&) const;

	/*
	* Name:
	operator != overload
	* Description:
	Checks whether or not the Movies are not equal
	* Parameter:
	Another movie
	* Return:
	A boolean based whether or not the two Movies are equal
	*/
	virtual bool operator!=(const Movie&) const;


private:
	const std::string movieType;					// the type will distinguish the movies
								// on highest level
	Media mediaType;				// the media type

	int stock;
	const std::string director;
	const std::string title;
	const std::string date_released;

	//std::vector<MovieAttribute *> movieAttributes; //A vector of MovieAttributes
protected:

	struct Comparable {
		MType genre;
		std::string first;
		std::string second;
    Comparable():genre(MType::DEFAULT),
                 first(std::string()),
                 second(std::string()){};

    Comparable(MType gnr, std::string frst, std::string sec)
        : genre(gnr), first(frst), second(sec){}
	}comp;

	/*
	* Name:
		addAttribute
	* Description:
		Adds the given Movie Attribute to the Movie Object
		(If the Movie allows for that Movie Attribute)
	* Parameter:
		The MovieAttribute to add to the vector
	* Return:
		Whether or not the Movie Attribute was added
	*/
	//virtual bool addAttribute(MovieAttribute*) = 0;
};

#endif /* MOVIE_H_ */
