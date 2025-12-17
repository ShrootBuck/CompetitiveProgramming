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

int main() {
    setIO();

    int N;
    cin >> N;

    vector<vector<int>> a(N, vector<int>(N));
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> a[r][c];
        }
    }

    ll horizontal = 0, vertical = 0;

    // Try horizontal alternatings
    for (int r = 0; r < N; r++) {
        vector<int> sums(2, 0);

        for (int c = 0; c < N; c++) { // C++!
            sums[c % 2] += a[r][c];   // Much nicer than two loops
        }

        horizontal += max(sums[0], sums[1]);
    }

    // Try vertical alternatings
    for (int c = 0; c < N; c++) {
        vector<int> sums(2, 0);

        for (int r = 0; r < N; r++) {
            sums[r % 2] += a[r][c];
        }

        vertical += max(sums[0], sums[1]);
    }

    cout << max(horizontal, vertical);
}
