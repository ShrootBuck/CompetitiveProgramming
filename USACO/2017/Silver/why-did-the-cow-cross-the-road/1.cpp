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
    setIO("helpcross");

    ll C, N;
    cin >> C >> N;

    multiset<ll> chickens;
    for (ll i = 0; i < C; i++) {
        ll t;
        cin >> t;
        chickens.insert(t);
    }

    vector<pair<ll, ll>> schedules(N);
    for (ll i = 0; i < N; i++)
        cin >> schedules[i].first >> schedules[i].second;
    sort(schedules.begin(), schedules.end(), [&](auto& a, auto& b) {
        if (a.second == b.second)
            return a.first < b.first;
        return a.second < b.second;
    });

    ll ans = 0;
    for (const auto& [first, second] : schedules) {
        if (auto it = chickens.lower_bound(first); it != chickens.end() && *it <= second) {
            ans++;
            chickens.erase(it);
        }
    }

    cout << ans;
}
