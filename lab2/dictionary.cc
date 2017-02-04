#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"
#include <math.h>
#include <list>

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
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions,
	const string& word) const {
		vector<string> trigrams;
		if(word.size() > 3) {
			unsigned int count;
			for(count = 0; count < word.size() - 2; ++count) {
				trigrams.push_back(word.substr(count, 3));
			}
			sort(trigrams.begin(), trigrams.end());

			for(unsigned int i = word.size() - 2; i < word.size() + 1; ++i) {
				for(Word w: words[i]) {
					if(w.get_matches(trigrams) >= ceil(trigrams.size() / 2.0)) {
						suggestions.push_back(w.get_word());
					}
				}
			}
		}
}

void Dictionary::rank_suggestions(vector<string>& suggestions,
	const string& word) const {
		vector<pair<int, string>> ranked_words;
		int d[26][26];
		for(unsigned int i = 0; i < 26; ++i) {
			d[i][0] = i;
		}
		for(unsigned int j = 0; j < 26; ++j) {
			d[0][j] = j;
		}

		for(unsigned int k = 0; k < suggestions.size(); ++k) {
			string& candidate = suggestions[k];
			for(unsigned int i = 1; i <= word.size(); ++i) {
				for(unsigned int j = 1; j <= candidate.size(); ++j) {
					d[i][j] = min({d[i-1][j] + 1, d[i][j-1] + 1,
						(word[i] == candidate[j]) ? (d[i-1][j-1]) : (d[i-1][j-1] + 1)});
				}
			}
			ranked_words.push_back(make_pair(d[word.size()][candidate.size()], suggestions[k]));
		}

		sort(ranked_words.begin(), ranked_words.end());
		suggestions.clear();
		for(unsigned int i = 0; i < ranked_words.size(); ++i) {
			suggestions.push_back(ranked_words[i].second);
		}
	}

void Dictionary::trim_suggestions(vector<string>& suggestions) const {
	if(suggestions.size() > 5) {
		suggestions.resize(5);
	}
}
