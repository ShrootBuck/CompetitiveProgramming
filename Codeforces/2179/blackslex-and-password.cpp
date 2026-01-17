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

    ll t;
    cin >> t;

    while (t--) {
        ll k, x;
        cin >> k >> x;
        cout << k * x + 1 << "\n";
    }
}
