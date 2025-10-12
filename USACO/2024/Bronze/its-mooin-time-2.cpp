#include <bits/stdc++.h>
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

  int N, F;
  cin >> N >> F;

  string contest;
  cin >> contest;

  unordered_map<string, int> occurrences;
  set<string> moos;

  // Shoutout editorial for teaching me lambdas
  auto is_moo = [&](int i) {
    if (i < 0 or i + 2 >= N) {
      return false;
    }

    return (contest[i] != contest[i + 1] && contest[i + 1] == contest[i + 2]);
  };

  auto update_point = [&](int i, int delta) {
    if (!is_moo(i)) {
      return; // Nothing to do if it's not a moo
    }

    string moo = contest.substr(i, 3);
    occurrences[moo] += delta;

    if (occurrences[moo] >= F) {
      moos.insert(moo);
    }
  };

  auto update_range = [&](int k, int delta) {
    for (int i = k - 2; i <= k; i++) {
      update_point(i, delta);
    }
  };

  for (int i = 0; i < contest.size() - 2; i++) {
    if (is_moo(i)) {
      occurrences[contest.substr(i, 3)]++;
    }
  }

  for (auto occurrence : occurrences) {
    if (occurrence.second >= F) {
      moos.insert(occurrence.first);
    }
  }

  for (int k = 0; k < N; ++k) {
    char original_char = contest[k];

    update_range(k, -1);

    // all possible replacement characters, though I feel there's a faster way?
    for (char new_char = 'a'; new_char <= 'z'; new_char++) {
      if (new_char == original_char) {
        continue;
      }

      // Put the test character into the string
      contest[k] = new_char;

      // Test it
      update_range(k, +1);
      // Undo test
      update_range(k, -1);
    }

    // Reset global state before next character
    contest[k] = original_char;
    update_range(k, +1);
  }

  cout << moos.size();
  for (string moo : moos) {
    cout << "\n" << moo;
  }
}
