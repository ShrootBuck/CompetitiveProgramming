#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
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
  setIO("diamond");

  size_t N;
  size_t K;
  cin >> N >> K;

  vector<int> rocks(N);

  for (size_t i = 0; i < N; i++) {
    cin >> rocks[i];
  }

  sort(rocks.begin(), rocks.end());

  size_t count = 1;

  // Sliding window
  // What an elegant solution I wish I thought of this earlier
  size_t left = 0;
  size_t right = 0;

  while (right < N) {
    while (right < N && rocks[right] - rocks[left] <= K) {
      right++;
    }

    count = max(count, right - left);

    left++;
  }

  cout << count;
}
