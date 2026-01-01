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
    setIO("planting");

    int N;
    cin >> N;

    map<int, int> deg;
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;

        deg[a]++;
        deg[b]++;
    }

    int ans = 1;
    for (auto& field : deg) {
        ans = max(ans, field.second + 1);
    }

    cout << ans;
}
