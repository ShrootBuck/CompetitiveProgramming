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

    int N, Q;
    cin >> N >> Q;

    // after 32 bits it doesnt even matter because of size
    vector<ll> a(32);

    for (int i = 0; i < N; i++) {
        if (i < 32)
            cin >> a[i];
        else {
            ll nope;
            cin >> nope;
        }
    }

    // Buying a fake 2^i bucket is just buying two 2^(i-1) buckets
    for (int i = N; i < 32; i++)
        a[i] = a[i - 1] * 2;

    // Make sure FJ isn't pulling a Sam Bankman-Fried on us
    for (int i = 1; i < 32; i++)
        a[i] = min(a[i], 2 * a[i - 1]);

    while (Q--) {
        ll x;
        cin >> x;

        ll ans = 0, best_over = LLONG_MAX;

        for (int i = 31; i >= 0; i--) {
            ll cap = 1LL << i;
            ll take = x / cap;

            ans += take * a[i], x %= cap;
            best_over = min(best_over, ans + a[i]);
        }

        cout << min(ans, best_over) << '\n';
    }
}
