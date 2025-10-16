#include <algorithm>
#include <cstdio>
#include <iostream>
#include <set>
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

int main() {
  setIO("balancing");

  int N, B;
  cin >> N >> B;

  vector<pair<int, int>> coordinates;
  set<int> unique_x;
  set<int> unique_y;

  for (int i = 0; i < N; i++) {
    int x, y;
    cin >> x >> y;
    coordinates.push_back({x, y});
    unique_x.insert(x);
    unique_y.insert(y);
  }

  int M = N;

  for (int x : unique_x) {
    for (int y : unique_y) {
      int a = x + 1;
      int b = y + 1;
      array<int, 4> quadrants{};
      int local_M = 0;

      for (pair<int, int> coordinate : coordinates) {
        if (coordinate.first > a && coordinate.second > b) { // Quadrant I
          quadrants[0]++;
        } else if (coordinate.first < a &&
                   coordinate.second > b) { // Quadrant II
          quadrants[1]++;
        } else if (coordinate.first < a &&
                   coordinate.second < b) { // Quadrant III
          quadrants[2]++;
        } else { // Quadrant IV
          quadrants[3]++;
        }
      }

      for (int cows : quadrants) {
        local_M = max(cows, local_M);
      }

      M = min(local_M, M);
    }
  }

  cout << M;
}
