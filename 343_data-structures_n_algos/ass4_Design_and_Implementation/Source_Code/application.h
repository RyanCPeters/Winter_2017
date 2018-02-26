#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>
#include <vector>
#include "customerFactory.h"
#include "diskfactory.h"
#include "transaction.h"

class Application {
public:
  Application();
  
  // main run. virtual if someone to inhertance this class
  // for customize
  virtual void run();
  
  // call cleanUp
  ~Application();

private:
  // read the files
  bool readFile();
  
  // for readFile
  // data is each line
  void parse(const std::string &data);
  
  // return false if command is invalid. otherwise return true
  bool isValidCommand(const std::string &command) const;
  
  // print transactions
  // limit is number of transactions to print out
  // 0 is print all
  void printTransactions(const unsigned long &limit = 0) const;
  
  // delete pointer of transactions
  void cleanUp();
  
  // all transactions. already sorted, push_back
  // when a customer wants to check out or check in, the functions inside
  // customer class will create Transaction*, we just need to add  this
  // transactions without create a new pointer.
  // but we need to delete all the transactions when the program is terminate
  // to prevent memory leak
  std::vector<Transaction *> transactions;
  
  CustomerFactory m_customers;
  
  DiskFactory m_disks;
};

#endif
