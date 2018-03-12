#ifndef COMEDY_H
#define COMEDY_H

#include "director.h"
#include "movie.h"

class Comedy : virtual private Movie, virtual public IMovie {
public:
  Comedy();
  
  Comedy(std::string &title, const Director &actor, const unsigned long &stock,
         const DDate &releaseDate, const DiskType &diskType = DVD);
  
  Comedy &operator=(const Comedy&);
  
  bool operator==(const Comedy &) const;
  
  bool operator!=(const Comedy &) const;
  
  bool operator<(const Comedy &) const;
  
  bool operator>(const Comedy &) const;
  
  ~Comedy();
  
  
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
   *
   *      -------------------------------------------------------
   *      |Movie type | Primary criteria   | Secondary criteria |
   *      |-----------|--------------------|--------------------|
   *      |   ‘C’     | Release date       |  Major actor       |
   *      |   ‘D’     | Director           |  Title             |
   *      |   ‘F’     | Title              |  Year released     |
   *      -------------------------------------------------------
   */
  virtual int comparePrimaryCriteria(const Movie &other) const override {
    int ret = this->m_prim.director.compare(other.m_prim.director);
    return (ret < 0)? -1 : (ret > 0)? 1 : 0;
  }
  
  /**
   * see description for comparePrimaryCriteria function.
   * @param other
   * @return
   */
  virtual int compareSecondaryCriteria(const Movie &other) const override {
    int ret = this->m_sec.title.compare(other.m_sec.title);
    return (ret < 0)? -1 : (ret > 0)? 1 : 0;
  }

  
};

Comedy::Comedy(std::string &title, const Director &actor,
               const unsigned long &stock, const DDate &releaseDate,
               const DiskType &diskType):m_title(title),  {
  
}

#endif
