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
    setIO("");

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        set<int> beauty;

        for (int i = 0; i < n; i++) {
            int apple_beauty;
            cin >> apple_beauty;

            beauty.insert(apple_beauty);
        }

        cout << beauty.size() << "\n";
    }
}
