#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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
    int n;
    cin >> n;

    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<ll> prefix_b = b, suffix_b = b;
    prefix_b[0] = b[0];
    suffix_b[n - 1] = b[n - 1] - (n - 1);
    for (int i = 1; i < n; i++) {
        prefix_b[i] = max(prefix_b[i - 1], b[i] + i);
    }
    for (int i = n - 2; i >= 0; i--) {
        suffix_b[i] = max(suffix_b[i + 1], b[i] - i);
    }

    ll ans = 0;

    for (int i = 1; i < n - 1; i++) {
        ans = max(ans, prefix_b[i - 1] + b[i] + suffix_b[i + 1]);
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
