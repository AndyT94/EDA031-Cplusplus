#include "date.h"
#include <string>
#include <sstream>
#include <iostream>

using namespace std;

template <typename T>
inline string toString(T a)  {
  ostringstream out;
  out << a;
  return out.str();
}

int main() {
  double d = 1.234;
  Date today;
  string sd = toString(d);
  string st = toString(today);
  cout << "Double: " << sd << endl << "Date: " << st << endl;
}
