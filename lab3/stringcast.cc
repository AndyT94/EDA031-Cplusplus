#include "date.h"
#include <string>
#include <iostream>

using namespace std;

template <typename T>
inline T string_cast<T>(const string& s)  {

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
