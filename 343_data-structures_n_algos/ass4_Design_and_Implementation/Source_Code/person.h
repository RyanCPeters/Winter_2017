#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

/**
 * enum PersonType is used to ensure that we can assess a Person's type from
 * any point of reference.
 */
enum class PersonType : char {DIRECTOR = 'd', ACTOR = 'a'};


/**
 * class Person is mostly virtual, however we need to define the get/set
 * functions for the private member variables holding the person's first and
 * last name, and their type.
 *
 * The type, is used to discern if the person was an actor in the movie (as
 * in the Classics movie genre) or if they are a director.
 */
class Person {
public:
  Person();
  
  Person(std::string firstName,
         std::string lastName,
         const PersonType& pType)
                            :m_firstName(std::move(firstName)),
                             m_lastName(std::move(lastName)),
                             m_type(pType){};
  
  virtual const std::string &getFirstName() const {return m_firstName;};
  
  virtual const std::string &getLastName() const {return m_lastName;};
  
  virtual const std::string &getFullName() const {
    return m_firstName + " " + m_lastName;
  };
  
  virtual const std::string &getFullNameReversed() const {
    return m_lastName + " " + m_firstName;
  };
  
  virtual const PersonType& getType() const {return m_type;};
  
  virtual bool operator==(const Person &) const = 0;
  
  virtual bool operator!=(const Person &) const = 0;
  
  virtual bool operator<(const Person &) const = 0;
  
  virtual bool operator>(const Person &) const = 0;
  
  virtual Person &operator=(const Person&) = 0;
  
  
  virtual ~Person();

protected:
  
  /**
   *
   * @param pType an enum which is used to discern a person's type should we
   * have to cast them between base class Person and some derived class.
   */
  void setType(const PersonType& pType){
    m_type = pType;
  }
  
  /**
   *
   * @param first std::string of person's first name
   * @param last  std::string of person's last name
   */
  void setName( const std::string& first, const std::string& last){
    m_firstName = first;
    m_lastName = last;
  }
  
private:
  std::string m_firstName;
  std::string m_lastName;
  PersonType m_type;
};

#endif
