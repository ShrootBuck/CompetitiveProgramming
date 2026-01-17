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

    int N;
    cin >> N;

    vector<int> B(N);
    vector<int> C(N);

    ll total = 0;

    vector<int> a_counts(N + 1, 0);

    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        a_counts[val]++;
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> C[i];
    }

    for (int i = 0; i < N; i++) {
        total += a_counts[B[C[i] - 1]];
    }

    cout << total;
}
