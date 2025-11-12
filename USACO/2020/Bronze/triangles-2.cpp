#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
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
    setIO("triangles");

    size_t N;
    cin >> N;

    vector<pair<int, int>> coordinates;
    for (size_t i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        coordinates.push_back({x, y});
    }

    size_t biggest_area = 0;

    for (size_t i = 0; i < N; i++) {
        size_t max_base = 0;
        size_t max_height = 0;

        for (size_t j = 0; j < N; j++) {
            if (coordinates[i].first == coordinates[j].first) {
                max_height =
                    max(max_height, (size_t)abs(coordinates[i].second - coordinates[j].second));
            }

            if (coordinates[i].second == coordinates[j].second) {
                max_base = max(max_base, (size_t)abs(coordinates[i].first - coordinates[j].first));
            }
        }

        biggest_area = max(biggest_area, max_base * max_height);
    }

    cout << biggest_area;
}
