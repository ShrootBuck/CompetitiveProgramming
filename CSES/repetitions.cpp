#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string sequence;
  cin >> sequence;

  char last = 'L';
  long count = 0;
  long maxCount = 0;

  for (unsigned long i = 0; i < sequence.length(); i++) {
    if (sequence[i] == last) {
      count++;
    } else {
      maxCount = max(maxCount, count);
      count = 0;
    }

    last = sequence[i];
  }

  maxCount = max(maxCount, count);

  cout << maxCount + 1;
}
