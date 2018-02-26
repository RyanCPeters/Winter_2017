#ifndef CUSTOMER_FACTORY
#define CUSTOMER_FACTORY

#include <iostream>
#include "customer.h"
#include "hashtable.h"

class CustomerFactory {
public:
  CustomerFactory();
  
  bool addCustomer(const unsigned long &key, const std::string &firstName,
                   const std::string &lastName);
  
  bool remove(const unsigned long &key);
  
  Customer *findCustomer(const unsigned long &key);
  
  void clear();
  
  ~CustomerFactory();

private:
  HashTable<unsigned long, *Customer> m_customers;
};

#endif
