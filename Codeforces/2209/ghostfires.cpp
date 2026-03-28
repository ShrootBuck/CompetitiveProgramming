#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

void solve() {
    int r, g, b;
    cin >> r >> g >> b;

    int rg = 0, gb = 0, rb = 0;
    while ((r > 0) + (g > 0) + (b > 0) > 1) {
        if (r <= g && r <= b)
            gb++, g--, b--;
        else if (g <= r && g <= b)
            rb++, r--, b--;
        else if (b <= r && b <= g)
            rg++, r--, g--;
    }

    if (g > 0) {
        cout << 'G';
        while (rg > 0)
            cout << "RG", rg--;

        bool flip = false;
        while (gb > 0)
            cout << "BG", gb--, flip = true;

        if (flip) {
            while (rb > 0)
                cout << "BR", rb--;
        } else {
            while (rb > 0)
                cout << "RB", rb--;
        }
    } else if (r > 0) {
        cout << 'R';
        while (rg > 0)
            cout << "GR", rg--;

        bool flip = false;
        while (rb > 0) {
            cout << "BR", rb--, flip = true;
        }
        if (flip) {
            while (gb > 0)
                cout << "BG", gb--;
        } else {
            while (gb > 0)
                cout << "GB", gb--;
        }
    } else {
        if (b > 0)
            cout << 'B';
        while (gb > 0)
            cout << "GB", gb--;

        bool flip = false;
        while (rb > 0)
            cout << "RB", rb--, flip = true;

        if (flip) {
            while (rg > 0)
                cout << "RG", rg--;
        } else {
            while (rg > 0)
                cout << "GR", rg--;
        }
    }
}

int main() {
    setIO();
    int t;
    cin >> t;
    while (t--)
        solve(), cout << '\n';
}
