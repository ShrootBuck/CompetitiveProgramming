// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t n;
  cin >> n;

  int total_confident_problems = 0;

  for (size_t i = 0; i < n; i++) {
    int confident1, confident2, confident3;
    cin >> confident1 >> confident2 >> confident3;

    if (confident1 + confident2 + confident3 > 1) {
      total_confident_problems++;
    }
  }

  cout << total_confident_problems;
}
