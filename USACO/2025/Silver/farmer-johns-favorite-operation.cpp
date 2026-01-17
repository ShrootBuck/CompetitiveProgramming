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
    ll N, M;
    cin >> N >> M;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
        a[i] %= M;
    }
    sort(a.begin(), a.end());

    vector<ll> b(2 * N);
    for (int i = 0; i < N; i++) {
        b[i] = a[i];
        b[i + N] = a[i] + M;
    }

    vector<ll> prefix(2 * N + 1, 0);
    for (int i = 0; i < 2 * N; i++) {
        prefix[i + 1] = prefix[i] + b[i];
    }

    ll cost = LLONG_MAX;
    for (int i = 0; i < N; i++) {
        int mid_i = i + N / 2;
        ll mid = b[mid_i];
        ll left_cost = N / 2 * mid - (prefix[mid_i] - prefix[i]);
        ll right_cost = (prefix[i + N] - prefix[mid_i + 1]) - ((N - 1 - (N / 2)) * mid);
        cost = min(left_cost + right_cost, cost);
    }

    return cost;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}
