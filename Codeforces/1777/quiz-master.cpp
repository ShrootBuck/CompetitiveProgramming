#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

vector<vector<int>> factors(1e5 + 1);
vector<int> freq(1e5 + 1);
void precompute() {
    for (int i = 1; i < factors.size(); i++) {
        for (int j = i; j < factors.size(); j += i) {
            factors[j].push_back(i);
        }
    }
}

int solve() {
    int n, m;
    cin >> n >> m;
    fill_n(freq.begin(), m + 1, 0);

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());

    int l = 0, best = INT_MAX, covered_factors = 0;
    for (int r = 0; r < n; r++) {
        // Add right
        for (int& factor : factors[a[r]]) {
            if (factor > m)
                continue;
            freq[factor]++;
            if (freq[factor] == 1)
                covered_factors++;
        }

        // Remove left as much as we can, then maximize
        while (covered_factors == m) {
            best = min(best, a[r] - a[l]);

            for (int& factor : factors[a[l]]) {
                if (factor > m)
                    continue;
                freq[factor]--;
                if (freq[factor] == 0)
                    covered_factors--;
            }

            l++;
        }
    }

    return (best == INT_MAX ? -1 : best);
}

int main() {
    precompute();
    setIO();

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << '\n';
    }
}
