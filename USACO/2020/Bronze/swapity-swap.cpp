#include <cstdio>
#include <iostream>
#include <numeric>
#include <string>
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

int main() {
    setIO("swap");

    int N, K, A1, A2, B1, B2;
    cin >> N >> K >> A1 >> A2 >> B1 >> B2;
    A1--, A2--, B1--, B2--;

    vector<int> arr(N);
    iota(arr.begin(), arr.end(), 1);

    vector<int> destination(N);

    for (int i = 0; i < N; i++) {
        int pos = i;

        if (pos >= A1 && pos <= A2) {
            pos = A1 + A2 - pos;
        }

        if (pos >= B1 && pos <= B2) {
            pos = B1 + B2 - pos;
        }

        destination[i] = pos;
    }

    vector<int> final_pos(N);
    vector<bool> visited(N);

    for (int i = 0; i < N; i++) {
        if (visited[i]) {
            continue;
        }

        // Build the cycle starting from i
        vector<int> cycle;
        int current = i;

        while (!visited[current]) {
            visited[current] = true;
            cycle.push_back(current);
            current = destination[current];
        }

        int shift = K % cycle.size();

        for (int j = 0; j < cycle.size(); j++) {
            int from = cycle[j];
            final_pos[from] = cycle[(j + shift) % cycle.size()];
        }
    }

    vector<int> results(N);
    for (int i = 0; i < N; i++) {
        results[final_pos[i]] = arr[i];
    }

    for (int& result : results) {
        cout << result << "\n";
    }
}
