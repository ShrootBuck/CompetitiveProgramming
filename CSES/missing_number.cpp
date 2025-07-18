

#include <bits/stdc++.h>
using namespace std;

int main() {
  long long n;
  cin >> n;

  long long sum = 0;

  long long expectedSum = n * (n + 1) / 2;

  for (int i = 0; i < n - 1; i++) {
    int x;
    cin >> x;
    sum += x;
  }

  cout << expectedSum - sum;
}
