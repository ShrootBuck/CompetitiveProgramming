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

    int N, Q;
    cin >> N >> Q;

    vector<ll> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<ll> prefix = a;
    for (int i = 1; i < N; i++) {
        prefix[i] += prefix[i - 1];
    }

    for (int i = 0; i < Q; i++) {
        int l, r;
        cin >> l >> r;

        ll left_remove = 0;

        if (l != 0) {
            left_remove = prefix[l - 1];
        }

        cout << prefix[r - 1] - left_remove << "\n";
    }
}
