#include <iostream>
#include "tagremover.h"

using namespace std;

TagRemover::TagRemover(const std::istream& in) {
  removeTags(in);
}

void TagRemover::print(const std::ostream& out) {

}

void TagRemover::removeTags(const std::istream& in) {
  string line;
}
