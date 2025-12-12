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

string s;
int q;

vector<vector<int>> prefix;

bool solve(int l, int r) {
    auto alphabet = prefix[r + 1];
    multiset<int> unique;
    for (int j = 0; j < 26; j++) {
        alphabet[j] -= prefix[l][j];
        if (alphabet[j] != 0) {
            unique.insert(alphabet[j]);
        }
    }

    if (unique.size() == 1) {
        return r == l;
    } else if (unique.size() >= 3) {
        return true;
    } else {
        return s[r] != s[l];
    }
}

int main() {
    setIO();

    cin >> s >> q;

    prefix = vector<vector<int>>(s.size() + 1, vector<int>(26, 0));
    for (int i = 1; i < s.size() + 1; i++) {
        prefix[i] = prefix[i - 1];
        prefix[i][s[i - 1] - 'a']++;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;

        cout << (solve(l, r) ? "Yes" : "No") << "\n";
    }
}
