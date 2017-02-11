#include "date.h"
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

template <typename T>
inline T string_cast(const string& s)  {
    stringstream convert(s);
    T value;
    if(convert >> value) {
      return value;
    }
    throw invalid_argument("Invalid argument");
}

int main() {
  try {
    int i = string_cast<int>("123");
    double d = string_cast<double>("12.34");
    Date date = string_cast<Date>("2015-01-10");
  } catch (invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}
