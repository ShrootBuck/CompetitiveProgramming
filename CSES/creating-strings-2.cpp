#include <bits/stdc++.h>
using namespace std;

string s;
vector<string> permutations;
int char_count[26];

void search(string current) {
  // Finished permutitating a permutational permuter
  if (s.size() == current.size()) {
    permutations.push_back(current);
    return;
  }

  for (int i = 0; i < 26; ++i) {
    // For available characters only!
    if (char_count[i] > 0) {
      // Add to current and search
      --char_count[i];
      search(current + (char)(i + 'a'));
      ++char_count[i];
    }
  }
}

int main() {
  cin >> s;

  for (char c : s) {
    ++char_count[c - 'a'];
  }

  search("");

  cout << permutations.size();

  for (string p : permutations) {
    cout << "\n" << p;
  }

  return 0;
}
