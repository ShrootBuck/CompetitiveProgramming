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

    ll N, M;
    cin >> N >> M;

    string s;
    cin >> s;

    ll total_milk = 0;
    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        total_milk += a[i];
    }

    for (int i = 0; i < N; i++) {
        if (s[i] == 'R' && s[(i + 1) % N] == 'L') {
            ll count = 0;
            for (int j = (i - 1 + N) % N;; j = (j - 1 + N) % N) {
                if (s[j] == 'R') {
                    count += a[j];
                } else {
                    break;
                }
            }
            total_milk -= min(M, count);

            count = 0;
            for (int j = (i + 2) % N;; j = (j + 1) % N) {
                if (s[j] == 'L') {
                    count += a[j];
                } else {
                    break;
                }
            }
            total_milk -= min(M, count);
        }
    }

    cout << total_milk;
}
