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
    setIO("mixmilk");

    vector<ll> c(3), m(3);
    cin >> c[0] >> m[0] >> c[1] >> m[1] >> c[2] >> m[2];

    for (ll i = 0; i < 100; i++) {
        ll from = i % 3;
        ll to = (i + 1) % 3;

        ll amount = min(m[from], c[to] - m[to]);
        m[from] -= amount;
        m[to] += amount;
    }

    for (ll milk : m) {
        cout << milk << "\n";
    }
}
