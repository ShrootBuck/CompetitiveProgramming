#include <bits/stdc++.h>
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
  setIO("citystate");

  // One to many (shoutout SQL)
  unordered_map<string, vector<string>> state_to_cities;

  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    string city, state;
    cin >> city >> state;

    state_to_cities[state].push_back(city.substr(0, 2));
  }

  int pairs = 0;

  for (auto pair : state_to_cities) {
    for (string statefrom : pair.second) {
      if (statefrom != pair.first) {
        auto it = state_to_cities.find(statefrom);
        if (it != state_to_cities.end()) {
          for (string stateto : it->second) {
            if (stateto == pair.first) {
              pairs++;
            }
          }
        }
      }
    }
  }

  cout << pairs / 2;
}
