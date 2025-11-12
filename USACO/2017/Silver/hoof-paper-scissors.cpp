#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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

int max_wins(vector<int>& top, vector<int>& bottom) {
    int max_top = max(max(top[0], top[1]), top[2]);
    int max_bottom = max(max(bottom[0], bottom[1]), bottom[2]);

    return max_top + max_bottom;
}

int main() {
    setIO("hps");

    int N;
    cin >> N;
    unordered_map<char, int> orders{{'H', 0}, {'P', 1}, {'S', 2}};

    vector<char> gestures;
    vector<int> top(3);
    vector<int> bottom(3);

    // Fill the bottom
    for (int i = 0; i < N; i++) {
        char gesture;
        cin >> gesture;

        gestures.push_back(gesture);
        bottom[orders[gesture]]++;
    }

    int total = 0;

    // From the top now
    for (int i = 0; i < N; i++) {
        bottom[orders[gestures[i]]]--;
        top[orders[gestures[i]]]++;

        total = max(total, max_wins(top, bottom));
    }

    cout << total;
}
