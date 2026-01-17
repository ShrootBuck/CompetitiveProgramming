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

    vector<int> a(N, 0);

    vector<int> b(N - 1);
    for (int i = 0; i < N - 1; i++)
        cin >> b[i];

    for (int start = 1; start <= N; start++) {
        a[0] = start;
        bool possible = true;
        vector<bool> used(N + 1, false);
        used[start] = true;

        for (int i = 1; i < N; i++) {
            a[i] = b[i - 1] - a[i - 1];

            if (a[i] < 1 || a[i] > N) {
                possible = false;
                break;
            }

            if (used[a[i]]) {
                possible = false;
                break;
            }

            used[a[i]] = true;
        }

        if (possible) {
            for (int i = 0; i < N; i++) {
                cout << a[i] << (i != N - 1 ? " " : "");
            }

            return 0;
        }
    }
}
