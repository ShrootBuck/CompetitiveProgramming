#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t N;
    cin >> N;

    vector<pair<int, int>> grid{};

    long long max_distance = 0;

    for (size_t i = 0; i < N; i++) {
        int x;
        cin >> x;
        grid.push_back({x, 0});
    }
    for (size_t i = 0; i < N; i++) {
        cin >> grid[i].second;
    }

    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            max_distance = max(max_distance, (long long)(pow(grid[i].second - grid[j].second, 2) +
                                                         pow(grid[i].first - grid[j].first, 2)));
        }
    }

    cout << max_distance;
}
