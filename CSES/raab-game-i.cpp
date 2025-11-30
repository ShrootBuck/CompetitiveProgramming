// My editorial!!
// http://usaco.guide/problems/cses-3399-raab-game-i/solution

#include <iostream>
using namespace std;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;

    int draws = n - (a + b);

    // Impossible if we need more draws than cards available
    if (draws < 0) {
        cout << "NO" << "\n";
        return;
    }

    // Impossible if one player implies a total victory on non-draw cards
    int k = n - draws;
    if (k > 0 && (a == 0 || b == 0)) {
        cout << "NO" << "\n";
        return;
    }

    cout << "YES" << "\n";

    // Player 1: Plays 1..k (winning/losing rounds), then k+1..n (draws)
    for (int i = 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";

    // Player 2: Cyclic shift for first k cards
    for (int i = 1; i <= k; i++) {
        // Shift by a and wrap around
        int val = i + a;
        if (val > k)
            val -= k;
        cout << val << " ";
    }

    // Player 2: Matches the draw cards exactly
    for (int i = k + 1; i <= n; i++) {
        cout << i << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}
