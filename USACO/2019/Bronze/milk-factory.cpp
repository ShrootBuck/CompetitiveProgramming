#include <cstdio>
#include <iostream>
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
    setIO("factory");

    int N;
    cin >> N;

    vector<int> outdegree(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;

        outdegree[a]++;
    }

    int candidate = -1;
    for (int i = 0; i < N; i++) {
        if (outdegree[i] == 0) {
            if (candidate != -1) {
                // More than one node with outdegree 0
                cout << -1;
                return 0;
            }

            candidate = i;
        }
    }

    if (candidate == -1) {
        cout << -1;
    } else {
        cout << candidate + 1;
    }
}
