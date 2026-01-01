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

void solve() {
    int n, k;
    cin >> n >> k;

    ll answer = 0;
    vector<int> a(n);
    unordered_map<int, int> freq;
    unordered_map<int, int> target_counts; // How many of a number need to be in
                                           // each multiset (a[i]/k)

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        freq[a[i]]++;
    }

    for (auto frequency : freq) {
        if (frequency.second % k != 0) {
            cout << 0;
            return;
        }

        target_counts[frequency.first] = frequency.second / k;
    }

    unordered_map<int, int> window_counts;

    int l = 0;

    for (int r = 0; r < n; r++) {
        // Add the new element to the window
        window_counts[a[r]]++;

        while (window_counts[a[r]] > target_counts[a[r]]) {
            // Too many a[r]s = must shrink the window from the left until it's valid
            window_counts[a[l]]--;
            l++;
        }

        answer += r - l + 1;
    }

    cout << answer;
}

int main() {
    setIO("");

    int t;
    cin >> t;

    while (t--) {
        solve();
        cout << "\n";
    }
}
