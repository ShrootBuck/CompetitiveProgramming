#include <bits/stdc++.h>
#include <numeric>
using namespace std;

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
  long long n = 1;
  for (int i = 2; i <= 20; i++) {
    n = lcm(n, i);
  }
  cout << n << "\n";
}