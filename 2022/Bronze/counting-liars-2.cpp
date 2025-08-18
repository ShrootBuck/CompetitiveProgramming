#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t N;
  cin >> N;

  size_t liars = 0;

  vector<pair<int, char>> sightings{};

  for (int i = 0; i < N; i++) {
    char dir;
    int p;
    cin >> dir;
    cin >> p;

    sightings.push_back({p, dir});

    if (dir == 'G') {
      liars++;
    }
  }

  sort(sightings.begin(), sightings.end());

  size_t local_liars = liars;

  for (int i = 0; i < N; i++) {

    if (sightings[i].second == 'G') {
      local_liars--;
    } else {
      local_liars++;
    }

    liars = min(liars, local_liars);
  }

  cout << liars;
}
