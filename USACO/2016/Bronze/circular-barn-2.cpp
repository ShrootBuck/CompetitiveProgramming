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

    int cows = 0;

    vector<int> capacities(N);

    long long current_steps = 0;
    long long initial_steps = 0;
    long long min_steps = LLONG_MAX;

    for (int i = 0; i < N; i++) {
        cin >> capacities[i];
        cows += capacities[i];

        current_steps += i * capacities[i];
        initial_steps = current_steps;
    }

    min_steps = min(min_steps, current_steps);

    for (int i = 1; i < N; i++) {
        current_steps = initial_steps - cows + N * capacities[i - 1];

        min_steps = min(min_steps, current_steps);
        initial_steps = current_steps;
    }

    cout << min_steps;
}
