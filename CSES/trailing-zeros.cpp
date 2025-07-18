#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;

  int zeros_count = 0;

  // (2, 5) prime combinations
  // 5 is "more rare" than 2
  // 5^n contributes n factors of 5

  // 5 is limiting reactant

  for (int k = 5; k <= n; k *= 5) {
    zeros_count += n / k;
  }

  cout << zeros_count;
}
