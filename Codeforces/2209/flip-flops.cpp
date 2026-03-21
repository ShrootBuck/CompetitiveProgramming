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

ll solve() {
    ll n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    for (int ai : a) {
        if (ai > c)
            return c;

        int diff = min(k, abs(c - ai));
        k -= diff;
        ai += diff;
        c += ai;
    }

    return c;
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
}
