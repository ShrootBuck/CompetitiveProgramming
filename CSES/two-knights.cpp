#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;

  for (long long k = 1; k <= n; k++) {
    // Get the max possible board positions
    // e.g. how many different combinations of knight placement
    // This is k^2 choose 2

    long long total_combinations = ((k * k) * (k * k - 1)) / 2;
    long long possible_attacks = (k - 2) * (k - 1) * 4;

    cout << total_combinations - possible_attacks << "\n";
  }
}
