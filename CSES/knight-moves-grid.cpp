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

    int n;
    cin >> n;

    vector<pair<int, int>> dirs{{2, 1},  {2, -1},  {1, 2},  {-1, 2},
                                {-2, 1}, {-2, -1}, {1, -2}, {-1, -2}};

    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    dist[0][0] = 0;

    queue<pair<int, int>> q;
    q.push({0, 0});

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (auto dir : dirs) {
            int nr = r + dir.first, nc = c + dir.second;

            if (0 <= min(nr, nc) && max(nr, nc) < n && dist[nr][nc] == INT_MAX) {
                dist[nr][nc] = dist[r][c] + 1;
                q.push({nr, nc});
            }
        }
    }

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            cout << dist[r][c] << " ";
        }
        cout << "\n";
    }
}
