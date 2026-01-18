#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

int new_grid[1000][1000];
int main() {
    setIO("lazy");

    int N, K;
    cin >> N >> K;

    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) { // C++
            int grass;
            cin >> grass;

            new_grid[r - c + N][r + c] = grass;
        }
    }

    for (int r = 1; r <= 2 * N; r++) {
        for (int c = 1; c <= 2 * N; c++) {
            new_grid[r][c] += new_grid[r - 1][c] + new_grid[r][c - 1] - new_grid[r - 1][c - 1];
        }
    }

    int max_grass = 0;
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) {
            int center_row = r - c + N;
            int center_col = r + c;

            int r1 = max(1, center_row - K);
            int c1 = max(1, center_col - K);
            int r2 = min(2 * (int)N, center_row + K);
            int c2 = min(2 * (int)N, center_col + K);

            max_grass = max(max_grass, new_grid[r2][c2] - new_grid[r1 - 1][c2] -
                                           new_grid[r2][c1 - 1] + new_grid[r1 - 1][c1 - 1]);
        }
    }

    cout << max_grass;
}
