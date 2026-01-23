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
    setIO("diamond");

    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    vector<int> len(N);
    int r = 0;

    for (int l = 0; l < N; l++) {
        while (r < N && a[r] - a[l] <= K) {
            r++;
        }
        len[l] = r - l;
    }

    vector<int> suffix = len;
    for (int i = N - 2; i >= 0; i--) {
        suffix[i] = max(suffix[i], suffix[i + 1]);
    }

    int best = 0;
    for (int i = 0; i < N; i++) {
        int current_len = len[i];
        if (i + current_len < N) {
            best = max(best, current_len + suffix[i + current_len]);
        } else {
            best = max(best, current_len);
        }
    }

    cout << best;
}
