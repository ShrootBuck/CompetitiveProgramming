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
  setIO();

  int N;
  cin >> N;

  vector<int> a;
  vector<int> b;
  vector<int> ans(N + 1, 0);

  for (int i = 0; i < N; ++i) {
    int temp_a;
    cin >> temp_a;
    a.push_back(temp_a);
  }

  for (int i = 0; i < N; ++i) {
    int temp_b;
    cin >> temp_b;
    b.push_back(temp_b);
  }

  // Calculate the base case: number of matches with no reversal (l == r)
  int alreadySame = 0;
  for (int i = 0; i < N; ++i) {
    if (a[i] == b[i]) {
      alreadySame++;
    }
  }

  // expand() takes a center (l, r) and expands outwards, calculating matches
  auto expand = [&](int l, int r) {
    int current_matches = alreadySame;

    // Expands the window [l, r] outwards until it hits an edge
    for (; l >= 0 && r < N; --l, ++r) {
      current_matches -= (a[l] == b[l]);
      if (l != r) { // Avoid double-counting for single-element centers
        current_matches -= (a[r] == b[r]);
      }

      // Add their new contribution now that they are swapped
      current_matches += (a[l] == b[r]);
      if (l != r) {
        current_matches += (a[r] == b[l]);
      }

      ans[current_matches]++;
    }
  };

  for (int mid = 0; mid < N; ++mid) {
    // Case 1: Odd-length reversals, centered at mid
    // The first reversal is (mid, mid), then (mid-1, mid+1), etc
    expand(mid, mid);

    // Case 2: Even-length reversals, centered between mid and mid+1
    // The first reversal is (mid, mid+1), then (mid-1, mid+2), etc
    expand(mid, mid + 1);
  }

  for (int count : ans) {
    cout << count << "\n";
  }
}