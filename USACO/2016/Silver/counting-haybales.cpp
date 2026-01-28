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
    setIO("haybales");

    int N, Q;
    cin >> N >> Q;

    vector<int> positions(N);
    for (int i = 0; i < N; i++)
        cin >> positions[i];
    sort(positions.begin(), positions.end());

    for (int i = 0; i < Q; i++) {
        int A, B;
        cin >> A >> B;

        auto left = lower_bound(positions.begin(), positions.end(), A);
        auto right = upper_bound(positions.begin(), positions.end(), B);

        cout << (right - left) << '\n';
    }
}
