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
  
  virtual bool operator==(const Director &other) const;
  
  virtual bool operator!=(const Director &other) const;
  
  virtual bool operator<(const Director &other) const;
  
  virtual bool operator<=(const Director &other) const;
  
  virtual bool operator>(const Director &other) const;

};

bool Director::operator==(const Director &other) const {
  if(this->getType() != other.getType())return false;
  
  std::string *myFirstPtr{nullptr},
              *myLastPtr{nullptr},
              *othFirstPtr{nullptr},
              *othLastPtr{nullptr};
  
  *myFirstPtr = getFirstName(), *myLastPtr = getLastName();
  *othFirstPtr = other.getFirstName(), *othLastPtr = other.getLastName();
  
  return ((*myFirstPtr) ==(*othFirstPtr)) &&
          ((*myLastPtr) == (*othLastPtr));
}

bool Director::operator!=(const Director &other) const {
  return !(*this == other);
}

bool Director::operator<(const Director &other) const {
  std::string *myFirstPtr{nullptr},
              *myLastPtr{nullptr},
              *othFirstPtr{nullptr},
              *othLastPtr{nullptr};
  
  *myFirstPtr = getFirstName(), *myLastPtr = getLastName();
  *othFirstPtr = other.getFirstName(), *othLastPtr = other.getLastName();
  
  int lessChecker = 0;
  lessChecker = (*myFirstPtr).compare(*othFirstPtr);
  
  if(lessChecker < 0) return true;
  if(lessChecker == 0)return (*myLastPtr).compare(*othLastPtr) <0;
  return false;
}

bool Director::operator<=(const Director &other) const {
  return *this < other || *this == other;
}

bool Director::operator>(const Director &other) const {
  return false;
}

#endif
