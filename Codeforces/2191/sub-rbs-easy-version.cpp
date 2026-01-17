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

int main() {
    setIO();

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        string s;
        cin >> s;

        ll consecutive = 0;
        for (auto& c : s) {
            if (c == '(') {
                consecutive++;
            } else {
                break;
            }
        }

        // Need consecutive+1 closing brackets, have n/2 - 1 because we overwrote one
        if (n / 2 - 1 >= consecutive + 1) {
            cout << n - 2 << "\n";
        } else {
            cout << "-1\n";
        }
    }
}
