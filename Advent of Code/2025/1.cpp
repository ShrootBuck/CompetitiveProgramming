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
    setIO("file");

    string move;
    ll dial = 50;
    ll ans = 0;

    vector<pair<char, int>> moves;

    while (cin >> move) {
        moves.push_back({move[0], stoi(move.substr(1))});
    }

    for (auto& move : moves) {
        if (move.first == 'L') {
            dial -= move.second;
        } else if (move.first == 'R') {
            dial += move.second;
        }

        if (abs(dial) % 100 == 0)
            ans++;
    }

    cout << "Part 1:\t" << ans << "\n";

    ans = 0, dial = 50;
    for (auto& move : moves) {
        for (int i = 0; i < move.second; i++) {
            if (move.first == 'L') {
                dial--;
            } else if (move.first == 'R') {
                dial++;
            }

            if (abs(dial) % 100 == 0)
                ans++;
        }
    }

    cout << "Part 2:\t" << ans;
}
