#ifndef CLASSICS_H
#define CLASSICS_H

#include "actor.h"
#include "director.h"
#include "movie.h"

class Classics : virtual private Movie, virtual public IMovie {
public:
  
  Classics(const std::string &title,
           const Director &director, const DDate &releaseDate,
           const Actor &actor, const unsigned long &stock,
           const DiskType &disktype = DVD);
  
  const Actor &getActor() const;
  
  Classics &operator=(const Classics &);
  
  bool operator==(const Classics &) const;
  
  bool operator!=(const Classics &) const;
  
  bool operator<(const Classics &) const;
  
  bool operator>(const Classics &) const;
  
  friend std::ostream &operator<<(std::ostream &sout, const Classics &);
  
  ~Classics();
  
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
    int ret = this->m_prim.release_date.year - other.m_prim.release_date.year;
    if(ret == 0){
      ret += this->m_prim.release_date.month - other.m_prim.release_date.month;
    }
    return (ret < 0)? -1 : (ret > 0)? 1 : 0;
  }
  
  /**
   * see description for comparePrimaryCriteria function.
   * @param other
   * @return
   */
  virtual int compareSecondaryCriteria(const Movie &other) const override {
    int ret = this->m_sec.major_actor.compare(other.m_sec.major_actor);
    return (ret < 0)? -1 : (ret > 0)? 1 : 0;
  }

private:
  // private ctor to prevent its use
  Classics();
  
  
  Actor m_actor;
  
  Director& primary;
  std::string secondary;
  
};

#endif
