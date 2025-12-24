#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
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
    setIO("cowqueue");

    ll N;
    cin >> N;

    vector<pair<ll, ll>> a(N);
    for (ll i = 0; i < N; i++)
        cin >> a[i].first >> a[i].second;
    sort(a.begin(), a.end());

    for (ll i = 1; i < N; i++) {
        a[i].first = max(a[i].first, a[i - 1].first + a[i - 1].second);
    }

    cout << a[N - 1].first + a[N - 1].second;
}
