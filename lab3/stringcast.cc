#include "date.h"

using namespace std;



int main() {
  try {
    int i = string_cast<int>("123");
    double d = string_cast<double>("12.34");
    Date date = string_cast<Date>("2015-01-10");
  } catch (invalid_argument& e) {
    cout << "Error: " << e.what() << endl;
  }
}
