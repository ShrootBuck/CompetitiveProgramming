

#include <bits/stdc++.h>

using namespace std;

int main() {
  unsigned long n;

  cin >> n;
  unsigned long ops = 0;
  unsigned long oldNum;

  cin >> oldNum;

  for (unsigned long i = 1; i < n; i++) {
    unsigned long num;
    cin >> num;

    if (num < oldNum) {
      ops += oldNum - num;
      num = oldNum;
    }

    oldNum = num;
  }

  cout << ops;
}
