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

    vector<ll> b(m);
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    vector<vector<ll>> die_l(k + 1), die_r(k + 1);

    for (ll i = 0; i < n; i++) {
        auto it = lower_bound(b.begin(), b.end(), a[i]);

        if (it != b.end()) {
            const ll dist = *it - a[i];
            if (dist <= k) {
                die_r[dist].push_back(i);
            }
        }

        if (it != b.begin()) {
            const ll dist = a[i] - *prev(it);
            if (dist <= k) {
                die_l[dist].push_back(i);
            }
        }
    }

    string s;
    cin >> s;
    ll current = 0, max_r = 0, max_l = 0, alive = n;
    vector<bool> dead(n, false);

    for (const char c : s) {
        if (c == 'L')
            current--;
        else
            current++;

        if (current > max_r) {
            max_r = current;
            for (const ll i : die_r[max_r]) {
                if (!dead[i]) {
                    dead[i] = true;
                    alive--;
                }
            }
        } else if (current < -max_l) {
            max_l = -current;
            for (const ll i : die_l[max_l]) {
                if (!dead[i]) {
                    dead[i] = true;
                    alive--;
                }
            }
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
