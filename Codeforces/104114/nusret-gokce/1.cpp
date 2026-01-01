#include <bits/stdc++.h>

using namespace std;

#define ll long long

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO();

    ll n, m;
    cin >> n >> m;

    vector<ll> s(n);
    for (ll i = 0; i < n; i++)
        cin >> s[i];

    bool changed_iter = true;
    while (changed_iter) {
        changed_iter = false;
        for (ll i = 0; i < n; i++) {
            if (i > 0) {
                if (s[i - 1] > s[i] + m) {
                    s[i] = s[i - 1] - m;
                    changed_iter = true;
                }
            }

            if (i < n - 1) {
                if (s[i + 1] > s[i] + m) {
                    s[i] = s[i + 1] - m;
                    changed_iter = true;
                }
            }
        }
    }

    for (ll i = 0; i < n; i++)
        cout << s[i] << " ";
}
