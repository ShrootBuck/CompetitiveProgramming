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
    int S;
    cin >> S;

    string s;
    cin >> s;

    if (s[0] != 'M' || s[1] != 'I' || s[2] != 'T') {
        return false;
    }

    int mit_index = -1;
    int it_index = -1;

    int l = 3;
    while (l < S) {
        if (s[l] == 'M' && l + 2 < S) {
            if (s[l + 1] == 'I' && s[l + 2] == 'T') {
                l += 3;
            } else {
                return false;
            }
        } else if (s[l] == 'I' && l + 1 < S) {
            if (s[l + 1] == 'T') {
                l += 2;
            } else {
                return false;
            }
        } else {
            return false;
        }
    }

    return true;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "YES" : "NO");
        cout << "\n";
    }
}
