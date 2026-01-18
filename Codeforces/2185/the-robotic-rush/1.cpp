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
    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    set<ll> b;
    for (ll i = 0; i < m; i++) {
        ll x;
        cin >> x;
        b.insert(x);
    }

    string s;
    cin >> s;
    for (char& c : s) {
        ll alive = 0;
        for (ll i = 0; i < a.size(); i++) {
            if (a[i] == LLONG_MIN)
                continue;

            if (c == 'L')
                a[i]--;
            else
                a[i]++;

            if (b.count(a[i])) {
                a[i] = LLONG_MIN;
            }
            if (a[i] != LLONG_MIN)
                alive++;
        }

        cout << alive << " ";
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
