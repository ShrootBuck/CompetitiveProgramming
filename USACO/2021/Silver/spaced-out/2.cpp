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
    setIO();

    int N;
    cin >> N;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) { // C++
            cin >> grid[r][c];
        }
    }

    ll horizontal_max = 0, vertical_max = 0;
    for (int r = 0; r < N; r++) {
        ll p1 = 0, p2 = 0;
        for (int c = 0; c < N; c += 2) {
            p1 += grid[r][c];
        }
        for (int c = 1; c < N; c += 2) {
            p2 += grid[r][c];
        }

        horizontal_max += max(p1, p2);
    }

    for (int c = 0; c < N; c++) {
        ll p1 = 0, p2 = 0;
        for (int r = 0; r < N; r += 2) {
            p1 += grid[r][c];
        }
        for (int r = 1; r < N; r += 2) {
            p2 += grid[r][c];
        }

        vertical_max += max(p1, p2);
    }

    cout << max(horizontal_max, vertical_max);
}
