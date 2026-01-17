#include <bits/stdc++.h>
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
    setIO("shuffle");

    ll N;
    cin >> N;

    vector<ll> a(N), to(N);
    for (ll i = 0; i < N; i++) {
        cin >> a[i];
        to[a[i] - 1] = i;
    }

    vector<ll> cows(N);
    for (ll i = 0; i < N; i++)
        cin >> cows[i];

    for (ll i = 0; i < 3; i++) {
        auto newcows = cows;
        for (ll j = 0; j < N; j++) {
            newcows[to[j]] = cows[j];
        }

        cows = newcows;
    }

    for (ll cow : cows) {
        cout << cow << "\n";
    }
}
