#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("speeding.in", "r", stdin);
    freopen("speeding.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;
    int max_infraction = 0;

    vector<array<int, 2>> road_segments(N);
    vector<int> limit_per_mile(100);

    int current_mile = 0;
    for (int i = 0; i < N; i++) {
        int length, speed_limit;
        cin >> length >> speed_limit;

        for (int j = 0; j < length; j++) {
            limit_per_mile[current_mile + j] = speed_limit;
        }

        current_mile += length;
    }

    current_mile = 0;

    for (int i = 0; i < M; i++) {
        int length, speed;
        cin >> length >> speed;

        for (int j = 0; j < length; j++) {
            max_infraction = max(max_infraction, speed - limit_per_mile[current_mile + j]);
        }

        current_mile += length;
    }

    cout << max_infraction;
};
