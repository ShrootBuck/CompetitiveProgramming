#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

int main() {
    setIO();

    int n, m;
    cin >> n >> m;

    set<int> cities, towers;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        cities.insert(a);
    }
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        towers.insert(b);
    }

    int max_distance = 0;
    for (auto& city : cities) {
        auto it = towers.lower_bound(city);
        int left = *towers.begin(), right = *prev(towers.end());
        if (it != towers.begin()) {
            left = *prev(towers.lower_bound(city));
        }
        if (it != towers.end()) {
            right = *it;
        }

        max_distance = max(max_distance, min(abs(city - left), abs(right - city)));
    }

    cout << max_distance;
}
