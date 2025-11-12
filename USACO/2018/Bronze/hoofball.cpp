#include <algorithm>
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
    setIO("hoofball");

    int N;
    cin >> N;

    vector<int> x(N);

    for (int i = 0; i < N; i++) {
        cin >> x[i];
    }

    sort(x.begin(), x.end());

    vector<int> to(N), indegree(N, 0);

    for (int i = 0; i < N; i++) {
        if (i == 0) {
            to[i] = i + 1;
        } else if (i == N - 1) {
            to[i] = i - 1;
        } else {
            int left_distance = x[i] - x[i - 1];
            int right_distance = x[i + 1] - x[i];
            to[i] = left_distance <= right_distance ? i - 1 : i + 1;
        }

        indegree[to[i]]++;
    }

    int ans = 0;

    // First part of answer is simply indegree=0 cows
    for (int &in : indegree) {
        ans += in == 0;
    }

    // Second part is # of isolated cycles

    for (int i = 0; i < N - 1; i++) {
        if (to[i] == i + 1 && to[i + 1] == i && indegree[i] == 1 &&
            indegree[i + 1] == 1) {
            ans++;
        }
    }

    cout << ans;
}
