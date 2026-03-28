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
        int x, y;
        cin >> x >> y;

        int S = abs(x - y);
        int min_fa = 0;

        if (S == 0) {
            // x==y
            min_fa = 1;
        } else {
            for (int i = 1; i * i <= S; i++) {
                if (S % i == 0) {
                    min_fa++;
                    if (i * i != S)
                        min_fa++;
                }
            }
        }
        cout << min_fa << '\n';

        for (int i = 0; i < x; i++)
            cout << "1 ";
        for (int i = 0; i < y; i++)
            cout << "-1 ";
        cout << '\n';
    }
}
