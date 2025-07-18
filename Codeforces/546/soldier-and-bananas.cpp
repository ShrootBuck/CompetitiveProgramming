

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long k, n, w;
  cin >> k >> n >> w;

  long long total_cost = 0;

  // Calculate total cost
  for (int i = 1; i <= w; i++) {
    total_cost += i * k;
  }

  cout << max(0, (int)(total_cost - n));
}
