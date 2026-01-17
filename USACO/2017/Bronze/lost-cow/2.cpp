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

// For that easy return statement
ll solve() {
    ll x, y;
    cin >> x >> y;

    ll hitdir = (y > x) ? 1 : -1;
    ll dir = 1, dist = 0, pos = x;

    // yummy spaghetti code
    for (ll depth = 0;; dir *= -1, depth++) {
        ll newpos = x + dir * pow(2, depth);
        dist += abs(newpos - pos);

        if ((newpos <= y && hitdir == -1) || (newpos >= y && hitdir == 1)) {
            dist -= abs(newpos - y);
            return dist;
        }

        pos = newpos;
    }
}

int main() {
    setIO("lostcow");

    cout << solve();
}
