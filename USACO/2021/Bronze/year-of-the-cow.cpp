#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <unordered_map>
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
    setIO();

    unordered_map<string, int> ox_offset{{"Ox", 0},      {"Tiger", 1}, {"Rabbit", 2}, {"Dragon", 3},
                                         {"Snake", 4},   {"Horse", 5}, {"Goat", 6},   {"Monkey", 7},
                                         {"Rooster", 8}, {"Dog", 9},   {"Pig", 10},   {"Rat", 11}};
    unordered_map<string, int> pos{{"Bessie", 0}};
    unordered_map<string, string> animals{{"Bessie", "Ox"}};

    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        string cow1, cow2, animal, direction, temp;
        cin >> cow1 >> temp >> temp >> direction >> animal >> temp >> temp >> cow2;
        animals[cow1] = animal;

        int offset = ox_offset[animal] - ox_offset[animals[cow2]];

        if (direction == "previous") {
            if (offset >= 0) {
                offset -= 12;
            }
        } else {
            if (offset <= 0) {
                offset += 12;
            }
        }

        pos[cow1] = pos[cow2] + offset;
    }

    cout << abs(pos["Bessie"] - pos["Elsie"]);
}
