#include <algorithm>
#include <cstdio>
#include <cstdlib>
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

struct goal {
    ll t;
    ll l;
    ll u;
};

bool solve() {
    ll N, H;
    cin >> N >> H;

    vector<goal> goals(N);
    for (int i = 0; i < N; i++) {
        cin >> goals[i].t >> goals[i].l >> goals[i].u;
    }

    ll min_h = H, max_h = H;
    ll time = 0;
    for (int i = 0; i < N; i++) {
        goal& g = goals[i];
        max_h += g.t - time;
        min_h -= g.t - time;

        min_h = max(min_h, g.l);
        max_h = min(max_h, g.u);

        if (min_h > max_h) {
            return false;
        }

        time = g.t;
    }

    return true;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << (solve() ? "Yes" : "No") << "\n";
    }
}
