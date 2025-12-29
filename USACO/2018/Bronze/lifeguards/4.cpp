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
    setIO("lifeguards");

    ll N;
    cin >> N;

    vector<pair<ll, ll>> shifts(N);
    vector<ll> base_covering(1001, 0);
    for (ll i = 0; i < N; i++) {
        ll a, b;
        cin >> a >> b;
        shifts[i] = {a, b};
        base_covering[a]++;
        base_covering[b]--;
    }

    ll ans = 0;

    for (auto& shift : shifts) {
        auto covering = base_covering;
        covering[shift.first]--;
        covering[shift.second]++;

        ll local_ans = 0;

        for (ll i = 1; i < 1001; i++) {
            covering[i] += covering[i - 1];
            local_ans += covering[i] > 0;
        }

        ans = max(ans, local_ans);
    }

    cout << ans;
}
