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

    ll n, m;
    cin >> n >> m;

    vector<ll> h(n), t(m);
    for (int i = 0; i < n; i++)
        cin >> h[i];
    for (int i = 0; i < m; i++)
        cin >> t[i];

    multiset<ll> h_multiset(h.begin(), h.end());

    for (int t_i = 0; t_i < m; t_i++) {
        auto v = h_multiset.upper_bound(t[t_i]);

        if (v == h_multiset.begin()) {
            cout << "-1\n";
        } else {
            v--;
            cout << *v << "\n";
            h_multiset.erase(v);
        }
    }
}
