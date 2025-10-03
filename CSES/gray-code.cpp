#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t n;
  cin >> n;

  for (unsigned long long i = 0; i < (1 << n); i++) {
    bitset<32> b(i);
    // only print the rightmost n bits
    cout << b.to_string().substr(32 - n);

    if (i != (1 << n) - 1) {
      cout << "\n";
    }
  }
}