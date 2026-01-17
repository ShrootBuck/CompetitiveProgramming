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

int solve() {
    int n, y, r;
    cin >> n >> y >> r;

    return min(n, y / 2 + r);
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
