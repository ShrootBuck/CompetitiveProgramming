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

    int N;
    cin >> N;

    unordered_map<char, pair<int, int>> bounds{{'G', {INT_MAX, INT_MIN}},
                                               {'H', {INT_MAX, INT_MIN}}};

    string s;
    cin >> s;

    for (int i = 0; i < N; i++) {
        auto& c = s[i];

        bounds[c].first = min(bounds[c].first, i);
        bounds[c].second = max(bounds[c].second, i);
    }

    vector<int> E(N);

    for (int i = 0; i < N; i++) {
        cin >> E[i];
        E[i]--; // input is given in 1-index
    }

    // Identify the "main leader" candidates
    int g_main_leader = -1;
    if (E[bounds['G'].first] >= bounds['G'].second) {
        g_main_leader = bounds['G'].first;
    }

    int h_main_leader = -1;
    if (E[bounds['H'].first] >= bounds['H'].second) {
        h_main_leader = bounds['H'].first;
    }

    ll pairs = 0;

    // Case 1: the G cow is the main leader and we need to find H cows before it
    // that contain it
    if (g_main_leader != -1) {
        for (int i = 0; i < g_main_leader; i++) {
            if (s[i] == 'H' && E[i] >= g_main_leader) {
                pairs++;
            } else if (i == h_main_leader) {
                pairs++;
            }
        }
    }

    // Case 2: vice-versa of above
    if (h_main_leader != -1) {
        for (int i = 0; i < h_main_leader; ++i) {
            if (s[i] == 'G' && E[i] >= h_main_leader) {
                pairs++;
            } else if (i == g_main_leader) {
                pairs++;
            }
        }
    }

    cout << pairs;
}
