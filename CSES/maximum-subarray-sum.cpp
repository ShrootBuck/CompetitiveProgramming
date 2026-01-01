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

int main() {
    setIO();

    ll n;
    cin >> n;

    vector<ll> x(n);
    for (ll i = 0; i < n; i++)
        cin >> x[i];

    ll sum = 0, ans = INT_MIN;
    for (ll i = 0; i < n; i++) {
        if (x[i] > sum + x[i]) {
            sum = x[i];
        } else {
            sum += x[i];
        }

        ans = max(sum, ans);
    }

    cout << ans;
}
