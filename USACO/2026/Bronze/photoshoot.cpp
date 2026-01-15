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

ll grid[501][501];
ll square_sums[501][501];

int main() {
    setIO();

    ll N, K, Q;
    cin >> N >> K >> Q;

    ll global_max = 0;

    for (int q = 0; q < Q; q++) {
        ll r, c, v;
        cin >> r >> c >> v;

        ll delta = v - grid[r][c];
        grid[r][c] += delta;

        ll start_r = max(1LL, r - K + 1);
        ll end_r = min(N - K + 1, r);

        ll start_c = max(1LL, c - K + 1);
        ll end_c = min(N - K + 1, c);

        for (ll i = start_r; i <= end_r; i++) {
            for (ll j = start_c; j <= end_c; j++) {
                square_sums[i][j] += delta;
                global_max = max(global_max, square_sums[i][j]);
            }
        }

        cout << global_max << "\n";
    }
}
