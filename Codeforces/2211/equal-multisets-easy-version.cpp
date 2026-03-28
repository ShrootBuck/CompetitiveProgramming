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
        int n, k;
        cin >> n >> k;
        vector<int> a(n + 1), b(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++)
            cin >> b[i];

        int L = n - k + 1, R = k;
        bool ok = true;

        // check non-free positions
        for (int i = 1; i <= n && ok; i++) {
            if (i < L || i > R) {
                if (b[i] != -1 && b[i] != a[i])
                    ok = false;
            }
        }

        // check free positions
        if (ok && L <= R) {
            vector<bool> in_s(n + 1, false), used(n + 1, false);

            for (int i = L; i <= R; i++)
                in_s[a[i]] = true;
            for (int i = L; i <= R && ok; i++) {
                if (b[i] != -1) {
                    if (!in_s[b[i]] || used[b[i]])
                        ok = false;
                    else
                        used[b[i]] = true;
                }
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }
}
