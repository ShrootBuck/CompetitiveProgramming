#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void setIO(const string& name = "") {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

#ifdef ZK_LOCAL_RUN
    freopen("f.in", "r", stdin);
    freopen("f.out", "w", stdout);
#else
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
#endif
}

vector<bool> visited;
vector<vector<int>> adj;

int dfs(int node) {
    visited[node] = true;
    int total = 1;
    for (int& neighbor : adj[node]) {
        if (!visited[neighbor])
            total += dfs(neighbor);
    }
    return total;
}

struct Cow {
    int x, y, p;
};

int main() {
    setIO("moocast");

    int N;
    cin >> N;
    visited.resize(N);
    adj.resize(N);

    vector<Cow> cows(N);
    for (int i = 0; i < N; i++)
        cin >> cows[i].x >> cows[i].y >> cows[i].p;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                continue;
            int dx = abs(cows[i].x - cows[j].x);
            int dy = abs(cows[i].y - cows[j].y);

            if (dx * dx + dy * dy <= cows[i].p * cows[i].p) {
                adj[i].push_back(j);
            }
        }
    }

    int reach = 0;
    for (int i = 0; i < N; i++) {
        fill(visited.begin(), visited.end(), false);
        reach = max(reach, dfs(i));
    }

    cout << reach;
}
