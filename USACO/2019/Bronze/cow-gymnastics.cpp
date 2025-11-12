#include <cstdio>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
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

    setIO("gymnastics");

    size_t K, N;
    cin >> K >> N;

    size_t consistent = 0;

    unordered_map<int, unordered_map<int, int>> scores{}; // Track in winner[loser] = count format
    vector<vector<int>> matches(K, vector<int>(N));

    for (size_t i = 0; i < K; i++) {
        for (size_t j = 0; j < N; j++) {
            cin >> matches[i][j];
        }
    }

    for (vector<int> match : matches) {
        for (size_t i = 0; i < N - 1; i++) {
            for (size_t j = i + 1; j < N; j++) {
                scores[match[i]][match[j]]++;
            }
        }
    }

    for (size_t i = 1; i < N; i++) {
        for (size_t j = i + 1; j <= N; j++) {
            if ((scores[i][j] == 0) || (scores[j][i] == 0)) {
                consistent++;
            }
        }
    }

    cout << consistent;
}
