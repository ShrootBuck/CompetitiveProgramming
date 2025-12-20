#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
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

    for (ll i = 0; i < n - 1; i++) {
        s[i + 1] = max(s[i + 1], s[i] - m);
    }

    for (ll i = n - 1; i > 0; i--) {
        s[i - 1] = max(s[i - 1], s[i] - m);
    }

    for (ll i = 0; i < n; i++)
        cout << s[i] << " ";
}
