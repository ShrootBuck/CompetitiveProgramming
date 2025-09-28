#include <bits/stdc++.h>
using namespace std;

struct Cow {
  int s, t, c;
};

struct AC {
  int a, b, p, m;
};

int N, M;
int min_cost = 10 * 1000;
vector<int> subset;
vector<int> cooling_needs(101);

void search(int k, const vector<Cow> &cows, const vector<AC> &conditioners) {
  if (k == M) {
    // Process this subset
    auto temp_needs = cooling_needs;
    int local_cost = 0;

    for (int i : subset) {
      // Use conditioner conditioners[i]
      auto conditioner = conditioners[i];
      local_cost += conditioner.m;

      for (int i = conditioner.a; i <= conditioner.b; i++) {
        temp_needs[i] -= conditioner.p;
      }
    }

    // Check if any are > 0
    bool ok = true;

    for (int stall : temp_needs) {
      if (stall > 0) {
        ok = false;
        break;
      }
    }

    if (ok) {
      min_cost = min(min_cost, local_cost);
    }

    return;
  }

  search(k + 1, cows, conditioners);
  subset.push_back(k);
  search(k + 1, cows, conditioners);
  subset.pop_back();
}

int main() {
  cin >> N >> M;
  vector<Cow> cows(N);
  vector<AC> conditioners(M);

  for (int i = 0; i < N; i++) {
    cin >> cows[i].s >> cows[i].t >> cows[i].c;
  }

  for (int i = 0; i < M; i++) {
    cin >> conditioners[i].a >> conditioners[i].b >> conditioners[i].p >>
        conditioners[i].m;
  }

  // Fill our vector of cooling needs
  for (auto cow : cows) {
    for (int i = cow.s; i <= cow.t; i++) {
      cooling_needs[i] = cow.c;
    }
  }
  search(0, cows, conditioners);

  cout << min_cost;
}
