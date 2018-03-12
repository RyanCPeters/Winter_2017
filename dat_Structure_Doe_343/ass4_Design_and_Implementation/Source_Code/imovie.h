//
// Created on 2/25/2018.
//
/** abstract class IMovie will function as a interface contract that ensures
 * all derived classes have the baseic public accessor/comparitor functions
 * needed for sorting and finding a given movie instance.
 */

#ifndef ASS4_DESIGN_AND_IMPLEMENTATION_IMOVIE_H
#define ASS4_DESIGN_AND_IMPLEMENTATION_IMOVIE_H

#include "director.h"
#include "disk.h"
#include "movie.h"


class IMovie {
public:
  // constructor
  IMovie();

  
  // get type of movie
  virtual char getMovieType() const = 0;
  
  // get the significant person from this movie, be it director or actor.
  virtual const Person &getSignificantPerson() const = 0;
  
  /**
   * pure virtual accessor to be implemented by the different movie types
   * provides a clean interface for comparing movies when sorting
   *
   * In both of the compare criteria functions, the implementing class should
   * dynamic_cast<TYPE&>(other); // replace TYPE with the derived class's type
   * Then, it needs to evaluate it's own primary/secondary criteria against
   * that of 'other'. The return should be an int value representing if
   * 'this' is naturally ordered before 'other'.
   *      let -1 represent when this->criteria <  other.criteria;
   *      let  0 represent when this->criteria == other.criteria;
   *      let  1 represent when this->criteria >  other.criteria;
   *
   * !!!!! Important Note !!!!!!!
   * To use these functions, the caller should first type-check other to be
   * of the same derived class as *this.
   *
   *      -------------------------------------------------------
   *      |Movie type | Primary criteria   | Secondary criteria |
   *      |-----------|--------------------|--------------------|
   *      |   ‘C’     | Release date       |  Major actor       |
   *      |   ‘D’     | Director           |  Title             |
   *      |   ‘F’     | Title              |  Year released     |
   *      -------------------------------------------------------
   *
   * @param other The Movie object reference against which *this is to be
   * compared.
   *
   * @return
   */
  virtual int comparePrimaryCriteria(const Movie &other) const = 0;
  
  virtual int compareSecondaryCriteria(const Movie &other) const = 0;
  
  // destructor
  virtual ~IMovie() =0;
  
  // assignment operator
  virtual Movie &operator=(const Movie &) = 0;
  
  // compare opeartor for sorting
  virtual bool operator==(const Movie &) const = 0;
  
  virtual bool operator!=(const Movie &) const = 0;
  
  virtual bool operator<(const Movie &) const = 0;
  
  virtual bool operator>(const Movie &) const = 0;
  
  virtual friend std::ostream &operator<<(std::ostream &sout, const Movie &)= 0;
  
  
};

#endif //ASS4_DESIGN_AND_IMPLEMENTATION_IMOVIE_H
