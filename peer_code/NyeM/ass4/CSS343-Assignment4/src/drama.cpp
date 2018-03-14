#include "stored_data/movie/drama.h"


bool Drama::parse(const std::string line, bool hasStock) {
  if (line[0] != 'D') {
    return false;
  }
  else {
    return Movie::parse(line, hasStock);
  }
}

int Drama::hash() const {
  return 0;
}

Drama::~Drama() = default;

Drama::Drama():Movie('D') {

}
