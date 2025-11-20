#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
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

    int N;
    cin >> N;

    int biggest_area = 0;

    vector<pair<int, int>> coordinates;
    unordered_map<int, vector<size_t>> unique_x;

    for (size_t i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;

        coordinates.push_back({x, y});
        unique_x[x].push_back(i);
    }

    for (pair<int, vector<size_t>> c : unique_x) {
        if (c.second.size() < 2) {
            continue;
        }

        for (size_t i = 0; i < c.second.size() - 1; i++) {
            for (size_t j = i + 1; j < c.second.size(); j++) {
                pair<int, int> c1 = coordinates[c.second[i]];
                pair<int, int> c2 = coordinates[c.second[j]];
                int y_height = abs(c1.second - c2.second);

                for (size_t k = 0; k < coordinates.size(); k++) {

                    if (k == c.second[i] || k == c.second[j]) {
                        continue;
                    }

                    pair<int, int> c3 = coordinates[k];

                    int x_length = 0;
                    if (c3.second == c1.second) {
                        x_length = abs(c3.first - c1.first);

                    } else if (c3.second == c2.second) {
                        x_length = abs(c3.first - c2.first);
                    } else {
                        continue;
                    }

                    biggest_area = max(biggest_area, y_height * x_length);
                }
            }
        }
    }

    cout << biggest_area;
}
