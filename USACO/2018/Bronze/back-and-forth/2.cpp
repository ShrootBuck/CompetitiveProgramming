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

set<ll> final_readings;

void solve(ll day, ll tank_a, ll tank_b, vector<ll> a, vector<ll> b) {
    if (day == 5) {
        final_readings.insert(tank_a);
        return;
    }

    if (day % 2 == 0) { // Second to First
        for (ll i = 0; i < b.size(); i++) {
            vector<ll> newb = b;
            newb.erase(newb.begin() + i);
            auto newa = a;
            newa.push_back(b[i]);
            solve(day + 1, tank_a + b[i], tank_b - b[i], newa, newb);
        }
    } else { // First to Second
        for (ll i = 0; i < a.size(); i++) {
            vector<ll> newa = a;
            newa.erase(newa.begin() + i);
            auto newb = b;
            newb.push_back(a[i]);
            solve(day + 1, tank_a - a[i], tank_b + a[i], newa, newb);
        }
    }
}

int main() {
    setIO("backforth");

    vector<ll> a(10), b(10);
    for (ll i = 0; i < 10; i++)
        cin >> a[i];
    for (ll i = 0; i < 10; i++)
        cin >> b[i];

    solve(1, 1000, 1000, a, b);
    cout << final_readings.size();
}
