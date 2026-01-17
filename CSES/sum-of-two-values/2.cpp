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

    vector<pair<ll, ll>> a;
    for (ll i = 0; i < n; i++) {
        ll ai;
        cin >> ai;

        a.emplace_back(ai, i + 1);
    }
    sort(a.begin(), a.end());

    ll l = 0, r = n - 1;
    while (l < r) {
        const ll sum = a[l].first + a[r].first;

        if (sum == x) {
            cout << a[l].second << " " << a[r].second;
            return 0;
        } else if (sum < x) {
            l++;
        } else {
            r--;
        }
    }

    cout << "IMPOSSIBLE";
}
