#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {

  setIO("blocks");

  int N;
  cin >> N;

  array<int, 26> letters_count{};

  for (int i = 0; i < N; i++) {
    map<char, int> alphabet1;
    map<char, int> alphabet2;

    string word1, word2;
    cin >> word1 >> word2;

    for (char character : word1) {
      if (alphabet1.find(character) != alphabet1.end()) {
        alphabet1[character]++;
      } else {
        alphabet1[character] = 1;
      }
    }

    for (char character : word2) {
      if (alphabet2.find(character) != alphabet2.end()) {
        alphabet2[character]++;
      } else {
        alphabet2[character] = 1;
      }
    }

    for (int j = 0; j < 26; j++) {
      char character = "abcdefghijklmnopqrstuvwxyz"[j];

      letters_count[j] += max(alphabet1[character], alphabet2[character]);
    }
  }

  for (int count : letters_count) {
    cout << count << "\n";
  }
}