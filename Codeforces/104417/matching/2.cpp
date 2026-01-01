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

    vector<int> a(n);
    vector<int> diff(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        diff[i] = a[i] - i;
    }

    map<int, vector<int>> buckets;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        buckets[diff[i]].push_back(a[i]);
    }

    for (auto& b : buckets) {
        vector<int> nums(b.second.begin(), b.second.end());
        sort(nums.rbegin(), nums.rend());

        for (int i = 0; i < b.second.size() - 1; i += 2) {
            if (nums[i] + nums[i + 1] > 0) {
                ans += nums[i] + nums[i + 1];
            } else {
                break;
            }
        }
    }

    return ans;
}

int main() {
    setIO("");

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}
