#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;

Dictionary::Dictionary() {
	ifstream input("words.txt");
	string line;

	if (input.is_open()) {
		while (getline(input,line)) {
			size_t firstDigit = line.find_first_of("0123456789");
			dict.insert(line.substr(0, firstDigit - 1));
		}
		input.close();
	} else {
		cout << "ERROR: Unable to open file(s)";
	}
}

bool Dictionary::contains(const string& word) const {
	return dict.count(word) > 0;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}
