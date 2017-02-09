#include <iostream>
#include <string>

using namespace std;

string getPrimes(unsigned int nbr) {
  string primes(nbr + 1, 'P');
  primes[0] = 'C';
  primes[1] = 'C';

  size_t index_of_p = primes.find("P");
  while(index_of_p != string::npos) {
    for(unsigned int i = index_of_p * 2; i <= nbr; i = i + index_of_p) {
      primes[i] = 'C';
    }
    index_of_p = primes.find("P", index_of_p + 1);
  }
  return primes;
}

int main() {
  string primes = getPrimes(200);
  cout << "Primes between 1 and 200: ";
  for(unsigned int i = 1; i < primes.length(); ++i) {
    if(primes[i] == 'P') {
      cout << i << " ";
    }
  }
  cout << endl;

  primes = getPrimes(100000);
  cout << "Largest prime less than 100,000: " << primes.find_last_of('P') << endl;
}
