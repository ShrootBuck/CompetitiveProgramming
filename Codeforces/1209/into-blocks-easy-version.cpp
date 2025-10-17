#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

#define ll long long

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

int main() {
  setIO();

  int n, q;
  cin >> n >> q;

  vector<int> arr(n);
  unordered_map<int, pair<int, int>> boundings;
  multiset<int> freq;

  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;

    arr[i] = number;

    if (freq.count(number) == 0) {
      boundings[number] = {i, i};
    } else {
      boundings[number].second = i;
    }

    freq.insert(number);
  }

  int total = 0;
  int start = 0;
  int max_right = 0;

  for (int i = 0; i < n; i++) {
    max_right = max(max_right, boundings[arr[i]].second);

    if (i == max_right) {
      unordered_map<int, int> sub_freq;
      int max_sub_freq = 0;

      for (int j = start; j <= i; j++) {
        sub_freq[arr[j]]++;
        max_sub_freq = max(max_sub_freq, sub_freq[arr[j]]);
      }
      total += (i - start + 1) - max_sub_freq;

      start = i + 1;
    }
  }

  cout << total;
}
