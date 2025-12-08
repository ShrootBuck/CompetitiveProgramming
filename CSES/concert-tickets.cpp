#include <algorithm>
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

int main() {
    setIO();

    int n, m;
    cin >> n >> m;

    multiset<int> h;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        h.insert(x);
    }
    vector<int> t(m);

    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }

    for (auto& x : t) {
        auto it = h.upper_bound(x);
        if (it == h.begin()) {
            cout << "-1\n";
            continue;
        } else {
            it--;
        }

        cout << *it << "\n";
        h.erase(it);
    }
}
