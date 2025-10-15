#include <cmath>
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int sgn(int x) {
  if (x > 0) {
    return 1;
  } else if (x < 0) {
    return -1;
  } else {
    return 0;
  }
}

bool checksafe(const vector<int> &report) {
  bool safe = true;
  int dir;

  for (int i = 0; i < report.size() - 1; i++) {
    int j = i + 1;
    int diff = abs(report[j] - report[i]);

    if (diff < 1 || diff > 3) {
      safe = false;
      break;
    }

    // First look, get the direction
    if (i == 0) {
      dir = sgn(report[j] - report[i]);
    } else {
      int newdir = sgn(report[j] - report[i]);
      if (newdir != dir) {
        safe = false;
        break;
      }

      if (newdir == 0) {
        safe = false;
        break;
      }
    }
  }

  return safe;
}

int main() {
  string line;

  vector<vector<int>> reports;

  // Though I could process here, this line magic is too weird so I will
  // process later in vectors

  while (getline(cin, line)) {
    stringstream ss(line);
    int n;
    vector<int> nums;

    while (ss >> n) {
      nums.push_back(n);
    }

    reports.push_back(nums);
  }

  int total1 = 0;
  int total2 = 0;

  for (const auto &report : reports) {
    bool safe = checksafe(report);
    total1 += safe;

    if (safe) {
      total2++;
    } else {
      // Each permute of a report
      for (int i = 0; i < report.size(); i++) {
        // i is index to remove
        auto clone = report;
        clone.erase(clone.begin() + i);
        if (checksafe(clone)) {
          total2++;
          break;
        }
      }
    }
  }

  cout << "Part 1:\t";
  cout << total1;

  cout << "\n";

  cout << "Part 2:\t";
  cout << total2;
}
