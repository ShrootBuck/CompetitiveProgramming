#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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
    int n, k;
    cin >> n >> k;

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<ll> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    if (k % 2 == 0) {
        ll best_score = LLONG_MIN;
        ll current_streak = LLONG_MIN;

        for (int i = 0; i < n; i++) {
            if (current_streak < 0) {
                current_streak = a[i];
            } else {
                current_streak += a[i];
            }

            best_score = max(best_score, current_streak);
        }
        return best_score;

    } else {
        // left[i] = Max sum of a subarray that ends at i
        vector<ll> left(n, 0);
        left[0] = a[0];
        for (int i = 1; i < n; i++) {
            left[i] = max(a[i], left[i - 1] + a[i]);
        }

        // right[i] = Max sum of a subarray that starts at index i
        vector<ll> right(n, 0);
        right[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            right[i] = max(a[i], right[i + 1] + a[i]);
        }

        ll best_score = LLONG_MIN;

        for (int i = 0; i < n; ++i) {
            // Let Alice use her boost b
            ll total = left[i] + right[i] - a[i] + b[i];

            best_score = max(best_score, total);
        }

        return best_score;
    }
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
