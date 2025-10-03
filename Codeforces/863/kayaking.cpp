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
  setIO();

  int n;
  cin >> n;

  vector<int> weights(2 * n);

  for (int i = 0; i < 2 * n; i++) {
    cin >> weights[i];
  }

  sort(weights.begin(), weights.end());

  int instability = 1000 * 50 + 1;

  for (int i = 0; i < weights.size() - 1; i++) {
    for (int j = i + 1; j < weights.size(); j++) {
      auto new_weights = weights;
      new_weights.erase(new_weights.begin() + j);
      new_weights.erase(new_weights.begin() + i);

      int local_instability = 0;

      for (int k = 0; k < new_weights.size() - 1; k += 2) {
        local_instability += new_weights[k + 1] - new_weights[k];
      }

      instability = min(local_instability, instability);
    }
  }

  cout << instability;
}
