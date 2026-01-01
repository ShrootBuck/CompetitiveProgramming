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
    setIO("");

    int Q;
    cin >> Q;

    map<ll, ll> redis;

    // mutate important state because you only live once
    while (Q--) {
        int command;
        cin >> command;

        if (command == 1) {
            ll k;
            cin >> k;
            cout << redis[k] << "\n";
        } else {
            ll k;
            ll v;
            cin >> k >> v;

            redis[k] = v;
        }
    }
}
