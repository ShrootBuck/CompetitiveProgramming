#include <cmath>
#include <cstdlib>
#include <iostream>
using namespace std;

int main() {
  int n = 100;

  int sum_of_squares = 0;
  int square_of_sum = 0;

  for (int i = 1; i <= n; i++) {
    sum_of_squares += i * i;
    square_of_sum += i;
  }

  square_of_sum *= square_of_sum;

  cout << abs(sum_of_squares - square_of_sum);
}
