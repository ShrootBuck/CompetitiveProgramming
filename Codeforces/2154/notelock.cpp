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
    int n, k;
    cin >> n >> k;

    string s;
    cin >> s;

    int protection_remaining = -1;
    int need_protection = 0;

    for (int i = 0; i < n; i++) {
        auto& c = s[i];

        if (c == '1') {
            if (protection_remaining <= 0) {
                need_protection++;
            }

            protection_remaining = k;
        }

        protection_remaining--;
    }

    cout << need_protection;
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
