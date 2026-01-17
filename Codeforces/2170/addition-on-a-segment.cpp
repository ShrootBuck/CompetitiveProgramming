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
    int n;
    cin >> n;

    vector<int> b(n);
    ll S = 0, nonzeros = 0;
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        S += b[i];
        nonzeros += b[i] != 0;
    }

    ll max_budget = S - (n - 1);
    return min(max_budget, nonzeros);
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
