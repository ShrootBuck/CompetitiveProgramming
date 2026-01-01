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

int R, C;
vector<vector<char>> grid;

int solve(int r, int c) {
    if (r == R - 1 && c == C - 1) {
        return 1;
    }

    int ans = 0;
    for (int i = r + 1; i < R; i++) {
        for (int j = c + 1; j < C; j++) {
            if (grid[r][c] != grid[i][j]) {
                ans += solve(i, j);
            }
        }
    }

    return ans;
}

int main() {
    setIO("hopscotch");

    cin >> R >> C;

    grid.resize(R);
    for (int r = 0; r < R; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < C; c++) {
            grid[r].push_back(s[c]);
        }
    }

    cout << solve(0, 0);
}
