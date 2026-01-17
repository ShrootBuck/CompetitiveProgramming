#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("censor");

    string S, T;
    cin >> S >> T;

    string res;

    for (int i = 0; i < S.length(); i++) {
        res += S[i];
        if (res.length() < T.length()) {
            continue;
        }

        if (res.substr(res.length() - T.length(), T.length()) == T) {
            res.erase(res.length() - T.length(), T.length());
        }
    }

    cout << res;
}
