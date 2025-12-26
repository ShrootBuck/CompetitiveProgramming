#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO("cbarn");

    ll n;
    cin >> n;

    vector<ll> r(n);
    for (ll i = 0; i < n; i++)
        cin >> r[i];

    ll distance = LLONG_MAX;
    for (ll i = 0; i < n; i++) {
        ll local_distance = 0;
        for (ll j = 0; j < n; j++) {
            local_distance += j * r[(i + j) % n];
        }

        distance = min(distance, local_distance);
    }

    cout << distance;
}
