#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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

    int N, M, K;
    cin >> N >> M >> K;

    vector<ll> H(N);
    vector<ll> B(M);

    for (int i = 0; i < N; i++) {
        cin >> H[i];
    }

    for (int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(H.begin(), H.end());
    sort(B.begin(), B.end());

    int last_b = 0;

    for (int i = 0; i < K; i++) {
        while (H[i] > B[last_b] && last_b < M) {
            last_b++;
        }

        if (H[i] > B[last_b]) {
            cout << "No";
            return 0;
        }

        last_b++;
    }

    cout << "Yes";
}
