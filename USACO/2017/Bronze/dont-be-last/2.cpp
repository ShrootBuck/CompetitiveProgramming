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

    vector<pair<int, string>> sorted_cows;

    for (const auto& pair : leaderboard) {
        sorted_cows.push_back({pair.second, pair.first});
    }

    sort(sorted_cows.begin(), sorted_cows.end());

    int min_milk = sorted_cows[0].first;
    int second_min_i = -1;

    for (int i = 1; i < sorted_cows.size(); i++) {
        if (sorted_cows[i].first != min_milk) {
            second_min_i = i;
            break;
        }
    }

    if (second_min_i == -1) {
        cout << "Tie";
    } else if (second_min_i + 1 < sorted_cows.size() &&
               sorted_cows[second_min_i].first == sorted_cows[second_min_i + 1].first) {
        cout << "Tie";
    } else {
        cout << sorted_cows[second_min_i].second;
    }
}
