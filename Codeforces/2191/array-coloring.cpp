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

bool solve() {
    ll n;
    cin >> n;

    vector<pair<ll, bool>> a(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i].first;

    // Try R...
    for (ll i = 0; i < n; i++) {
        a[i].second = i % 2 == 0;
    }
    auto temp = a;
    sort(temp.begin(), temp.end());
    for (ll i = 1; i < n; i++) {
        if (temp[i].second == temp[i - 1].second)
            return false;
    }

    // Try B...
    for (ll i = 0; i < n; i++) {
        a[i].second = i % 2 != 0;
    }
    temp = a;
    sort(temp.begin(), temp.end());
    for (ll i = 1; i < n; i++) {
        if (temp[i].second == temp[i - 1].second)
            return false;
    }

    return true;
}

int main() {
    setIO();

    ll t;
    cin >> t;

    while (t--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}
