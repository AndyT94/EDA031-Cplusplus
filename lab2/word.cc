 #include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) : word(w), trigrams(t) {}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int matches = 0;
	unsigned int i = 0;
	unsigned int j = 0;

	while(i < trigrams.size() && j < t.size()) {
		int comparison = trigrams[i].compare(t[j]);
		if(comparison < 0) {
			++i;
		} else if (comparison > 0) {
			++j;
		} else {
			++matches;
			++i;
			++j;
		}
	}
	return matches;
}
