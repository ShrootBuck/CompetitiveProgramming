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
    int n;
    cin >> n;
    vector<int> a(n), ans(n, 0);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++) {
        int greater = 0, lesser = 0;

        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i])
                greater++;
            if (a[j] < a[i])
                lesser++;
        }

        cout << max(greater, lesser) << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--)
        solve();
}
