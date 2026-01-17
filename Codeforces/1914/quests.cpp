#include <bits/stdc++.h>
using namespace std;

#define ll long long

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

ll solve() {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    int best_b = 0;
    ll xp = 0; // Previously collected in row A
    ll ans = 0;

    for (int i = 0; i < min(n, k); i++) {
        int k_left = k - (i + 1);
        best_b = max(best_b, b[i]);
        xp += a[i];

        ans = max(ans, xp + (best_b * k_left));
    }

    return ans;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
