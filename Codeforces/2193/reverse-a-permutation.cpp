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
        int n;
        cin >> n;
        vector<int> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i];

        int l = 0, next_expected = p[0];
        for (int i = 0, expected = n; i < n; i++, expected--) {
            if (p[i] != expected) {
                l = i;
                next_expected = expected;
                break;
            }
        }

        reverse(p.begin() + l, find(p.begin(), p.end(), next_expected) + 1);

        for (int i = 0; i < n; i++)
            cout << p[i] << ' ';
        cout << '\n';
    }
}
