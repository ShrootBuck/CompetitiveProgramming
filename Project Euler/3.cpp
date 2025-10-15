#include <cmath>
#include <iostream>
using namespace std;

int main() {
  size_t N = 600851475143;
  size_t x = N;
  size_t biggest;

  for (int i = 2; i <= sqrt(N); i++) {
    while (x % i == 0) {
      x /= i;
      biggest = i;
    }
  }

  cout << biggest;
}
