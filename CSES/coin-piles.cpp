#include <algorithm>
#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {

    int a;
    int b;
    cin >> a >> b;
    // TEST 3, 6

    if ((a + b) % 3 == 0) {
      if (max(a, b) <= 2 * min(a, b)) {
        cout << "YES" << "\n";

      } else {
        cout << "NO" << "\n";
      }
    } else {
      cout << "NO" << "\n";
    }
  }
}
