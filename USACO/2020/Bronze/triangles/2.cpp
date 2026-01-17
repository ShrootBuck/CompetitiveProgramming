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
    setIO("triangles");

    ll N;
    cin >> N;

    vector<pair<ll, ll>> points(N);
    for (ll i = 0; i < N; i++)
        cin >> points[i].first >> points[i].second;

    ll ans = LLONG_MIN;
    for (ll i = 0; i < N; i++) {
        for (ll j = 0; j < N; j++) {
            for (ll k = 0; k < N; k++) {
                if (i == j || j == k || i == k)
                    continue;

                ll local_ans;
                if ((points[i].first == points[j].first && points[i].second == points[k].second)) {
                    local_ans = abs(points[i].second - points[j].second) *
                                abs(points[i].first - points[k].first);
                } else if ((points[i].second == points[j].second &&
                            points[i].first == points[k].first)) {
                    local_ans = abs(points[i].first - points[j].first) *
                                abs(points[i].second - points[k].second);
                } else {
                    continue;
                }

                ans = max(ans, local_ans);
            }
        }
    }

    cout << ans;
}
