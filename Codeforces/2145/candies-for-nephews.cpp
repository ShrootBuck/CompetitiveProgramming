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
  setIO("");

  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    cout << (3 - (n % 3)) % 3;

    if (t != 0) {
      cout << "\n";
    }
  }
}
