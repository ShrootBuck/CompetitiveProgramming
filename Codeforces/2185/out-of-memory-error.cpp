// What if instead of OOM it was MOO because Bessie is a cow
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

void solve() {
    ll n, m, h;
    cin >> n >> m >> h;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    vector<ll> a_mutable = a;

    vector<bool> needs_reset(n, true);
    for (ll i = 0; i < m; i++) {
        ll b, c;
        cin >> b >> c;
        b--;

        if (needs_reset[b]) {
            needs_reset[b] = false;
            a_mutable[b] = a[b] + c;
        } else {
            a_mutable[b] += c;
        }

        if (a_mutable[b] > h) {
            fill(needs_reset.begin(), needs_reset.end(), true);
        }
    }

    for (ll i = 0; i < n; i++) {
        if (needs_reset[i])
            cout << a[i];
        else
            cout << a_mutable[i];
        cout << ' ';
    }
}

int main() {
    setIO();

    ll t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}
