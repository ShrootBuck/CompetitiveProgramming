#include <bits/stdc++.h>
using namespace std;

int tank1 = 1000;
int tank2 = 1000;

// cX values are CAPACITIES of barn X
vector<int> c1(10);
vector<int> c2(10);

set<int> readings;

vector<int> bucket_order;
int choices = 0;

void solve(int day, int milk1, vector<int> buckets1, vector<int> buckets2) {
  if (day == 4) {
    // BOOM! base case
    readings.insert(milk1);
    return;
  }

  if (day % 2 == 0) { // Tuesday (0) or Thursday (2): move from barn 1 to 2
    for (int i = 0; i < buckets1.size(); i++) {
      int b = buckets1[i];
      int new_milk = milk1 - b;

      auto new_buckets1 = buckets1;
      new_buckets1.erase(new_buckets1.begin() + i);

      auto new_buckets2 = buckets2;
      new_buckets2.push_back(b);

      // 5. Make the recursive call for the next day
      solve(day + 1, new_milk, new_buckets1, new_buckets2);
    }
  } else { // Wednesday (1) or Friday (3): move from barn 2 to 1
    for (int i = 0; i < buckets2.size(); i++) {
      int b = buckets2[i];
      int new_milk = milk1 + b;

      auto new_buckets2 = buckets2;
      new_buckets2.erase(new_buckets2.begin() + i);

      auto new_buckets1 = buckets1;
      new_buckets1.push_back(b);

      // 5. Make the recursive call for the next day
      solve(day + 1, new_milk, new_buckets1, new_buckets2);
    }
  }
}

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

bool search() {}

int main() {
  setIO("backforth");

  for (int i = 0; i < 10; ++i) {
    cin >> c1[i];
  }

  for (int i = 0; i < 10; ++i) {
    cin >> c2[i];
  }

  // Kick off the recursion with the starting state
  solve(0, 1000, c1, c2);

  cout << readings.size();
}
