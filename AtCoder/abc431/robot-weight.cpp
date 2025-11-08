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

    int X, N;
    cin >> X >> N;

    vector<int> W(N);
    vector<int> enabled(N);
    for (int i = 0; i < N; i++) {
        cin >> W[i];
    }

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int P;
        cin >> P;

        enabled[P - 1] = !enabled[P - 1];

        if (enabled[P - 1]) {
            X += W[P - 1];
        } else {
            X -= W[P - 1];
        }

        cout << X << "\n";
    }
}
