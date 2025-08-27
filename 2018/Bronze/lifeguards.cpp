#include <algorithm>
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
  setIO("lifeguards");

  int N;
  cin >> N;

  int max_covered = 0;
  vector<pair<int, int>> shifts{};

  for (int i = 0; i < N; i++) {
    int start, end;
    cin >> start >> end;
    shifts.push_back({start, end});
  }

  for (int i = 0; i < N; i++) {
    array<bool, 1000> times{};
    for (int j = 0; j < N; j++) {
      if (j == i) {
        continue;
      }

      for (int k = shifts[j].first; k < shifts[j].second; k++) {
        times[k] = true;
      }
    }

    int localmax = 0;
    for (bool time : times) {
      if (time) {
        localmax++;
      }
    }

    max_covered = max(localmax, max_covered);
  }

  cout << max_covered;
}
