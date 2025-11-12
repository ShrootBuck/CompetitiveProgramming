#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <utility>
#include <vector>
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
    setIO("balancing");

    int N;
    cin >> N;

    vector<pair<int, int>> coordinates;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    auto x_sorted = coordinates;
    auto y_sorted = coordinates;

    sort(x_sorted.begin(), x_sorted.end());
    sort(y_sorted.begin(), y_sorted.end(),
         [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; });

    int M = N;

    for (int i = 0; i < N; ++i) {
        int a = x_sorted[i].first + 1;

        int top_left = 0, top_right = 0;
        int bottom_left = i + 1;
        int bottom_right = N - (i + 1);

        for (int j = 0; j < N; ++j) {
            if (y_sorted[j].first < a) {
                bottom_left--;
                top_left++;
            } else {
                bottom_right--;
                top_right++;
            }

            M = min(M, max({top_left, top_right, bottom_left, bottom_right}));
        }
    }

    cout << M;
}
