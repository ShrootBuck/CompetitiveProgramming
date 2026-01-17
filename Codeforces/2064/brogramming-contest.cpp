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

void solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    bool all_zero = true;
    bool all_one = true;

    for (char& c : s) {
        if (c == '0') {
            all_one = false;
        } else {
            all_zero = false;
        }
    }

    if (all_zero) {
        cout << 0;
        return;
    }

    if (all_one) {
        cout << 1;
        return;
    }

    char last = '0';

    int groups = 0;

    for (auto& c : s) {
        if (c != last) {
            groups++;
        }

        last = c;
    }

    cout << groups;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
