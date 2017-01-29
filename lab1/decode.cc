#include <fstream>  // file streams
#include <iostream>
#include "coding.h"

using namespace std;

int main(int argc, char* argv[]) {
  if(argc != 2) {
    cerr << "Wrong number of arguments" << endl;
    exit(1);
  }

  ifstream input(argv[1]);
  if (!input) { // "if the file couldn’t be opened"
    cerr << "Could not open: " << argv[1] << endl;
    exit(1);
  }

  ofstream dec_file;
  dec_file.open("file.dec");

  char c = input.get();
  while (input.good()) {
    dec_file << Coding::decode(c);
    c = input.get();
  }
  input.close();
}
