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

void solve() {
    int n;
    cin >> n;
    vector<ll> f(n);
    for (auto& x : f)
        cin >> x;

    ll S = (f[0] + f[n - 1]) / (n - 1);
    vector<ll> a(n);
    vector<ll> diff(n - 1);

    // diff[i] represents f(i+2) - f(i+1) in 1-based indexing
    // f[i+1] - f[i] in 0-based indexing
    for (int i = 0; i < n - 1; i++)
        diff[i] = f[i + 1] - f[i];

    a[0] = (diff[0] + S) / 2;
    for (int i = 1; i < n - 1; i++)
        a[i] = (diff[i] - diff[i - 1]) / 2;
    a[n - 1] = (S - diff[n - 2]) / 2; // lazy but idk how I would clean this into a single loop

    for (int i = 0; i < n; i++)
        cout << a[i] << (i == n - 1 ? "" : " ");
    cout << '\n';
}

int main() {
    setIO();

    int t;
    cin >> t;
    while (t--)
        solve();
}
