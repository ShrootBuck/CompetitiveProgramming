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
    int m;
    cin >> m;

    vector<vector<int>> grid(2, vector<int>(m));

    for (int i = 0; i <= 1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }

    // Can probably do without both but this seems easier
    vector<vector<int>> postfix = grid;
    vector<vector<int>> prefix = grid;

    for (int i = 0; i < 2; i++) {
        for (int j = m - 2; j >= 0; j--) {
            postfix[i][j] += postfix[i][j + 1];
        }
        for (int j = 1; j < m; j++) {
            prefix[i][j] += prefix[i][j - 1];
        }
    }

    int ans = INT_MAX;

    for (int i = 0; i < m; i++) {
        ans = min(ans, max(prefix[1][i] - grid[1][i], postfix[0][i] - grid[0][i]));
    }

    return ans;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
