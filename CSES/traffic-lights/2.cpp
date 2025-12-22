#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iterator>
#include <set>
#include <string>
#include <vector>
using namespace std;

using ll = long long;

void setIO(string name = "") {
    cin.tie(0)->sync_with_stdio(0);

    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#ifdef LOCAL_RUN
    else {
        freopen("f.in", "r", stdin);
        freopen("f.out", "w", stdout);
    }
#endif
}

int main() {
    setIO();

    ll x, n;
    cin >> x >> n;

    vector<ll> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    multiset<ll> gaps{x};
    set<ll> lights{0, x};

    for (int i = 0; i < n; i++) {
        auto [it, success] = lights.insert(p[i]);
        auto after = next(it);
        auto previous = prev(it);

        if (after == lights.end()) {
            gaps.insert(x - *it);
        } else {
            gaps.insert(*after - *it);
        }

        if (previous == lights.begin()) {
            gaps.insert(*it);
        } else {
            gaps.insert(*it - *previous);
        }

        gaps.erase(gaps.find(*after - *previous));

        cout << *prev(gaps.end()) << " ";
    }
}
