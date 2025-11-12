#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
vector<int> X, Y;
vector<int> partner;
vector<int> next_on_right;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

bool cycle_exists() {
    for (int i = 0; i < N; ++i) {
        int pos = i;

        for (int step = 0; step < N; ++step) {
            pos = next_on_right[partner[pos]];
            if (pos == -1) {
                break;
            }
        }
        if (pos != -1) {
            // Must be a cycle
            return true;
        }
    }

    // None create a cycle
    return false;
}

int solve() {
    int i = -1;
    for (int j = 0; j < N; ++j) {
        if (partner[j] == -1) {
            i = j;
            break;
        }
    }

    if (i == -1) {
        if (cycle_exists()) {
            return 1;
        }
        return 0;
    }

    int total_count = 0;
    // Try pairing wormhole i with every subsequent unpaired wormhole j
    for (int j = i + 1; j < N; ++j) {
        if (partner[j] == -1) {
            partner[i] = j;
            partner[j] = i;
            total_count += solve(); // Recurse and add all in one
            partner[i] = partner[j] = -1;
        }
    }
    return total_count;
}

int main() {
    setIO("wormhole");
    cin >> N;
    X.resize(N);
    Y.resize(N);
    partner.resize(N, -1);
    next_on_right.resize(N, -1);

    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }

    // Pre-compute the next wormhole to the right for each wormhole
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (X[j] > X[i] && Y[j] == Y[i]) {
                if (next_on_right[i] == -1 || X[j] < X[next_on_right[i]]) {
                    next_on_right[i] = j;
                }
            }
        }
    }

    cout << solve();

    return 0;
}
