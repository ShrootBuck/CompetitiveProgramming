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
  setIO("cownomics");

  size_t N, K;

  cin >> N >> K;

  vector<vector<char>> table(2 * N, vector<char>(K));

  size_t count = 0;

  // Load in our data
  for (size_t i = 0; i < 2 * N; i++) {
    for (size_t j = 0; j < K; j++) {
      cin >> table[i][j];
    }
  }

  for (size_t i = 0; i < K; i++) {
    unordered_map<char, bool> seen{
        {'A', false}, {'C', false}, {'G', false}, {'T', false}};

    for (size_t j = 0; j < N; j++) {
      seen[table[j][i]] = true;
    }

    bool valid = true;

    for (size_t j = N; j < 2 * N; j++) {
      if (seen[table[j][i]]) {
        valid = false;
      }
    }

    if (valid) {
      count++;
    }
  }

  cout << count;
}
