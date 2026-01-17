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
    setIO("maxcross");

    int N, K, B;
    cin >> N >> K >> B;

    vector<bool> a(N);
    for (int i = 0; i < B; i++) {
        int num;
        cin >> num;

        a[num - 1] = true;
    }

    int current_broken = 0;
    for (int i = 0; i < K; i++) {
        current_broken += a[i];
    }

    int ans = current_broken;

    for (int i = K; i < N; i++) {
        current_broken -= a[i - K];
        current_broken += a[i];

        ans = min(ans, current_broken);
    }

    cout << ans;
}
