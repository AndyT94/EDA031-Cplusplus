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
			string word;
			vector<string> trigrams;

			vector<string> split;
			size_t curr_pos = line.find(' ');
			size_t prev_pos = 0;

			while (curr_pos != string::npos) {
				split.push_back(line.substr(prev_pos, curr_pos - prev_pos));
				prev_pos = curr_pos + 1;
				curr_pos = line.find(' ', prev_pos);
			}
			split.push_back(line.substr(prev_pos, line.size() - prev_pos));

			auto it = split.begin();
			word = *it;
			++it; //skip digit
			++it;
			while(it != split.end()) {
				trigrams.push_back(*it);
				++it;
			}

			dict.insert(word);
			Word w = Word(word, trigrams);
			words[word.size() - 1].push_back(w);
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
