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

int main() {
    setIO("mountains");

    ll N;
    cin >> N;
    vector<pair<ll, ll>> base_range(N);

    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        base_range[i] = {x - y, x + y};
    }
    sort(base_range.begin(), base_range.end(), [&](auto& m1, auto& m2) {
        if (m1.first == m2.first)
            return m1.second > m2.second;
        return m1.first < m2.first;
    });

    ll furthest = -1, ans = 0;
    for (auto& mountain : base_range) {
        if (mountain.second > furthest) {
            ans++;
            furthest = mountain.second;
        }
    }

    cout << ans;
}
