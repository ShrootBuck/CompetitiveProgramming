
// Permutations

#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  vector<int> evens;
  vector<int> odds;

  if (n == 2 || n == 3) {
    cout << "NO SOLUTION";
    return 0;
  }

  for (int i = 1; i <= n; i++) {
    if (i % 2 == 0) {
      evens.push_back(i);
    } else {
      odds.push_back(i);
    }
  }

  for (int even : evens) {
    cout << even << " ";
  }

  for (int odd : odds) {
    cout << odd << " ";
  }
}
