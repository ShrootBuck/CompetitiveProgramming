#include <iostream>
#include <unordered_map>
#include <string>
#include <cstdio>
using namespace std;

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  // Farmer John needs Apple Maps

  setIO("whereami");

  int N;
  cin >> N;

  string mailboxes;
  cin >> mailboxes;

  for (int k = 1; k <= N; k++) {
    unordered_map<string, int> frequency;
    bool found = true;

    for (int i = 0; i <= N - k; i++) {
      string sub = mailboxes.substr(i, k);
      frequency[sub]++;

      if (frequency[sub] > 1) {
        found = false;
      }
    }

    if (found) {
      cout << k;
      return 0;
    }
  }
}
