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

struct Event {
    int x, y, t;
};

int main() {
    setIO();

    int G, N;
    cin >> G >> N;

    vector<Event> grazings(G);
    vector<int> grazing_times(G);
    for (int i = 0; i < G; i++) {
        cin >> grazings[i].x >> grazings[i].y >> grazings[i].t;
    }
    sort(grazings.begin(), grazings.end(), [&](auto& g1, auto& g2) { return g1.t < g2.t; });
    for (int i = 0; i < G; i++)
        grazing_times[i] = grazings[i].t;

    vector<Event> alibis(N);
    for (int i = 0; i < N; i++)
        cin >> alibis[i].x >> alibis[i].y >> alibis[i].t;

    int cleared_cows = 0;
    for (int i = 0; i < N; i++) {
        auto it = upper_bound(grazing_times.begin(), grazing_times.end(), alibis[i].t);

        bool cleared = false;

        // Check previous grazing
        if (it != grazing_times.begin()) {
            auto left_grazing = prev(it);
            int left_i = left_grazing - grazing_times.begin();
            ll dt = alibis[i].t - grazings[left_i].t;
            ll dx = alibis[i].x - grazings[left_i].x;
            ll dy = alibis[i].y - grazings[left_i].y;

            if (dt * dt < dx * dx + dy * dy)
                cleared = true;
        }

        // Check next grazing
        if (it != grazing_times.end()) {
            int right_i = it - grazing_times.begin();
            ll dt = grazings[right_i].t - alibis[i].t;
            ll dx = grazings[right_i].x - alibis[i].x;
            ll dy = grazings[right_i].y - alibis[i].y;

            if (dt * dt < dx * dx + dy * dy)
                cleared = true;
        }

        cleared_cows += cleared;
    }

    cout << cleared_cows;
}
