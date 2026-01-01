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

int main() {
    setIO();

    int N, P;
    cin >> N >> P;

    vector<pair<int, int>> p(P);
    for (int i = 0; i < P; i++) {
        cin >> p[i].first >> p[i].second;
    }

    vector<vector<ll>> distance_from_origin(1001, vector<ll>(1001));
    long long current_dist = 0;
    for (int i = 0; i < P; i++) {
        int x1 = p[i].first;
        int y1 = p[i].second;

        int next_i = (i + 1) % P;
        int x2 = p[next_i].first;
        int y2 = p[next_i].second;

        int dx = 0, dy = 0;
        if (x1 < x2)
            dx = 1;
        else if (x1 > x2)
            dx = -1;
        else if (y1 < y2)
            dy = 1;
        else if (y1 > y2)
            dy = -1;
        int curr_x = x1;
        int curr_y = y1;

        while (curr_x != x2 || curr_y != y2) {
            distance_from_origin[curr_x][curr_y] = current_dist;
            current_dist++;
            curr_x += dx;
            curr_y += dy;
        }
    }

    for (int i = 0; i < N; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        long long d1 = distance_from_origin[x1][y1];
        long long d2 = distance_from_origin[x2][y2];

        long long route1 = abs(d1 - d2);
        long long route2 = current_dist - route1;

        cout << min(route1, route2) << "\n";
    }
}
