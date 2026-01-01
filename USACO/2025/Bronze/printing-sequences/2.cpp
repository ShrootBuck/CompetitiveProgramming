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

bool solve() {
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<vector<int>> dp(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        dp[i][i] = 1;
    }

    for (int len = 2; len <= N; len++) {
        for (int i = 0; i <= N - len; i++) {
            int j = i + len - 1;
            dp[i][j] = N + 1;

            // "Two separate print statements" check
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
            }

            // Repetition check
            for (int d = 1; d < len; d++) {
                if (len % d == 0) {
                    bool match = true;

                    for (int k = i + d; k <= j; k++) {
                        if (a[k] != a[k - d]) {
                            match = false;
                            break;
                        }
                    }

                    if (match) {
                        dp[i][j] = min(dp[i][j], dp[i][i + d - 1]);
                    }
                }
            }
        }
    }

    return dp[0][N - 1] <= K;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "YES" : "NO") << "\n";
    }
}
