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

ll solve() {
    ll W, H, x1, y1, x2, y2, w, h;
    cin >> W >> H >> x1 >> y1 >> x2 >> y2 >> w >> h;

    ll ans = LLONG_MAX;
    bool valid = false;

    if (w + x2 - x1 <= W) {
        valid = true;
        ans = min(ans, max(0LL, w - x1));
        ans = min(ans, max(0LL, x2 - W + w));
    }

    if (h + y2 - y1 <= H) {
        valid = true;
        ans = min(ans, max(0LL, h - y1));
        ans = min(ans, max(0LL, y2 - H + h));
    }

    return valid ? ans : -1;
}

int main() {
    setIO();

    ll t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
