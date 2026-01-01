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

string solve() {
    int n, k;
    cin >> n >> k;

    map<ll, ll> orders{};
    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;
        orders[a] += b;
    }

    ll last_day = 0;
    ll units = 0;
    for (auto& order : orders) {
        units += (order.first - last_day) * k;
        units -= order.second;

        if (units < 0)
            return "No";

        last_day = order.first;
    }

    return "Yes";
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}
