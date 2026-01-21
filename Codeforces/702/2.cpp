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

    vector<int> cities(n), towers(m);
    for (int i = 0; i < n; i++) {
        cin >> cities[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> towers[i];
    }

    int max_distance = 0;
    int j = 0;

    for (int i = 0; i < n; i++) {
        while (j + 1 < m && abs(towers[j + 1] - cities[i]) <= abs(towers[j] - cities[i])) {
            j++;
        }
        max_distance = max(max_distance, abs(towers[j] - cities[i]));
    }

    cout << max_distance;
}
