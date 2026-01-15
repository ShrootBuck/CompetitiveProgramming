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

    ll n, t;
    cin >> n >> t;

    vector<ll> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];

    ll global_ans = 0;
    ll sum = 0;
    for (ll l = 0, r = 0; r < n; r++) {
        sum += a[r];

        while (sum > t) {
            sum -= a[l];
            l++;
        }

        global_ans = max(global_ans, r - l + 1);
    }

    cout << global_ans;
}
