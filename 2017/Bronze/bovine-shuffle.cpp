#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shuffle.in", "r", stdin);
  freopen("shuffle.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  size_t N;
  cin >> N;

  // Get every a[i]
  vector<int> a(N);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  // Get every cow id in the final lineup
  vector<int> lineup(N);
  for (int i = 0; i < N; i++) {
    cin >> lineup[i];
  }

  // unshuffle 3x
  vector<int> unshuffled_lineup(N);

  for (int j = 0; j < N; j++) {
    int index = j;
    for (int i = 0; i < 3; i++) {
      auto it = find(a.begin(), a.end(), index + 1);
      index = it - a.begin();
      // cout << index << " ";
    }

    // cout << index << " ";
    unshuffled_lineup[index] = lineup[j];
  }

  //   cout << "\n\n";
  for (int cow : unshuffled_lineup) {
    cout << cow << "\n";
  }
}