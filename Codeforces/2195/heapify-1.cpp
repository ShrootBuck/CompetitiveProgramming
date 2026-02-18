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

int remove_twos(int x) {
    while (x % 2 == 0)
        x /= 2;
    return x;
}

bool solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    bool possible = true;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];

        if (remove_twos(a[i]) != remove_twos(i))
            possible = false;
    }

    return possible;
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--)
        cout << (solve() ? "YES" : "NO") << '\n';
}
