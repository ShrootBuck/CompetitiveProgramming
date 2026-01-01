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
    int N;
    cin >> N;

    if (N % 2 == 0) {
        cout << "2025";

        for (int i = 0; i < N - 4; i++) {
            cout << "0";
        }
    } else {
        cout << "42025";

        for (int i = 0; i < N - 5; i++) {
            cout << "0";
        }
    }
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        solve();
        cout << "\n";
    }
}
