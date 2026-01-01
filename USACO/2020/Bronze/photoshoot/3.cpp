#include <bits/stdc++.h>

using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO("photo");

    ll N;
    cin >> N;

    vector<ll> b(N);
    for (ll i = 0; i < N; i++)
        cin >> b[i];

    for (ll ai = 1; ai <= N; ai++) {
        vector<ll> a(N);
        vector<bool> seen(N, false);
        a[0] = ai;
        bool valid = true;
        for (ll i = 1; i < N; i++) {
            a[i] = b[i - 1] - a[i - 1];

            if (a[i] < 1 || a[i] > N) {
                valid = false;
                continue;
            }

            if (seen[a[i]]) {
                valid = false;
            } else {
                seen[a[i]] = true;
            }
        }

        if (valid) {
            for (ll i = 0; i < N; i++) {
                cout << a[i] << (i != N - 1 ? " " : "");
            }
            return 0;
        }
    }
}
