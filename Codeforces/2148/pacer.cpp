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

  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> requirements{{0, 0}};
    int points = 0;

    for (int i = 0; i < n; i++) {
      int a, b;
      cin >> a >> b;
      requirements.push_back({a, b});
    }

    for (int i = 0; i < n; i++) {
      int time_diff = requirements[i + 1].first - requirements[i].first;

      bool parity = requirements[i].second == requirements[i + 1].second;

      if (time_diff % 2 == 0) {
        if (parity) {
          points += time_diff;
        } else {
          points += time_diff - 1;
        }
      } else {
        if (!parity) {
          points += time_diff;
        } else {
          points += time_diff - 1;
        }
      }
    }

    // Add remaining laps post-requirements
    points += m - requirements[n].first;

    cout << points << "\n";
  }
}
