#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0, i = 0, j = 0;

    while (i < n && j < m) {
        if (a[i] - k > b[j]) {
            j++;
        } else if (a[i] + k < b[j]) {
            i++;
        } else {
            ans++, i++, j++;
        }
    }

    cout << ans;
}
