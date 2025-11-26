#include <algorithm>
#include <cstdio>
#include <iostream>
#include <numeric>
#include <set>
#include <string>
#include <utility>
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

int main() {
    setIO("reduce");

    int N;
    cin >> N;

    vector<int> ids(N);
    iota(ids.begin(), ids.end(), 0);

    vector<pair<int, int>> cows(N);

    for (int i = 0; i < N; i++) {
        cin >> cows[i].first >> cows[i].second;
    }

    set<int> candidates;

    // Sort for X
    sort(ids.begin(), ids.end(), [&](int a, int b) { return cows[a].first < cows[b].first; });

    for (int i = 0; i <= 3; i++) {
        candidates.insert(ids[i]);
        candidates.insert(ids[N - (i + 1)]);
    }

    // Re-sort for Y
    sort(ids.begin(), ids.end(), [&](int a, int b) { return cows[a].second < cows[b].second; });

    for (int i = 0; i <= 3; i++) {
        candidates.insert(ids[i]);
        candidates.insert(ids[N - (i + 1)]);
    }

    ll area = 40001 * 40001;

    // bootleg recursion
    for (int i : candidates) {
        for (int j : candidates) {
            for (int k : candidates) {
                int min_x = 40001, min_y = 40001;
                int max_x = 0, max_y = 0;

                for (int cow : candidates) {
                    // I am loving this shorthand, my code feels very ambiguous
                    if (cow == i || cow == j || cow == k)
                        continue;

                    min_x = min(min_x, cows[cow].first);
                    max_x = max(max_x, cows[cow].first);
                    min_y = min(min_y, cows[cow].second);
                    max_y = max(max_y, cows[cow].second);
                }

                area = min(area, (ll)(max_x - min_x) * (max_y - min_y));
            }
        }
    }

    cout << area;
}
