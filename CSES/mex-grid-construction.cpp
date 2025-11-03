#include <cstdio>
#include <iostream>
#include <set>
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

    int n;
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(n));

    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            set<int> prev;

            for (int i = 0; i < r; i++) {
                prev.insert(arr[i][c]);
            }
            for (int i = 0; i < c; i++) {
                prev.insert(arr[r][i]);
            }

            int v = 0;
            while (prev.count(v) != 0) {
                v++;
            }

            arr[r][c] = v;
            cout << v << " ";
        }
        cout << "\n";
    }
}
