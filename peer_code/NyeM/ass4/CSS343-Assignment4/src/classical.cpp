#include "stored_data/movie/classical.h"


Classical::Classical():Movie('C') { }

Classical::~Classical() = default;

int Classical::hash() const {
  return 0;
}

bool Classical::parse(const std::string line, bool hasStock) {
  if (line[0] != 'C') {
    return false;
  }
  else {
    return Movie::parse(line, hasStock);
  }
}
