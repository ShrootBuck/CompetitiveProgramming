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

ll solve() {
    ll N;
    cin >> N;

    vector<ll> h(N);
    for (ll i = 0; i < N; i++)
        cin >> h[i];

    if (N == 1)
        return 0;

    ll bags = 0;
    for (ll i = 0; i < N - 2; i++) {
        if (h[i + 1] > h[i]) {
            const ll delta = h[i + 1] - h[i];
            h[i + 1] -= delta, h[i + 2] -= delta;
            bags += 2 * delta;
        }
    }

    if (*min_element(h.begin(), h.end()) < 0)
        return -1;

    for (ll i = N - 1; i >= 2; i--) {
        if (h[i - 1] > h[i]) {
            const ll delta = h[i - 1] - h[i];
            h[i - 1] -= delta, h[i - 2] -= delta;
            bags += 2 * delta;
        }
    }

    if (h[1] != h[0])
        return -1;

    if (*min_element(h.begin(), h.end()) < 0)
        return -1;

    return bags;
}

int main() {
    setIO();

    ll T;
    cin >> T;
    while (T--) {
        cout << solve() << "\n";
    }
}
