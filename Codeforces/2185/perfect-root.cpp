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
    ll n;
    cin >> n;

    for (ll y = 1; y <= n; y++) {
        cout << y << " ";
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
