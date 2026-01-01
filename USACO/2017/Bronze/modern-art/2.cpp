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

int main() {
    setIO("art");

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    set<int> visible;
    vector<int> min_r(10, N), max_r(10, 0), min_c(10, N), max_c(10, 0);
    for (int r = 0; r < N; r++) {
        string s;
        cin >> s;
        for (int c = 0; c < N; c++) {
            int n = s[c] - '0';
            grid[r][c] = n;
            visible.insert(n);

            min_r[n] = min(min_r[n], r);
            min_c[n] = min(min_c[n], c);
            max_r[n] = max(max_r[n], r);
            max_c[n] = max(max_c[n], c);
        }
    }

    visible.erase(0);
    auto candidates = visible;

    for (auto& color : visible) {
        for (int r = min_r[color]; r <= max_r[color]; r++) {
            for (int c = min_c[color]; c <= max_c[color]; c++) {
                if (grid[r][c] != color) {
                    candidates.erase(grid[r][c]);
                }
            }
        }
    }

    cout << candidates.size();
}
