#include <bits/stdc++.h>
#include <cmath>
using namespace std;

bool checkprime(const int &n) {
  if (n == 1) {
    return false;
  }

  bool prime = true;

  for (int i = 2; i <= (int)sqrt(n); i++) {
    if (n % i == 0) {
      prime = false;
      break;
    }
  }

  return prime;
}
int main() {
  // Generate prime numbers
  int n = 10001;
  int current = 0;
  int i = 0;

  while (current <= 10001) {
    i++;
    if (checkprime(i)) {
      current++;

      if (current == 10001) {
        cout << i;
      }
    }
  }
}
