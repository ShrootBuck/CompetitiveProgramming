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

    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto prefix = a;
    for (int i = 1; i < n; i++) {
        prefix[i] += prefix[i - 1];
    }

    ll ans = 0;

    map<ll, int> freq{{0, 1}};
    for (int i = 0; i < n; i++) {
        int remainder = ((prefix[i] % n) + n) % n;

        prefix[i] = remainder;
        ans += freq[remainder];
        freq[remainder]++;
    }

    cout << ans;
}
