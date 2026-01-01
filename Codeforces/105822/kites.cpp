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

void solve() {
    int N;
    cin >> N;

    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    vector<int> diffs(N - 1);
    for (int i = 0; i < N - 1; i++) {
        diffs[i] = a[i + 1] - a[i];
    }

    vector<int> suff(N - 1);
    suff[N - 2] = diffs[N - 2];
    for (int i = N - 3; i >= 0; i--) {
        suff[i] = min(suff[i + 1], diffs[i]);
    }

    int ans = INT_MAX;
    for (int k = 0; k <= N - 4; k++) {
        ans = min(ans, diffs[k] + suff[k + 2]);
    }

    cout << ans;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        solve();
        cout << "\n";
    }
}
