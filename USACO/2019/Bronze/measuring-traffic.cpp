#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
};

struct road_stretch { // 1 mile stretch
  string ramp;
  int min;
  int max;
};

array<int, 2> collapse_ranges(int min1, int max1, int min2, int max2) {
  return {max(min1, min2), min(max1, max2)};
}

int main() {
  setIO("traffic");

  int N;
  cin >> N;

  vector<road_stretch> highway;

  for (int i = 0; i < N; i++) {
    string ramp;
    int min;
    int max;
    cin >> ramp >> min >> max;

    highway.push_back({ramp, min, max});
  }

  // Forward-pass
  int min = 0;
  int max = 100 * 1000 + 1;

  for (road_stretch road_stretch : highway) {
    if (road_stretch.ramp == "none") {
      array<int, 2> normalized =
          collapse_ranges(min, max, road_stretch.min, road_stretch.max);

      min = normalized[0];
      max = normalized[1];
    }

    if (road_stretch.ramp == "on") {
      max += road_stretch.max;
      min += road_stretch.min;
    }

    if (road_stretch.ramp == "off") {
      max -= road_stretch.min;
      min -= road_stretch.max;

      max = std::max(0, max);
      min = std::max(0, min);
    }
  }

  int end_min = min;
  int end_max = max;

  // Reverse-pass
  min = 0;
  max = 100 * 1000 + 1;

  for (int i = N - 1; i >= 0; i--) {
    road_stretch road_stretch = highway[i];

    if (road_stretch.ramp == "none") {
      array<int, 2> normalized =
          collapse_ranges(min, max, road_stretch.min, road_stretch.max);

      min = normalized[0];
      max = normalized[1];
    }

    if (road_stretch.ramp == "on") {
      max -= road_stretch.min;
      min -= road_stretch.max;

      max = std::max(0, max);
      min = std::max(0, min);
    }

    if (road_stretch.ramp == "off") {
      max += road_stretch.max;
      min += road_stretch.min;
    }
  }

  int start_min = min;
  int start_max = max;

  cout << start_min << " " << start_max;
  cout << "\n";
  cout << end_min << " " << end_max;
}
