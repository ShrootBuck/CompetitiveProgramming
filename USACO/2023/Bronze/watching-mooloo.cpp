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

    ll N, K;
    cin >> N >> K;

    vector<ll> days(N);

    for (int i = 0; i < N; i++) {
        cin >> days[i];
    }

    ll cost = 1 + K;

    for (int i = 1; i < N; i++) {
        if (days[i] - days[i - 1] <= K + 1) {
            cost += days[i] - days[i - 1];
        } else {
            cost += K + 1;
        }
    }

    cout << cost;
}
