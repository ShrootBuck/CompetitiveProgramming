#include <cstdio>
#include <iostream>
#include <set>
#include <string>
#include <unordered_set>
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
  setIO("");
  int k, n;
  cin >> k >> n;

  vector<ll> jury_marks(k);
  vector<ll> jury_prefix(k);
  unordered_set<ll> prefix_sums;

  vector<ll> polycarp_memory(n);

  unordered_set<ll> candidates;

  for (int i = 0; i < k; i++) {
    cin >> jury_marks[i];

    if (i == 0) {
      jury_prefix[i] = jury_marks[i];
    } else {
      jury_prefix[i] = jury_prefix[i - 1] + jury_marks[i];
    }

    prefix_sums.insert(jury_prefix[i]);
  }

  for (int i = 0; i < n; i++) {
    cin >> polycarp_memory[i];
  }

  set<ll> answers;

  for (int i = 0; i < k; i++) {
    candidates.insert(polycarp_memory[0] - jury_prefix[i]);
  }

  for (auto &candidate : candidates) {
    bool ok = true;

    for (auto &score : polycarp_memory) {
      if (prefix_sums.count(score - candidate) == 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      answers.insert(candidate);
    }
  }

  cout << answers.size();
}
