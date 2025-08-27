#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <utility>
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
  setIO("lifeguards");

  int N;
  cin >> N;

  int max_covered = 0;
  map<int, pair<int, int>> events; // events[t] = [-1/1, cowID]

  for (int i = 0; i < N; i++) {
    int start, end;
    cin >> start >> end;
    events[start] = {1, i};
    events[end] = {-1, i};
  }

  int active = 0;
  int last = events.begin()->first;
  vector<int> alone_time(N, 0);
  set<int> active_cows;
  int total_covered = 0;

  for (auto const &[time, details] : events) {

    if (active > 0) {
      total_covered += time - last;
    }

    if (active == 1) {
      int lone_cow = *active_cows.begin();
      alone_time[lone_cow] += time - last;
    }

    int type = details.first;
    int cow_id = details.second;

    if (type == 1) { // A cow is starting
      active_cows.insert(cow_id);
    } else { // A cow is ending
      active_cows.erase(cow_id);
    }

    active += details.first;
    last = time;
  }

  int min_loss = *min_element(alone_time.begin(), alone_time.end());

  max_covered = total_covered - min_loss;

  cout << max_covered;
}
