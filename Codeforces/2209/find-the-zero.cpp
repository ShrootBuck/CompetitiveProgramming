#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// First interactive problem and I must say I love this format
int query(int i, int j) {
    cout << "? " << i << " " << j << endl; // endl automatically flushes
    int res;
    cin >> res;
    if (res == -1)
        exit(0);
    return res;
}

// Reports the answer
void answer(int k) { cout << "! " << k << endl; }

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i < 2 * n - 1; i += 2) {
        int j = i + 1;
        if (query(i, j) == 1) {
            answer(i);
            return;
        }
    }

    if (query(2 * n, 1) == 1 || query(2 * n, 2) == 1)
        answer(2 * n);
    else
        answer(2 * n - 1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();
}
