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
    setIO("herding");

    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    if ((a[N - 2] - a[0] == N - 2 && a[N - 1] - a[N - 2] > 2) ||
        (a[N - 1] - a[1] == N - 2 && a[1] - a[0] > 2)) {
        cout << "2\n";
    } else {
        int best_gap = INT_MAX, r = 0;
        for (int l = 0; l < N; l++) {
            while (r < N && a[r] - a[l] < N)
                r++;

            best_gap = min(best_gap, N - (r - l)); // (r - 1) - l + 1 = r - l
        }
        cout << best_gap << '\n';
    }

    int total_gaps = a[N - 1] - a[0] + 1 - N;
    int left_lost = a[1] - a[0] - 1, right_lost = a[N - 1] - a[N - 2] - 1;
    cout << total_gaps - min(left_lost, right_lost);
}
