#ifndef DIRECTOR_H
#define DIRECTOR_H

#include "person.h"

class Director : virtual public Person {
public:
  Director();
  
  Director(const std::string &firstName, const std::string &lastName,
           const PersonType& pType){
    setName(firstName,lastName);
    // person type needs to be set in order to satisfy the
    // interface established in the abstract class Person
    setType(pType);
  }
  
  ~Director();
  
  virtual bool operator==(const Director &) const;
  
  virtual bool operator!=(const Director &) const;
  
  virtual bool operator<(const Director &) const;
  
  virtual bool operator<=(const Director &) const;
  
  virtual bool operator>(const Director &) const;

};

#endif
