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
    setIO("pails");

    ll X, Y, M;
    cin >> X >> Y >> M;

    ll max_fill = LLONG_MIN;
    for (ll x = 0; x <= M / X; x++) {
        for (ll y = 0; y <= M / Y; y++) {
            ll amount = x * X + y * Y;
            if (amount <= M) {
                max_fill = max(max_fill, amount);
            }
        }
    }

    cout << max_fill;
}
