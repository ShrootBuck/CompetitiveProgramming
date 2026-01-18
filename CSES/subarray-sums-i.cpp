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
    setIO();

    ll n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll r = 0, l = 0, sum = a[0], ans = 0;
    for (; r < n && l < n;) {
        if (sum == x) {
            sum -= a[l];
            ans++, l++, r++;
            sum += a[r];
        } else if (sum < x) {
            r++;
            sum += a[r];
        } else {
            sum -= a[l];
            l++;
        }
    }

    cout << ans;
}
