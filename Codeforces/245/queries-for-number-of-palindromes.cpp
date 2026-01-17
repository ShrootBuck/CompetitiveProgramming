#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

int is_palindrome[5001][5001];
int dp[5001][5001];

int main() {
    setIO();

    string s;
    cin >> s;

    ll q;
    cin >> q;

    for (ll i = 0; i < s.size(); i++) {
        is_palindrome[i][i] = dp[i][i] = 1;
    }

    for (ll len = 2; len <= s.size(); len++) {
        for (ll i = 0; i <= s.size() - len; i++) {
            ll j = i + len - 1;

            if (len == 2) {
                is_palindrome[i][j] = s[i] == s[j];
            } else {
                is_palindrome[i][j] = s[i] == s[j] && is_palindrome[i + 1][j - 1];
            }

            dp[i][j] = dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] + is_palindrome[i][j];
        }
    }

    for (ll i = 0; i < q; i++) {
        ll l, r;
        cin >> l >> r;
        l--, r--;

        cout << dp[l][r] << "\n";
    }
}
