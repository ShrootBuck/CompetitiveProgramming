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
    int n, a, b;
    cin >> n >> a >> b;

    int draws = n - a - b;
    if (draws < 0) {
        cout << "NO";
        return;
    }

    n -= draws;
    if (n < 0) {
        cout << "NO";
        return;
    }

    if (n != 0 && (a == n || b == n)) {
        cout << "NO";
        return;
    }

    cout << "YES\n";

    // Player A just throws it all out
    for (int i = 1; i <= n + draws; i++) {
        cout << i << " ";
    }

    cout << "\n";

    // Player B
    for (int i = 1; i <= n; i++) {
        int x = i + a;
        if (x > n) {
            x -= n;
        }
        cout << x << " ";
    }

    // Player B's draw cards
    for (int i = n + 1; i <= n + draws; i++) {
        cout << i << " ";
    }
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
