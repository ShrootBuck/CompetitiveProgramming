// Source: https://usaco.guide/general/io

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

    while (num < oldNum) {
      num++;
      ops++;
    }

    oldNum = num;
  }

  cout << ops;
}
