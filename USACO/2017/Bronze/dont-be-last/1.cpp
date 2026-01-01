#include <bits/stdc++.h>

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
    setIO("notlast");

    int N;
    cin >> N;

    unordered_map<string, int> leaderboard{
        {"Bessie", 0},    {"Elsie", 0},  {"Daisy", 0},     {"Gertie", 0},
        {"Annabelle", 0}, {"Maggie", 0}, {"Henrietta", 0},
    };

    for (int i = 0; i < N; i++) {
        string cow;
        int milk;

        cin >> cow >> milk;

        leaderboard[cow] += milk;
    }

    // Get a global min
    int M = 100 * 100 + 1;

    for (auto cow : leaderboard) {
        M = min(M, cow.second);
    }

    // Get second min
    int M2 = 100 * 100 + 1;
    int all_min = true;

    for (auto cow : leaderboard) {
        if (cow.second != M) {
            M2 = min(M2, cow.second);
            all_min = false;
        }
    }

    if (all_min) {
        cout << "Tie";
        return 0;
    }

    int with_M2 = 0;
    string cow_M2;

    for (auto cow : leaderboard) {
        if (cow.second == M2) {
            with_M2++;
            cow_M2 = cow.first;
        }
    }

    if (with_M2 > 1) {
        cout << "Tie";
    } else {
        cout << cow_M2;
    }
}
