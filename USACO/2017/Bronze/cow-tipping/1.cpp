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
    setIO("cowtip");

    int N;
    cin >> N;

    vector<vector<bool>> cows(N, vector<bool>(N));

    auto flip_until = [&](int r, int c) {
        for (int i = 0; i <= r; i++) {
            for (int j = 0; j <= c; j++) {
                cows[i][j] = !cows[i][j];
            }
        }
    };

    auto rightmost_tipped = [&]() {
        pair<int, int> rightmost{-1, -1};

        for (int i = N - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                if (cows[i][j]) {
                    rightmost = {i, j};
                    return rightmost;
                }
            }
        }

        return rightmost;
    };

    for (int r = 0; r < N; r++) {
        string s;
        cin >> s;

        for (int c = 0; c < N; c++) {

            cows[r][c] = (s[c] == '1');
        }
    }

    int count = 0;

    while (true) {
        auto rightmost = rightmost_tipped();

        if (rightmost.first == -1 || rightmost.second == -1) {
            break;
        }

        flip_until(rightmost.first, rightmost.second);
        count++;
    }

    cout << count;
}
