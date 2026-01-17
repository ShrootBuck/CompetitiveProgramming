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

ll solve() {
    int n;
    cin >> n;

    map<int, int> freq;
    for (int i = 0; i < 2 * n; i++) {
        int num;
        cin >> num;

        freq[num]++;
    }

    int odd_count = 0, even_count = 0;

    for (auto& p : freq) {
        if (p.second % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    int theoretical_max = 2 * even_count + odd_count;

    if (odd_count == 0 && even_count % 2 != n % 2) {
        theoretical_max -= 2;
    }

    return theoretical_max;
}

int main() {
    setIO();

    int t;
    cin >> t;

    while (t--) {
        cout << solve() << "\n";
    }
}
