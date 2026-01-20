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
    setIO("pairup");

    ll N;
    cin >> N;

    map<ll, ll> y_to_x{};
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;
        y_to_x[y] += x;
    }

    ll time = 0;
    while (!y_to_x.empty()) {
        ll lower = y_to_x.begin()->first;
        ll upper = prev(y_to_x.end())->first;

        time = max(time, lower + upper);
        ll x = min(y_to_x[lower], y_to_x[upper]);
        y_to_x[lower] -= x, y_to_x[upper] -= x;
        if (y_to_x[lower] <= 0) {
            y_to_x.erase(lower);
        }
        if (lower != upper && y_to_x[upper] <= 0) {
            y_to_x.erase(upper);
        }
    }

    cout << time;
}
