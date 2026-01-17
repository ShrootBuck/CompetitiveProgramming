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

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> prefix(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (i == 0) {
            prefix[i] = a[i];
        } else {
            prefix[i] = max(prefix[i - 1], a[i]);
        }
    }

    int total = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            if (i < n - 1 && a[i] >= prefix[i + 1]) {
                int diff = a[i] - prefix[i + 1] + 1;
                a[i] -= diff;
                total += diff;
            }

            if (i > 0 && a[i] >= prefix[i - 1]) {
                int diff = a[i] - prefix[i - 1] + 1;
                a[i] -= diff;
                total += diff;
            }
        }
    }

    cout << total;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
