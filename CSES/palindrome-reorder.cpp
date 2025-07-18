#include <bits/stdc++.h>
using namespace std;

int main() {

  const string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string first_half = "";
  string second_half = "";
  string middle = "";

  int num_odds = 0;

  array<int, 26> letter_store{};

  string input;
  cin >> input;

  for (unsigned long i = 0; i < input.length(); i++) {

    letter_store[alphabet.find_first_of(input[i])]++;
  }

  for (unsigned long i = 0; i < 26; i++) {
    if (letter_store[i] % 2 == 0) {
      for (int j = 0; j < letter_store[i]; j++) {
        if (j % 2 == 0) {
          first_half.push_back(alphabet[i]);
        }
      }
    } else {
      num_odds++;
      for (int j = 0; j < letter_store[i]; j++) {
        middle += alphabet[i];
      }
    }
  }

  if (num_odds > 1) {
    cout << "NO SOLUTION";
    return 0;
  }

  second_half = first_half;
  reverse(second_half.begin(), second_half.end());

  cout << first_half << middle << second_half;
}
