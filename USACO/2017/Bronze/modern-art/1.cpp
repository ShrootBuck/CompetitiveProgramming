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
    setIO("art");

    int N;
    cin >> N;

    set<int> visible;

    vector<vector<int>> grid(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < N; j++) {
            grid[i][j] = s[j] - '0';
            visible.insert(grid[i][j]);
        }
    }

    // True if c1 covers c2
    auto covers = [&](int c1, int c2) {
        // Find c2's bounding box
        int top = N, bottom = 0, left = N, right = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == c2) {
                    top = min(top, i);
                    bottom = max(bottom, i);
                    left = min(left, j);
                    right = max(right, j);
                }
            }
        }

        for (int i = top; i <= bottom; i++) {
            for (int j = left; j <= right; j++) {
                if (grid[i][j] == c1) {
                    return true;
                }
            }
        }

        return false;
    };

    int ans = 0;

    for (int i = 1; i <= 9; i++) {
        if (visible.count(i)) {
            bool valid = true;

            for (int j = 1; j <= 9; j++) {
                if (i != j && visible.count(j) && covers(i, j)) {
                    valid = false;
                }
            }

            ans += valid;
        }
    }

    cout << ans;
}
