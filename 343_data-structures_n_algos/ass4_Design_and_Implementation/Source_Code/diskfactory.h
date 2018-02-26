#ifndef DISK_FACTORY_H
#define DISK_FACTORY_H

#include <iostream>
#include <string>
#include <vector>
#include "disk.h"
#include "hashtable.h"

class DiskFactory {
public:
  DiskFactory();
  
  // call disk:: createDisk to create
  // should find it first
  bool addDisk(const DiskType &diskType, const MediaType &mediaType,
               const short &genre, const std::string &title,
               const unsigned int &stock, const DDate &releaseDate,
               const std::string &firstName, const std::string &lastName,
               const std::string &fistName1 = " ",
               const std::string &lastName1 = " ");
  
  // list all the disks have the key for each mediaType and Genre, than ask
  // clients to choose which cd they want to delete if the disk return 1 delete
  // and return true cant find return false
  bool removeDisk(const std::string &key);
  
  // delete all elements
  void clear();
  
  // ‘I’ should output all Comedy movies,
  // then all Dramas, then all Classics.
  void printAll() const;
  
  // using  std::vector<Disk*> findDisk(const std::string& key)
  // ask the clients what disks they want to get (sometime disks can duplicate
  // in name but different genre) if std::vector<Disk*> findDisk(const
  // std::string& key) size == 1 just return the disk
  Disk *findDisk(const std::string &key);
  
  ~
  
  virtual DiskFactory();

private:
  // return pointer of the disks with the same key for each mediatype and Genre.
  std::vector<Disk *> findDisk(const std::string &key);
  
  // maps for each genre of movie
  std::vector<HashTable<std::string, Disk *>> m_disks(TOTAL_MOVIE_TYPE);
};

#endif
