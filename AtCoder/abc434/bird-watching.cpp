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

    int N, M;
    cin >> N >> M;

    vector<int> counts(M, 0);
    vector<int> size(M, 0);

    for (int i = 0; i < N; i++) {
        int A, B;
        cin >> A >> B;
        A--;

        size[A] += B;
        counts[A]++;
    }

    for (int i = 0; i < M; i++) {
        cout << (double)size[i] / counts[i] << "\n";
    }
}
