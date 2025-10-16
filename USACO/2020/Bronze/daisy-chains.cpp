#include <iostream>
#include <vector>
using namespace std;

int main() {
  size_t N;
  cin >> N;

  vector<size_t> flowers(N);

  for (size_t i = 0; i < N; i++) {
    cin >> flowers[i];
  }

  int count = 0;

  for (size_t i = 0; i < N; i++) {
    for (size_t j = i; j < N; j++) {
      // (i, j) pair begins here

      size_t petals = 0;

      // Calculate sum of petals in range [i, j]
      for (size_t k = i; k <= j; k++) {
        petals += flowers[k];
      }

      // Check if average is a whole number
      size_t subset_size = j - i + 1;
      if (petals % subset_size == 0) {
        size_t avg = petals / subset_size;

        // Check if any flower in range [i, j] has avg petals
        for (size_t k = i; k <= j; k++) {
          if (flowers[k] == avg) {
            count++;
            break;
          }
        }
      }
    }
  }

  cout << count;
}