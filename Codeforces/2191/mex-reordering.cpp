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

    ll zeros = 0, ones = 0;
    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;

        if (num == 0) {
            zeros++;
        } else if (num == 1) {
            ones++;
        }
    }

    if (zeros == 0) {
        return false;
    } else if (zeros > 1 && ones == 0) {
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
