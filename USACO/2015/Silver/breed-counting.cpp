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
    setIO("bcount");

    int N, Q;
    cin >> N >> Q;

    vector<int> breeds(N);
    for (int i = 0; i < N; i++) {
        cin >> breeds[i];
    }

    vector<array<int, 3>> prefixes(N);
    prefixes[0][breeds[0] - 1]++;
    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 3; j++) {
            prefixes[i][j] += prefixes[i - 1][j];
        }
        prefixes[i][breeds[i] - 1]++;
    }

    for (int i = 0; i < Q; i++) {
        int a, b;
        cin >> a >> b;

        for (int j = 0; j < 3; j++) {
            if (a == 1) {
                cout << prefixes[b - 1][j];
            } else {
                cout << prefixes[b - 1][j] - prefixes[a - 2][j];
            }

            if (j != 2) {
                cout << " ";
            }
        }

        cout << "\n";
    }
}
