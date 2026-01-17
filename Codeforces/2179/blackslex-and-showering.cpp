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
    setIO();

    ll t;
    cin >> t;

    while (t--) {
        ll n;
        cin >> n;

        ll ans = LLONG_MAX;
        ll sum = 0;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];

        for (ll i = 0; i < n - 1; i++)
            sum += abs(a[i + 1] - a[i]);

        for (ll i = 0; i < n; i++) {
            ll impact = sum;
            if (i < n - 1) {
                impact -= abs(a[i] - a[i + 1]);
            }
            if (i > 0) {
                impact -= abs(a[i - 1] - a[i]);
            }

            if (i > 0 && i < n - 1) {
                impact += abs(a[i + 1] - a[i - 1]);
            }

            ans = min(ans, impact);
        }

        cout << ans << "\n";
    }
}
