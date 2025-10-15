#include <iostream>
#include <set>
using namespace std;

int main() {
  int N;
  cin >> N;
  set<int> nums;
  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    nums.insert(x);
  }

  cout << nums.size();
}
