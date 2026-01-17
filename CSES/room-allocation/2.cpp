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
    setIO();

    ll n;
    cin >> n;

    vector<pair<pair<ll, ll>, ll>> customers;
    for (ll i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        customers.push_back({{a, b}, i});
    }
    sort(customers.begin(), customers.end());

    ll room = 0;
    vector<ll> ans(n);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    for (auto& customer : customers) {
        ll arrival = customer.first.first;
        ll departure = customer.first.second;
        ll original_i = customer.second;

        if (!pq.empty() && pq.top().first < arrival) {
            ll room_id = pq.top().second;
            pq.pop();
            pq.push({departure, room_id});
            ans[original_i] = room_id;
        } else {
            room++;
            pq.push({departure, room});
            ans[original_i] = room;
        }
    }

    cout << room << "\n";

    for (int i = 0; i < n; i++)
        cout << ans[i] << " ";
}
