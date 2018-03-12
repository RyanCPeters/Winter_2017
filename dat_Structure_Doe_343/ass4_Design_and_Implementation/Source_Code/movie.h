#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "director.h"
#include "disk.h"

enum class MovieType : short {
  COMEDY = 'F', DRAMA = 'D', CLASSICS = 'C', TOTAL_MOVIE_TYPE =3
};

union MoviePrimary {
  // Classic movie primary sort category
  DDate release_date;
  
  // Drama movie primary sort category
  std::string director{nullptr};
  
  // Comedy movie primary sort category
  std::string title{nullptr};
};

union MovieSecondary {
  // Classic movie primary sort category
  std::string major_actor{nullptr};
  
  // Drama movie primary sort category
  std::string title{nullptr};
  
  // Comedy movie primary sort category
  DDate year_released;
};

class Movie : virtual public Disk {
public:
  // constructor
  Movie();

  
  
protected:
  MovieType m_type;
  DDate m_date;
  std::string m_title;
  Director  m_director;
  MoviePrimary m_prim;
  MovieSecondary m_sec;
  
};

#endif
