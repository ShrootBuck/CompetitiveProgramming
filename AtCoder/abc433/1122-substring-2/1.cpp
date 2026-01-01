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
    setIO();

    string S;
    cin >> S;

    int last = -2;
    set<int> borders;
    for (int i = 0; i < S.size(); i++) {
        int current = S[i] - '0';
        if (current - last == 1) {
            borders.insert(i);
        }
        last = current;
    }

    // Now expand the borders
    ll subs = 0;

    for (const int& border : borders) {
        int i = border - 1, j = border;

        while (i >= 0 && j < S.size()) {
            if ((S[j] - '0') - (S[i] - '0') != 1) {
                break;
            }

            if (i != border - 1) { // Meaning we've moved at least once
                if (S[i] != S[i + 1] || S[j] != S[j - 1]) {
                    break;
                }
            }

            subs++;
            i--, j++;
        }
    }

    cout << subs;
}
