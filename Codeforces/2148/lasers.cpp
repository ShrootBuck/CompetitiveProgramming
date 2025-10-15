#include <cstdio>
#include <iostream>
#include <string>
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
    int crosses = 0;

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    for (int i = 0; i < n; i++) {
      int laser_y;
      cin >> laser_y;

      crosses += (laser_y <= y);
    }

    for (int i = 0; i < m; i++) {
      int laser_x;
      cin >> laser_x;

      crosses += (laser_x <= x);
    }

    cout << crosses << "\n";
  }
}
