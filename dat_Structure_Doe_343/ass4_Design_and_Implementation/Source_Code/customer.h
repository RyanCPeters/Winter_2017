#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <vector>
#include "disk.h"
#include "hashTable.h"
#include "person.h"
#include "transaction.h"

class Customer : public Person {
public:
  Customer();
  
  Customer(const std::string &firstName, const std::string &lastName,
           const unsigned long &id);
  
  const unsigned long &getId() const;
  
  // add to m_borrowDisks
  // and return transaction for Application class so it can add
  // transactions of all customers
  // return null if stock is < 0
  Transaction *checkOut(Disk *disk);
  
  // delete m_borrowDisks if can find
  // and return transaction for Application class so it can add
  // transactions of all customers
  // return null if cant find
  Transaction *checkIn(const std::string &diskName);
  
  // ‘H’ should show a list of DVD transactions of a
  // customer in chronological order (latest to earliest) and specify whether
  // the movie was borrowed or returned
  
  // limit for numbers of transactions that clients want to print
  // defaule is 0 for print all transactions
  void printTransaction(const unsigned int limit = 0);
  
  ~Customer();

private:
  Disk *findDisk(const std::string &key);
  
  unsigned long                  m_id;
  // transtraction pointer will detele at vector<Transaction*> in Application
  std::vector<Transaction *>     m_transactions;
  HashTable<std::string, Disk *> m_borrowDisks;
};

#endif
