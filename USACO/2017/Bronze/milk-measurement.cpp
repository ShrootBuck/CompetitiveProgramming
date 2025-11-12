#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <utility>
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
    setIO("measurement");

    int N;
    cin >> N;

    map<int, pair<int, int>> history{}; // history[t](cow_id, delta)

    // LCM "hash" trick I learned about in Art of Problem Solving just today!
    unordered_map<int, int> rates{{2, 7}, {3, 7}, {4, 7}};

    int leaderboard = 1;
    int changes = 0;

    for (int i = 0; i < N; i++) {
        int num;
        string cow;
        int change;

        cin >> num >> cow >> change;

        int cow_id;

        if (cow == "Mildred") {
            cow_id = 3;
        } else if (cow == "Bessie") {
            cow_id = 2;
        } else {
            cow_id = 4;
        }

        history[num].first = cow_id;
        history[num].second = change;
    }

    for (auto t : history) {
        rates[t.second.first] += t.second.second;

        int highest_score = 0;
        int local_leader = 1;

        for (auto rate : rates) {
            if (rate.second > highest_score) {
                highest_score = rate.second;
                local_leader = rate.first;
            } else if (rate.second == highest_score) {
                local_leader *= rate.first;
            }
        }

        if (leaderboard != local_leader) {
            changes++;
            leaderboard = local_leader;
        }
    }

    cout << changes;
}
