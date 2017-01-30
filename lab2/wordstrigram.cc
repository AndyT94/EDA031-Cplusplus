#include <fstream>
#include <iostream>

using namespace std;

int main() {
  string line;
  ifstream input("usr/share/dict/words");
  ofstream words("words.txt");

  if (input.is_open() && words.is_open()) {
    while (getline(input,line)) {
      transform(line.begin(), line.end(), line.begin(), ::tolower);
      if(line.size() > 3) {

      } else {
        words << line + " 0" << endl;
      }
    }
    input.close();
    words.close();
  } else {
    cout << "ERROR: Unable to open file(s)";
  }
}
