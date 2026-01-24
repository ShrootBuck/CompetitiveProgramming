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

    int n, q;
    string s;
    cin >> n >> s >> q;

    map<char, map<int, int>> cache;

    // Precompute
    for (char c = 'a'; c <= 'z'; c++) {
        for (int m = 1; m <= n; m++) {
            int l = 0, count = 0, best = 0;
            for (int r = 0; r < n; r++) {
                count += s[r] != c;

                while (count > m) {
                    count -= (s[l] != c);
                    l++;
                }

                best = max(best, r - l + 1);
            }
            cache[c][m] = best;
        }
    }

    while (q--) {
        int m;
        char c;
        cin >> m >> c;
        cout << cache[c][m] << '\n';
    }
}
