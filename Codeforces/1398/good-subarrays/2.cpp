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

ll solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;
    vector<int> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = s[i] - '0' - 1;
    }

    ll ans = 0;
    map<int, int> counts{{0, 1}};

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += b[i];
        ans += counts[sum];
        counts[sum]++;
    }

    return ans;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
