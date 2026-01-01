#include <bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("pails");

    int X, Y, M;
    cin >> X >> Y >> M;

    int total = 0;

    for (int i = 0; i * X <= M; i++) {
        for (int j = 0; i * X + j * Y <= M; j++) {
            int newmax = X * i + Y * j;
            total = max(total, newmax);
        }
    }

    cout << total;
}
