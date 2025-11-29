#include <cstdio>
#include <iostream>
#include <string>
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
    int n, k;
    cin >> n >> k;

    // 8 7

    int n_even = n - (k - 1) * 2;
    int n_odd = n - (k - 1);

    if (n_even % 2 == 0 && n_even > 0) {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++) {
            cout << "2 ";
        }

        cout << n_even << "\n";
        return;
    }

    if (n_odd % 2 != 0 && n_odd > 0) {
        cout << "YES\n";
        for (int i = 0; i < k - 1; i++) {
            cout << "1 ";
        }
        cout << n_odd << "\n";
        return;
    }
    cout << "NO\n";
    return;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        solve();
    }
}
