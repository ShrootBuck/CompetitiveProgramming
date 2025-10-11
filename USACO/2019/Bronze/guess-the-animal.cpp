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
  setIO("guess");

  int N;
  cin >> N;

  vector<set<string>> animals;

  for (int i = 0; i < N; i++) {
    string dummy;
    cin >> dummy; // 45 years and this is the best they came up with

    int K;
    cin >> K;

    animals.push_back({});

    for (int k = 0; k < K; k++) { // I know
      string feature;
      cin >> feature;

      animals[i].insert(feature);
    }
  }

  int max_shared = 0;

  for (int i = 0; i < animals.size() - 1; i++) {
    set<string> animal_a = animals[i];

    for (int j = i + 1; j < animals.size(); j++) {
      set<string> animal_b = animals[j];

      set<string> intersection_result;
      set_intersection(
          animal_a.begin(), animal_a.end(), animal_b.begin(), animal_b.end(),
          std::inserter(intersection_result, intersection_result.begin()));

      max_shared = max(max_shared, (int)intersection_result.size());
    }
  }

  cout << max_shared + 1;
}
