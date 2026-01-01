#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO("mowing");

    ll N;
    cin >> N;

    ll x = 0, y = 0;
    ll ans = LLONG_MAX;
    bool overlapped = false;

    map<pair<ll, ll>, ll> coordinate_to_time;
    for (ll i = 0, t = 0; i < N; i++) {
        char dir;
        ll steps;
        cin >> dir >> steps;

        while (steps--) {
            switch (dir) {
            case 'N':
                y++;
                break;
            case 'E':
                x++;
                break;
            case 'S':
                y--;
                break;
            case 'W':
                x--;
                break;
            }

            if (coordinate_to_time.count({x, y})) {
                ans = min(ans, t - coordinate_to_time[{x, y}]);
                overlapped = true;
            }

            coordinate_to_time[{x, y}] = t;
            t++;
        }
    }

    if (overlapped) {
        cout << ans;
    } else {
        cout << -1;
    }
}
