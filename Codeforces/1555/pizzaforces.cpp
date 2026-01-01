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
    ll n;
    cin >> n;

    return max(6LL, n + 1) / 2 * 5;
}

int main() {
    setIO();

    ll t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
