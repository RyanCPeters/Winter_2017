#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>
#include "disk.h"

// movie transaction
class enum TransactionStatus : short {
  BORROW, RETURN
};

// why members are not pointer of Disk*?
// if a disk is delete from Application:: DiskFactory m_disks
// then the pointer in this class is dangling (nullptr)
// but we want to keep the list of transaction
// because transaction never get delete from Application
class Transaction {
public:
  Transaction(const TransactionStatus &status, const Disk *disk);
  
  // B for borrow R for return
  std::string getStatus() const;
  
  // name of the movie
  const std::string &getTitle() const;
  
  // DVD
  std::string getDiskType() const;
  
  // movie, music, or porn :)
  std::string getMediaType() const;
  
  // if it is borrow, what date it will be return?
  // assume 30 days
  virtual DDate getReturnDate() const;
  
  friend ostream &operator<<(ostream &sout, const Transaction &);
  
  virtual ~Transaction();

private:
  TransactionStatus m_status;
  std::string       m_title;
  DDate             m_transactionDate;
  diskType          m_type;
  MediaType         m_mediaType;
};

#endif
