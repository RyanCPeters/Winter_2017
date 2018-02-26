#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "director.h"
#include "disk.h"

enum class MovieType : short {
  COMEDY, DRAMA, CLASSICS, TOTAL_MOVIE_TYPE
};

class Movie : virtual public Disk {
public:
  // constructor
  Movie();
  
  Movie(const std::string &title, const MovieType &type,
        const Person &relevantPerson, const unsigned int &stock,
        const DDate &releaseDate, const DiskType &diskType);
  
  // copy ctor
  Movie(const Movie &other);
  
  // get type of movie
  char getMovieType() const {
    switch (m_type) {
      case MovieType::CLASSICS: return 'C';
      case MovieType::DRAMA: return 'D';
      case MovieType::COMEDY: return 'F';
      default: return '*';
        // Fail case: * seems like an easy way to
        // check for failure
    }
  }
  
  // get director
  const Director &getDirector() const;
  
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
   */
  virtual int comparePrimaryCriteria(const Movie &other) const = 0;
  
  virtual int compareSecondaryCriteria(const Movie &other) const = 0;
  
  // destructor
  virtual ~Movie();
  
  // assignment operator
  Movie &operator=(const Movie &);
  
  // compare opeartor for sorting
  bool operator==(const Movie &) const;
  
  bool operator!=(const Movie &) const;
  
  bool operator<(const Movie &) const;
  
  bool operator>(const Movie &) const;
  
  friend std::ostream &operator<<(std::ostream &sout, const Movie &);
  
  
protected:
  MovieType m_type;
  Director  m_director;
  
  virtual void* getPrimary() const = 0;
  
  virtual void* getSecondary() const = 0;
  
};

#endif
