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

    map<ll, vector<int>> buckets;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;

        buckets[i - num].push_back(num); // We just need the weight
    }

    for (auto& bucket : buckets) {
        sort(bucket.second.rbegin(), bucket.second.rend());
    }

    ll sum = 0;

    for (auto& bucket : buckets) {
        for (int i = 0; i < bucket.second.size() - 1; i += 2) {
            if (bucket.second[i] + bucket.second[i + 1] > 0) {
                sum += bucket.second[i] + bucket.second[i + 1];
            }
        }
    }

    return sum;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}
