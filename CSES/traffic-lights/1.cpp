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
    setIO();

    int x, n;
    cin >> x >> n;

    set<int> p{0, x};
    multiset<int> gaps{x};

    for (int i = 0; i < n; i++) {
        int pi;
        cin >> pi;

        auto right = p.upper_bound(pi);
        auto left = prev(right);

        p.insert(pi);

        gaps.erase(gaps.find(*right - *left));
        gaps.insert(pi - *left);
        gaps.insert(*right - pi);

        cout << *gaps.rbegin() << " ";
    }
}
