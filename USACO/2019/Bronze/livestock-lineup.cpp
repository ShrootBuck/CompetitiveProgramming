#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int n;
vector<string> current = {
    "Beatrice", "Belinda", "Bella",     "Bessie",
    "Betsy",    "Blue",    "Buttercup", "Sue",
};
vector<pair<string, string>> neighbors;

bool check_valid() {
  bool ok = true;

  for (auto cowpair : neighbors) {
    long index1 = distance(current.begin(),
                           find(current.begin(), current.end(), cowpair.first));
    long index2 = distance(
        current.begin(), find(current.begin(), current.end(), cowpair.second));

    if (abs(index1 - index2) != 1) {
      ok = false;
      break;
    }
  }

  return ok;
}

int main() {
  setIO("lineup");

  sort(current.begin(), current.end());

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string cow1, cow2, trash;
    cin >> cow1 >> trash >> trash >> trash >> trash >> cow2;

    neighbors.push_back({cow1, cow2});
  }

  do {
    if (check_valid()) {
      for (string cow : current) {
        cout << cow << "\n";
      }

      return 0;
    }
  } while (next_permutation(current.begin(), current.end()));
}
