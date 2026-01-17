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

        ll z = 0, o = 0;
        for (auto& c : s) {
            if (c == '1')
                o++;
            else
                z++;
        }

        vector<ll> indices;
        for (ll i = 0; i < z; i++) {
            if (s[i] == '1') {
                indices.push_back(i + 1);
            }
        }
        for (ll i = z; i < n; i++) {
            if (s[i] == '0') {
                indices.push_back(i + 1);
            }
        }

        if (indices.empty()) {
            cout << "Bob\n";
        } else {
            cout << "Alice\n" << indices.size() << "\n";
            for (const auto& i : indices) {
                cout << i << " ";
            }
            cout << "\n";
        }
    }
}
