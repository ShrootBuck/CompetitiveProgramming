#include <bits/stdc++.h>
using namespace std;

int main() {
  string original;
  vector<string> strings;

  cin >> original;

  sort(original.begin(), original.end());

  do {
    strings.push_back(original);
  } while (next_permutation(original.begin(), original.end()));

  cout << strings.size();
  for (auto string : strings) {
    cout << "\n" << string;
  }
}
