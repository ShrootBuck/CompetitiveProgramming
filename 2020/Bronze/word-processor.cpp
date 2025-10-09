#include <bits/stdc++.h>

using namespace std;
int main() {
  freopen("word.in", "r", stdin);
  freopen("word.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  size_t n, k;
  cin >> n >> k;
  vector<string> words(n);

  for (size_t i = 0; i < n; i++) {
    cin >> words[i];
  }

  cout << words[0];
  size_t current_line = words[0].length();

  for (size_t i = 1; i < n; i++) {
    if (words[i].length() + current_line <= k) {
      cout << " " << words[i];
      current_line += words[i].length();
    } else { // No space on this line, newline
      cout << "\n" << words[i];
      current_line = words[i].length();
    }
  }
}
