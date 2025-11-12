#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
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
    setIO("cbarn");

    int N;
    cin >> N;

    vector<int> capacities(N);

    for (int i = 0; i < N; i++) {
        cin >> capacities[i];
    }

    long long min_steps = LLONG_MAX;

    for (int i = 0; i < N; i++) {

        long long current_steps = 0;

        for (int j = 0; j < N; j++) {
            current_steps += capacities[(j + i) % N] * j;
        }

        min_steps = min(min_steps, current_steps);
    }

    cout << min_steps;
}
