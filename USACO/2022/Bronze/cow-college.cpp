#include <iostream>
#include <vector>
#include <algorithm>
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
  setIO();

  int N;
  cin >> N;

  vector<long long> c(N);

  while (N--) {
    cin >> c[N];
  }

  sort(c.rbegin(), c.rend());

  long long max_pay = 0;
  long long tuition = 0;

  for (int i = 0; i < c.size(); i++) {
    long long new_max = (i + 1) * c[i];
    if (new_max >= max_pay) {
      max_pay = new_max;
      tuition = c[i];
    }
  }

  cout << max_pay << " " << tuition;
}
