#include <iostream>
#include "tagremover.h"
#include <string>
#include <regex>

using namespace std;

TagRemover::TagRemover(std::istream& in) {
  removeTags(in);
}

void TagRemover::print(std::ostream& out) {
  out << text;
}

void TagRemover::removeTags(std::istream& in) {
  string line;

  while(getline(in, line)) {
    text += line + "\n";
  }

  text = regex_replace(text, regex("<[^>]*>"), "");
  text = regex_replace(text, regex("&lt"), "<");
  text = regex_replace(text, regex("&gt"), ">");
  text = regex_replace(text, regex("&nbsp"), " ");
  text = regex_replace(text, regex("&amp"), "&");
}
