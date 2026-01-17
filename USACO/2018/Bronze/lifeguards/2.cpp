#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("lifeguards");

    int N;
    cin >> N;

    int max_covered = 0;
    array<int, 1000> coverage{};
    vector<pair<int, int>> shifts;
    int total_coverage = 0;

    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;

        for (int j = start; j < end; j++) {
            coverage[j]++;
        }

        shifts.push_back({start, end});
    }

    for (int shift : coverage) {
        if (shift > 0) {
            total_coverage++;
        }
    }

    for (int i = 0; i < N; i++) {
        int this_cow_cov = 0;
        for (int j = shifts[i].first; j < shifts[i].second; j++) {
            if (coverage[j] == 1) {
                this_cow_cov++;
            }
        }

        max_covered = max(max_covered, total_coverage - this_cow_cov);
    }

    cout << max_covered;
}
