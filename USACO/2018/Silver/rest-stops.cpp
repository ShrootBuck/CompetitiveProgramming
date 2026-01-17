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
    setIO("reststops");

    int L, N, RF, RB;
    cin >> L >> N >> RF >> RB;

    vector<pair<int, int>> stops(N);

    for (int i = 0; i < N; i++) {
        cin >> stops[i].first >> stops[i].second;
    }

    vector<pair<int, int>> stop_at;
    int greatest_c = 0;
    for (int i = N - 1; i >= 0; i--) {
        if (stops[i].second > greatest_c) {
            greatest_c = stops[i].second;
            stop_at.push_back(stops[i]);
        }
    }

    sort(stop_at.begin(), stop_at.end());

    ll tastiness = 0;
    int pos = 0;

    for (auto& stop : stop_at) {
        int dist = stop.first - pos;

        tastiness += (ll)(RF - RB) * dist * stop.second;

        pos = stop.first;
    }

    cout << tastiness;
}
