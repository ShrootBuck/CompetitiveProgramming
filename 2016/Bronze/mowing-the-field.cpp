#include <bits/stdc++.h>
#include <climits>
#include <unordered_map>
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
  setIO("mowing");

  int N;
  cin >> N;

  int t = 0;
  long long x = LLONG_MAX;

  int fj_x = 0;
  int fj_y = 0;

  unordered_map<int, unordered_map<int, int>> field{}; // field[X][Y] = 0 or t+1
  bool lapped = false;

  field[0][0] = 1;

  for (int i = 0; i < N; i++) {
    char dir;
    int steps;

    cin >> dir >> steps;

    for (int j = 0; j < steps; j++) {
      t++;

      switch (dir) {
      case 'N':
        fj_y++;
        break;

      case 'E':
        fj_x++;
        break;

      case 'S':
        fj_y--;
        break;

      case 'W':
        fj_x--;
        break;
      }

      int current_patch = field[fj_x][fj_y];

      if (current_patch != 0) {
        lapped = true;
        x = min(x, (long long)(t - current_patch +
                               1)); // Since we store t+1, we do (t+1) - 1 = t
      }

      field[fj_x][fj_y] = t + 1;
    }
  }

  if (lapped) {
    cout << x;
  } else {
    cout << -1;
  }
}
