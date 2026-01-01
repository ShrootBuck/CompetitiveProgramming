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

    int N;
    cin >> N;

    string s;
    cin >> s;

    int reversals = 0;

    for (int c = N - 2; c >= 0; c -= 2) {
        string sub = s.substr(c, 2);

        if (sub[0] == sub[1]) {
            // Reversal doesn't matter for maximization
            continue;
        }

        if ((sub == "GH" && reversals % 2 == 0) || (sub == "HG" && reversals % 2 == 1)) {
            reversals++;
        }
    }

    cout << reversals;
}
