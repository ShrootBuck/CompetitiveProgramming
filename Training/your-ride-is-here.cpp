/*
ID: zayd1
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <iostream>
#include <string>
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
  setIO("ride");

  string a, b;
  cin >> a >> b;

  int numa = 1;
  int numb = 1;

  for (auto c : a) {
    numa *= c - 'A' + 1;
  }

  for (auto c : b) {
    numb *= c - 'A' + 1;
  }

  numa %= 47;
  numb %= 47;

  if (numa == numb) {
    cout << "GO";
  } else {
    cout << "STAY";
  }

  cout << "\n";
  return 0;
}
