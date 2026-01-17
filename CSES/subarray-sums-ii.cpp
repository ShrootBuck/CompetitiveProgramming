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

    int n, x;
    cin >> n >> x;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    ll prefix = 0;
    ll ans = 0;

    map<ll, int> freq;
    freq[0] = 1;

    for (int i = 0; i < n; i++) {
        prefix += a[i];
        ans += freq[prefix - x];

        freq[prefix]++;
    }

    cout << ans;
}
