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
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    bool type_0 = false, type_1 = false;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        type_0 = type_0 || b[i] == 0;
        type_1 = type_1 || b[i] == 1;
    }

    if (type_0 && type_1) {
        return true;
    }

    for (int i = 1; i < n; i++) {
        if (a[i] < a[i - 1]) {
            return false;
        }
    }

    return true;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << (solve() ? "Yes" : "No") << "\n";
    }
}
