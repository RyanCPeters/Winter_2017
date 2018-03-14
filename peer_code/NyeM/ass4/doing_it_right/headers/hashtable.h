#ifndef DOING_IT_RIGHT_ABSTRACT_HASHTABLE_H
#define DOING_IT_RIGHT_ABSTRACT_HASHTABLE_H

#include <vector>
#include <iostream>
#include <tuple>

using std::vector;
using std::string;
using std::cout;
using std::endl;

template <class k, class v>
class HashTable {
protected:

  static const int map_end = {97};

  struct buckets{

    vector<std::pair<k,v>> kv{};

    buckets() = default;

    int contains(const k& key){
      for(int i = 0; i < kv.size(); ++i){
        if(kv.at(i).first == key)return i;
      }
      return -1;
    }

    void add_or_replace( k key, v val){
      int pos =contains(key);
      if(pos < 0) kv.emplace_back(std::make_pair(key,val));
      else kv[pos] = val;
    }

    bool add_or_fail(k key, v val){
      int pos = contains(key);
      if(pos < 0) {
        kv.emplace_back(std::make_pair(key, val));
        return true;
      }
      return false;
    }

    v& extractVal(const k& key){
      int pos = contains(key);
      if( pos < 0) return nullptr;
      return &(kv.at(pos).second);

    }

    void clear(){
      kv.clear();
    }

  };

  int accumulated_entries{0};

  buckets* table[map_end];


public:

  HashTable() = default;

  ~HashTable(){
    for(int i = 0; i < map_end; ++i)table[i]->clear();
    delete[] table;
  }

  /** int contains(std::string key)const;
   * will search the table for the given key. If the table contais the key,
   * it will return the index position of the bucket where it was found, as a
   * value between 0 and the table's max size.
   *
   * If the key isn't found, return -1;
   * @param key the key we are going to search for
   *
   * @return an int value for the index position of the bucket where the key
   * was found.
   */
  virtual int contains(k key)const = 0;

  virtual bool add(k key, v val) = 0;

  virtual v& extractVal(k key) = 0;

  virtual std::vector<v> orderedValues()=0;





};
#endif //DOING_IT_RIGHT_ABSTRACT_HASHTABLE_H
