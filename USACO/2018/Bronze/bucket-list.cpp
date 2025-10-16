#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
using namespace std;

void setIO(std::string name = "") {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

struct cow {
  int s;
  int t;
  int b;
};

int main() {
  setIO("blist");

  int N;
  cin >> N;

  int total_time = 0;

  vector<cow> unmilked_cows(N);

  for (int i = 0; i < N; i++) {
    cin >> unmilked_cows[i].s;
    cin >> unmilked_cows[i].t;
    cin >> unmilked_cows[i].b;

    total_time = max(total_time, unmilked_cows[i].t);
  };

  int buckets_in_use = 0;
  int max_buckets_in_use = 0;

  for (int i = 1; i <= total_time; i++) {
    for (cow cow : unmilked_cows) {
      if (i > cow.s) {
        if (i < cow.t) {
          // Is milking
        } else if (cow.t == i) {
          buckets_in_use -= cow.b;
        }
      } else if (cow.s == i) {
        int buckets_left = cow.b;
        while (buckets_left > cow.b) {
          buckets_in_use++;
          buckets_left--;
        }

        buckets_in_use += buckets_left;
      }
    }

    max_buckets_in_use = max(max_buckets_in_use, buckets_in_use);
  }

  cout << max_buckets_in_use;
}