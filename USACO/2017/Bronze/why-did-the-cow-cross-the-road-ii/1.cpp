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
    setIO("circlecross");

    string input;
    cin >> input;
    map<char, pair<int, int>> cow_indices;
    unordered_map<char, int> first_position;

    // Load in the cow indices
    for (int i = 0; i < input.length(); i++) {
        char cow = input[i];

        if (first_position.count(cow)) {
            cow_indices[cow] = {first_position[cow], i};
        } else {
            first_position[cow] = i;
        }
    }

    unordered_map<int, unordered_map<int, bool>> crossings;
    int total = 0;

    for (int i = 0; i < 26; i++) {
        char current_cow = 'A' + i;
        int overlap = 0;
        unordered_map<char, bool> unfolded{};

        for (int j = cow_indices[current_cow].first + 1; j < cow_indices[current_cow].second; j++) {
            if (unfolded[input[j]]) {
                overlap--;
                // We could clean it from unfolded here but not really necessary
            } else {
                unfolded[input[j]] = true;
                overlap++;
            }
        }

        total += overlap;
    }

    cout << total / 2;
}
