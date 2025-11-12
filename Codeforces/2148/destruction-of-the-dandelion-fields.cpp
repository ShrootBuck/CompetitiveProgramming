#include <algorithm>
#include <cstdio>
#include <iostream>
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

void solve() {
    int n;
    cin >> n;

    ll count = 0;
    vector<int> odds;

    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;

        if (d % 2 == 0) {
            count += d;
        } else {
            odds.push_back(d);
        }
    }

    if (odds.size() == 0) {
        cout << 0;
        return;
    }

    sort(odds.begin(), odds.end());

    // Add the largest odds that we don't sacrifice
    for (int i = odds.size() / 2; i < odds.size(); i++) {
        count += odds[i];
    }

    cout << count;
}

int main() {
    setIO("");

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
