#include <iostream>
#include <vector>
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
  setIO("cownomics");

  int N, M;
  cin >> N >> M;

  vector<string> spotted;
  vector<string> plain;

  for (int i = 0; i < N; i++) {
    string genome;
    cin >> genome;

    spotted.push_back(genome);
  }

  for (int i = 0; i < N; i++) {
    string genome;
    cin >> genome;

    plain.push_back(genome);
  }

  int sets = 0;

  for (int p1 = 0; p1 < M - 2; p1++) {
    for (int p2 = p1 + 1; p2 < M - 1; p2++) {
      for (int p3 = p2 + 1; p3 < M; p3++) {
        for (int i = 0; i < N; i++) {
          char c1 = spotted[i][p1];
          char c2 = spotted[i][p2];
          char c3 = spotted[i][p3];

          bool valid = true;

          for (int j = 0; j < N; j++) {
            bool comp1 = c1 == plain[j][p1];
            bool comp2 = c2 == plain[j][p2];
            bool comp3 = c3 == plain[j][p3];

            if (comp1 && comp2 && comp3) {
              valid = false;
            }
          }

          if (!valid) {
            break;
          }

          if (i == N - 1) {
            sets++;
          }
        }
      }
    }
  }

  cout << sets;
}
