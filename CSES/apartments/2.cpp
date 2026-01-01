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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    vector<ll> b(m);
    for (ll i = 0; i < m; i++)
        cin >> b[i];
    sort(b.begin(), b.end());

    ll a_i = 0, b_i = 0, ans = 0;
    while (a_i < n && b_i < m) {
        if (abs(a[a_i] - b[b_i]) <= k) {
            ans++;
            a_i++;
            b_i++;
        } else if (b[b_i] > a[a_i]) {
            a_i++;
        } else {
            b_i++;
        }
    }

    cout << ans;
}
