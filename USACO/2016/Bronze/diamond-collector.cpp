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
  setIO("diamond");

  int N;
  int K;
  cin >> N >> K;

  vector<int> rocks(N);

  for (int i = 0; i < N; i++) {
    cin >> rocks[i];
  }

  sort(rocks.begin(), rocks.end());

  int count = 1;

  for (int i = 0; i < N; i++) {
    int local_count = 1;
    for (int j = i + 1; j < N && rocks[j] - rocks[i] <= K; j++) {
      local_count++;
    }

    count = max(count, local_count);
  }
  cout << count;
}
