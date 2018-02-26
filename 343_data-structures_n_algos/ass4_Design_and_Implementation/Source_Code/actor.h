#ifndef ACTOR_H
#define ACTOR_H

#include <iostream>
#include "person.h"

class Actor : virtual public Person {
public:
  Actor(const std::string &firstName, const std::string &lastName,
        const PersonType& pType){
    setName(firstName,lastName);
    // person type needs to be set in order to satisfy the
    // interface established in the abstract class Person
    setType(pType);
  }
  
  ~Actor();
  
  virtual bool operator==(const Actor &) const;
  
  virtual bool operator!=(const Actor &) const;
  
  virtual bool operator<(const Actor &) const;
  
  virtual bool operator>(const Actor &) const;
};

#endif
