#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef ZK_LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO("reduce");

    ll N;
    cin >> N;

    vector<pair<ll, ll>> cows(N), x_to_id(N), y_to_id(N);
    for (ll i = 0; i < N; i++) {
        ll x, y;
        cin >> x >> y;

        cows[i].first = x;
        cows[i].second = y;
        x_to_id[i] = {x, i};
        y_to_id[i] = {y, i};
    }
    sort(x_to_id.begin(), x_to_id.end());
    sort(y_to_id.begin(), y_to_id.end());

    set<ll> reduced_id_set;
    for (ll i = 0; i < 2; i++) {
        reduced_id_set.insert(x_to_id[i].second);
        reduced_id_set.insert(y_to_id[i].second);
        reduced_id_set.insert(x_to_id[N - 1 - i].second);
        reduced_id_set.insert(y_to_id[N - 1 - i].second);
    }
    const vector<ll> reduced_ids(reduced_id_set.begin(), reduced_id_set.end());

    ll min_fence = LLONG_MAX;
    for (const ll removed_id : reduced_ids) {
        ll min_x = LLONG_MAX, min_y = LLONG_MAX;
        ll max_x = LLONG_MIN, max_y = LLONG_MIN;
        for (const ll potential_id : reduced_ids) {
            if (potential_id == removed_id)
                continue;

            min_x = min(min_x, cows[potential_id].first);
            max_x = max(max_x, cows[potential_id].first);
            min_y = min(min_y, cows[potential_id].second);
            max_y = max(max_y, cows[potential_id].second);
        }

        min_fence = min(min_fence, ((max_x - min_x) * (max_y - min_y)));
    }

    cout << min_fence;
}
