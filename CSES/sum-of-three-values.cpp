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

    int n, x;
    cin >> n >> x;

    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i + 1;
    }
    sort(a.begin(), a.end());

    for (int a1 = 0; a1 < n - 2; a1++) {
        const ll target = x - a[a1].first;
        int a2 = a1 + 1, a3 = n - 1;
        while (a2 < a3) {
            ll sum = (ll)a[a2].first + a[a3].first;
            if (sum > target) {
                a3--;
            } else if (sum < target) {
                a2++;
            } else {
                cout << a[a1].second << " " << a[a2].second << " " << a[a3].second;
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE";
}
