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

int solve() {
    int n;
    cin >> n;

    vector<int> negatives;

    int swaps = 0;

    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if (num == 0) {
            swaps++;
        } else if (num < 0) {
            negatives.push_back(num);
        }
    }

    sort(negatives.begin(), negatives.end());

    if (negatives.size() % 2 == 0) {
        return swaps;
    } else {
        return swaps + abs(negatives[0]) + 1;
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
