#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t n, x;
    cin >> n >> x;

    map<size_t, size_t> cache; // hardly a cache but ok

    for (int i = 0; i < n; i++) {
        size_t newnum;
        cin >> newnum;

        if (cache.contains(x - newnum)) {
            cout << cache[x - newnum] + 1 << " " << i + 1;
            return 0;
        }

        cache[newnum] = i;
    }

    cout << "IMPOSSIBLE";
}
