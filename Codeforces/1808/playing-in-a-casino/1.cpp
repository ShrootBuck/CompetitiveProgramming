#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> cards(n, vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> cards[i][j];
        }
    }

    long long total_winnings = 0;

    // Iterate through each column
    for (int j = 0; j < m; ++j) {
        vector<int> column;
        for (int i = 0; i < n; ++i) {
            column.push_back(cards[i][j]);
        }

        sort(column.begin(), column.end());

        // Calculate the sum of pairwise differences for this sorted column using
        // that strange formula I got
        for (int i = 0; i < n; ++i) {
            total_winnings += (long long)column[i] * (2LL * i - n + 1);
        }
    }

    cout << total_winnings << "\n";
}

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

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
