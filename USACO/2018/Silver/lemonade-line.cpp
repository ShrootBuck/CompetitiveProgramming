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

int main() {
    setIO("lemonade");

    ll N;
    cin >> N;

    vector<ll> w(N);
    for (ll i = 0; i < N; i++)
        cin >> w[i];

    sort(w.rbegin(), w.rend());
    ll i = 0;
    for (; i < N; i++) {
        if (w[i] < i) {
            break;
        }
    }

    cout << i;
}
