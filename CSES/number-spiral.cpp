#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  for (int i = 1; i <= t; i++) {
    long long y;
    long long x;

    cin >> y;
    cin >> x;

    long long layer = max(x, y);
    long long k = layer * layer;

    // Even x -> Counting starts on Column
    if (layer % 2 == 0) {
      if (y > x) {
        cout << (k + 1 - x) << "\n";
      } else {
        cout << (k + 1 - x - (x - y)) << "\n";
      }
    }
    // Odd i -> Counting starts on Row
    else {
      if (y > x) {
        cout << (k + 1 - y - (y - x)) << "\n";
      } else {
        cout << (k + 1 - y) << "\n";
      }
    }
  }
}
