#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int main() {
  string line;
  ifstream input("/usr/share/dict/words");
  ofstream words("words.txt");

  if (input.is_open() && words.is_open()) {
	while (getline(input,line)) {
	transform(line.begin(), line.end(), line.begin(), ::tolower);
	
	if(line.size() > 3) {
		vector<string> trigrams;

		unsigned int count;
		for(count = 0; count < line.size() - 2; ++count) {
			trigrams.push_back(line.substr(count, 3));
		}
		sort(trigrams.begin(), trigrams.end());
		
		words << line << " " << count;
		for(auto it = trigrams.begin(); it != trigrams.end(); ++it) {
			words << " " << *it;
		}
		words << endl;
	} else {
		words << line << " 0" << endl;
	}
		
    }
    input.close();
    words.close();
  } else {
    cout << "ERROR: Unable to open file(s)";
  }
}
