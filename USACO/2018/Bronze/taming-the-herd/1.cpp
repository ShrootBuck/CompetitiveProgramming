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
    setIO("taming");

    int N;
    cin >> N;

    vector<int> breakouts(N);

    for (int i = 0; i < N; i++) {
        cin >> breakouts[i];
    }

    if (breakouts[0] > 0) {
        cout << -1;
        return 0;
    }

    breakouts[0] = 0;

    int confirmed = 0;
    int unsure = 0;
    int expected = -1;

    for (int i = N - 1; i >= 0; i--) {
        int& breakout = breakouts[i];

        if (expected != -1 && breakout != -1 && expected != breakout) {
            cout << -1;
            return 0;
        }

        if (expected == -1) {
            expected = breakout;
        }

        if (breakout == -1) {
            breakouts[i] = expected;
        }

        if (breakout == 0) {
            confirmed++;
        }

        if (breakout == -1) {
            unsure++;
        }

        if (expected > -1) {
            expected--;
        }
    }

    cout << confirmed << " " << unsure + confirmed;
}
