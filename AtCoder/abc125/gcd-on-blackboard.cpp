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

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> prefix = A, suffix = A;
    for (int i = 1; i < N; i++) {
        prefix[i] = gcd(prefix[i], prefix[i - 1]);
    }
    for (int i = N - 2; i >= 0; i--) {
        suffix[i] = gcd(suffix[i], suffix[i + 1]);
    }

    // handle the two "edge" cases (edges are edge cases)
    int best = max(prefix[N - 2], suffix[1]);
    for (int i = 1; i < N - 1; i++) {
        best = max(best, gcd(prefix[i - 1], suffix[i + 1]));
    }

    cout << best;
}
