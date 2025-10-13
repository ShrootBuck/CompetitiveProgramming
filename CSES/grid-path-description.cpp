#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

string path;

int valid = 0;
int visited[7][7];

bool is_blocked(int row, int col) {
  return (row > 6 || row < 0 || col > 6 || col < 0 || visited[row][col]);
}

// Optimization edge-case HELL
bool impossible_path(int row, int col) {
  if (is_blocked(row, col)) {
    return true;
  }

  if (is_blocked(row - 1, col) && is_blocked(row + 1, col) &&
      !is_blocked(row, col - 1) && !is_blocked(row, col + 1)) {
    // This path is a horizontal wall, doomed to fail
    return true;
  }

  if (is_blocked(row, col - 1) && is_blocked(row, col + 1) &&
      !is_blocked(row - 1, col) && !is_blocked(row + 1, col)) {
    // Same as above, but this is a vertical wall
    return true;
  }

  // Up-Right pocket
  if (is_blocked(row - 1, col) && is_blocked(row, col + 1) &&
      !is_blocked(row - 1, col + 1)) {
    return true;
  }
  // Up-Left pocket
  if (is_blocked(row - 1, col) && is_blocked(row, col - 1) &&
      !is_blocked(row - 1, col - 1)) {
    return true;
  }
  // Down-Right pocket
  if (is_blocked(row + 1, col) && is_blocked(row, col + 1) &&
      !is_blocked(row + 1, col + 1)) {
    return true;
  }
  // Down-Left pocket
  if (is_blocked(row + 1, col) && is_blocked(row, col - 1) &&
      !is_blocked(row + 1, col - 1)) {
    return true;
  }

  return false;
}

int solve(int row, int col, int pathIndex) {
  if (impossible_path(row, col)) {
    return 0;
  }

  if (pathIndex == 48) {
    return (row == 6 && col == 0);
  }

  // If we're @ destination and not 48 steps in, end early
  if (row == 6 && col == 0) {
    return 0;
  }

  visited[row][col] = true;

  int count = 0;
  char c = path[pathIndex];
  if (c == '?' || c == 'D') {
    count += solve(row + 1, col, pathIndex + 1);
  }
  if (c == '?' || c == 'U') {
    count += solve(row - 1, col, pathIndex + 1);
  }
  if (c == '?' || c == 'L') {
    count += solve(row, col - 1, pathIndex + 1);
  }
  if (c == '?' || c == 'R') {
    count += solve(row, col + 1, pathIndex + 1);
  }

  visited[row][col] = false; // backtrack
  return count;
}

int main() {
  setIO();

  cin >> path;
  cout << solve(0, 0, 0);
}
