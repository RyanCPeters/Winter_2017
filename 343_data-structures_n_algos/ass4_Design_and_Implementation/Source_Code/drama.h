#ifndef DRAMA_H
#define DRAMA_H

#include "director.h"
#include "disk.h"
#include "movie.h"

class Drama : virtual public Movie {
public:
  Drama():m_type(MovieType::DRAMA),m_director(Director()),primary(m_director){};
  
  Drama(std::string &title, const Director &actor, const unsigned int &stock,
        const DDate &releaseDate, const DiskType &diskType = DVD);
  
  Drama &operator=(const Drama &);
  
  bool operator==(const Drama &) const;
  
  bool operator!=(const Drama &) const;
  
  bool operator<(const Drama &) const;
  
  bool operator>(const Drama &) const;
  
  friend std::ostream &operator<<(std::ostream &sout, const Drama &);
  
  ~Drama();
  
  
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
    Drama* dPtr = &dynamic_cast<Drama&>(other);
    Director* prim = dynamic_cast<Director*>(dPtr->getPrimary());
    return(this->primary < *prim )? -1: (this->primary == *prim )?0:1;
  }
  
  /**
   * see description for comparePrimaryCriteria function.
   * @param other
   * @return
   */
  virtual int compareSecondaryCriteria(const Movie &other) const override {
    Drama* dPtr = &dynamic_cast<Drama&>(other);
    Director* sec = dynamic_cast<Director*>(dPtr->getSecondary());
    return(this->primary < *sec )? -1: (this->primary == *sec )?0:1;
    
  }

protected:
  
  virtual void* getPrimary() const override {
    return &primary;
  }
  
  virtual void* getSecondary() const override {
    return &secondary;
  }


private:
  Director& primary;
  std::string secondary;
  
};

#endif
