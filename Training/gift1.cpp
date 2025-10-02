/*
ID: zayd1
LANG: C++
TASK: gift1
*/

#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
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
  setIO("gift1");

  int N;
  cin >> N;

  unordered_map<string, size_t> name_index;
  vector<int> accounts(N);
  vector<string> names;

  for (int i = 0; i < N; i++) {
    string name;
    cin >> name;

    name_index[name] = i;
    names.push_back(name);
  }

  string giver;

  while (cin >> giver) {
    int money, givings;
    int money_sent = 0;
    cin >> money >> givings;

    accounts[name_index[giver]] -= money;

    if (givings > 0) {
      for (int i = 0; i < givings; i++) {
        string given;
        cin >> given;

        accounts[name_index[given]] += (int)(money / givings);
        money_sent += (int)(money / givings);
      }

      accounts[name_index[giver]] += money - money_sent;
    } else {
      for (int i = 0; i < givings; i++) {
        string given;
        cin >> given;
      }
    }
  }

  for (int i = 0; i < N; i++) {
    cout << names[i] << " " << accounts[i] << "\n";
  }
}
