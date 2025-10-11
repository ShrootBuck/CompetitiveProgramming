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
  setIO("angry");

  int N;
  cin >> N;

  vector<int> x(N);

  for (int i = 0; i < N; i++) {
    cin >> x[i];
  }

  sort(x.begin(), x.end());

  int exploded = 0;

  // Try every single starting haybale
  for (int i = 0; i < N; i++) {
    // left
    int l = i;
    int radius_l = 1;

    while (true) {
      int new_l = l;

      while (new_l - 1 >= 0 && x[l] - x[new_l - 1] <= radius_l) {
        new_l--;
      }

      if (new_l == l) {
        break;
      }

      l = new_l;
      radius_l++;
    }

    // right
    int r = i;
    int radius_r = 1;

    while (true) {
      int new_r = r;

      while (new_r + 1 < N && x[new_r + 1] - x[r] <= radius_r) {
        new_r++;
      }

      if (new_r == r) {
        break;
      }

      r = new_r;
      radius_r++;
    }

    int total = r - l + 1; // +1 is for the originally sniped barrel
    exploded = max(exploded, total);
  }

  cout << exploded;
}
