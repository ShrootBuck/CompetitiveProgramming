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

bool solve() {
    int n, s, x;
    cin >> n >> s >> x;

    int sum = 0;
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        sum += val;
    }

    if (sum > s)
        return false;
    return (s - sum) % x == 0;
}

int main() {
    setIO();
    int t;
    cin >> t;
    while (t--) {
        cout << (solve() ? "YES" : "NO") << '\n';
    }
}
