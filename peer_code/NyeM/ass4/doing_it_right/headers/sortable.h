#ifndef DOING_IT_RIGHT_SORTABLE_H
#define DOING_IT_RIGHT_SORTABLE_H

#include <string>

using std::string;

class Sortable {
protected:
  struct Comparable {
    std::string type;
    std::string first;
    std::string second;

    Comparable():type(string()), first(string()), second(string()){}

    bool operator==(const Comparable &rhs) const {
      return type == rhs.type &&
             first == rhs.first &&
             second == rhs.second;
    }

    bool operator!=(const Comparable &rhs) const {
      return !(rhs == *this);
    }

    bool operator<(const Comparable &rhs) const {
      if (type == rhs.type) {
        if (first == rhs.first){
          return second < rhs.second;
        }else return first < rhs.first;
      }else return type < rhs.type;
    }

    bool operator>(const Comparable &rhs) const {
      return rhs < *this;
    }

    bool operator<=(const Comparable &rhs) const {
      return !(rhs < *this);
    }

    bool operator>=(const Comparable &rhs) const {
      return !(*this < rhs);
    }

  }comp;

public:

  Sortable():comp(){};

  bool operator==(const Sortable &rhs) const {
    return comp == rhs.comp;
  }

  bool operator!=(const Sortable &rhs) const {
    return !(rhs == *this);
  }

  bool operator<(const Sortable &rhs) const {
    return comp < rhs.comp;
  }

  bool operator>(const Sortable &rhs) const {
    return rhs < *this;
  }

  bool operator<=(const Sortable &rhs) const {
    return !(rhs < *this);
  }

  bool operator>=(const Sortable &rhs) const {
    return !(*this < rhs);
  }
};

#endif //DOING_IT_RIGHT_SORTABLE_H
