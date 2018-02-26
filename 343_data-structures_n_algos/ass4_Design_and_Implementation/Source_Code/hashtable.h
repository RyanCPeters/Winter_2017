#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>

template<class K, class V>
class HashTable {
  
  // nested struct to keep everything nice and civil
  struct bucket {
    K              hash;
    std::vector<K> Keys;
    std::vector<V> Values;
  };

private:
  // pointer to hash function
  K (*hasher)(K);
  
  // number of entries
  int                 numberOfEntries;
  // underlying implementation
  std::vector<bucket> map;

public:
  // constructor takes a pointer to a
  // hashing function
  HashTable(K(*hashFunc)(K));
  
  // enroll emplaces a key value pair
  // creates a new bucket if the hash
  // does not already exist
  void enroll(K, V);
  
  // retrieves a value from a key
  V get(K);
  
  // updates a keypair
  void update(K, V);
  
  // returns current number of entries
  int getNumberOfEntries();
  
  // return all movies sorted like they need to be
  static std::vector<V>
  retrieveAllValues(HashTable<K, V>, bool(*sortComparator)(V, V));
  
  // helper function for unit testing purposes
  static K getHash(K);
};

#include "hashtable.cpp"

#endif //HASHTABLE_H
