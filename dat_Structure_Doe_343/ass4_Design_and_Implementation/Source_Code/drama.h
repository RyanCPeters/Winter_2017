#ifndef DRAMA_H
#define DRAMA_H

#include "director.h"
#include "disk.h"
#include "movie.h"
#include "imovie.h"

class Drama : virtual private Movie, virtual public IMovie {
public:
  
  Drama(std::string &title, const Director &dir, const unsigned int &stock,
        const DDate &releaseDate, const DiskType &diskType = DVD);
  
  virtual Drama &operator=(const Drama &);
  
  virtual bool operator==(const Drama &) const;
  
  virtual bool operator!=(const Drama &) const;
  
  virtual bool operator<(const Drama &) const;
  
  virtual bool operator>(const Drama &) const;
  
  virtual friend std::ostream &operator<<(std::ostream &sout, const Drama &);
  
  virtual ~Drama();
  
  
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
   *
   * @param other The Movie object reference against which *this is to be
   * compared.
   *
   * @return
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

private:
  
  // making the empty ctor private to prevent
  Drama();
  
};

#endif
