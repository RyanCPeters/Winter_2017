#ifndef CLASSICS_H
#define CLASSICS_H

#include "actor.h"
#include "director.h"
#include "movie.h"

class Classics : virtual public Movie {
public:
  Classics();
  
  Classics(const std::string &title,
           const Director &director const DDate &releaseDate,
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
    dynamic_cast<Classics&>(other);
    
  }
  
  virtual int compareSecondaryCriteria(const Movie &other) const override {
    dynamic_cast<Classics&>(other);
    
  }

protected:
  
  virtual void* getPrimary() const override {
    return &primary;
  }
  
  virtual void* getSecondary() const override {
    return &secondary;
  }

private:
  Actor m_actor;
  
  Director& primary;
  std::string secondary;
  
};

#endif
