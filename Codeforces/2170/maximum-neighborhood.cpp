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

int solve() {
    int n;
    cin >> n;

    vector<vector<int>> grid(n, vector<int>(n));

    // this is inefficient as hell but ill upsolve later
    int last = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = ++last;
        }
    }

    int max_cost = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int local_cost = grid[r][c];

            if (r > 0) {
                local_cost += grid[r - 1][c];
            }
            if (r < n - 1) {
                local_cost += grid[r + 1][c];
            }
            if (c > 0) {
                local_cost += grid[r][c - 1];
            }
            if (c < n - 1) {
                local_cost += grid[r][c + 1];
            }

            max_cost = max(max_cost, local_cost);
        }
    }

    return max_cost;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
