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

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        sort(a.begin(), a.end());

        if (n % 2 == 0) {
            for (ll i = 0; i < n / 2; i++) {
                cout << a[n / 2 + i] << " " << a[n / 2 - 1 - i] << " ";
            }
        } else {
            cout << a[n / 2] << " ";
            for (ll i = 1; i <= n / 2; i++) {
                cout << a[n / 2 + i] << " " << a[n / 2 - i] << " ";
            }
        }

        cout << "\n";
    }
}
