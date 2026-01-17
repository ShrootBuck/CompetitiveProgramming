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

int main() {
    setIO();

    ll n, q;
    cin >> n >> q;

    vector<vector<bool>> forest(n, vector<bool>(n));
    for (ll r = 0; r < n; r++) {
        string s;
        cin >> s;
        for (ll c = 0; c < n; c++) { // C++
            forest[r][c] = s[c] == '*';
        }
    }

    vector<vector<ll>> prefix(n + 1, vector<ll>(n + 1, 0));
    for (ll r = 1; r <= n; r++) {
        for (ll c = 1; c <= n; c++) {
            prefix[r][c] =
                forest[r - 1][c - 1] + prefix[r - 1][c] + prefix[r][c - 1] - prefix[r - 1][c - 1];
        }
    }

    for (ll query = 0; query < q; query++) {
        ll y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << prefix[y2][x2] - prefix[y1 - 1][x2] - prefix[y2][x1 - 1] + prefix[y1 - 1][x1 - 1]
             << "\n";
    }
}
