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

ll solve() {
    ll n;
    cin >> n;

    set<ll> a_temp;
    for (ll i = 0; i < n; i++) {
        ll num;
        cin >> num;
        a_temp.insert(num);
    }

    ll max_run = 1, current_run = 1;
    const vector<ll> a(a_temp.begin(), a_temp.end());
    for (ll i = 0; i < a.size() - 1; i++) {
        if (a[i + 1] - a[i] == 1) {
            current_run++;
        } else {
            max_run = max(max_run, current_run);
            current_run = 1;
        }
    }
    max_run = max(max_run, current_run);

    return max_run;
}

int main() {
    setIO();

    ll t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
