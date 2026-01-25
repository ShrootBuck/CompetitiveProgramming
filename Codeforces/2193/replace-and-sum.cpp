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
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];

        vector<int> local_best(n);
        for (int i = 0; i < n; i++)
            local_best[i] = max(a[i], b[i]);

        vector<int> best = local_best;
        for (int i = n - 2; i >= 0; i--)
            best[i] = max(best[i], best[i + 1]);

        vector<int> prefix(n + 1, 0);
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + best[i];

        while (q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;

            cout << prefix[r + 1] - prefix[l];
            if (q != 0)
                cout << ' ';
        }

        cout << '\n';
    }
}
