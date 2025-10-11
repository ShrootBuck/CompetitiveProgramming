#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> a;
  vector<int> b;
  vector<int> c(N + 1, 0);

  for (int i = 0; i < N; i++) {
    int temp_a;
    cin >> temp_a;

    a.push_back(temp_a);
  }

  for (int i = 0; i < N; i++) {
    int temp_b;
    cin >> temp_b;

    b.push_back(temp_b);
  }

  // Check every possible (l, r)
  for (int l = 0; l < N; l++) {
    for (int r = l; r < N; r++) {
      // For every (l, r) pair, check EVERY a[i] b[i] pair (with the l-r swap)
      int pairs = 0;

      for (int i = 0; i < N; i++) {
        // Check if i is between l and r
        if ((l <= i) && (i <= r)) {
          if (a[(r - i + l)] == b[i]) {
            pairs++;
          }
        } else {
          if (a[i] == b[i]) {
            pairs++;
          }
        }
      }

      c[pairs]++;
    }
  }

  for (int count : c) {
    cout << count << "\n";
  }
}
