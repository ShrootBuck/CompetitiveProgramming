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

int solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a)
        cin >> x;

    int ops = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1] || a[i] + a[i + 1] == 7)
            ops++, i++; // We fixed a[i+1] to match a[i] AND a[i+2], so skip the next check
    }

    return ops;
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--)
        cout << solve() << '\n';
}
