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

int dfs(int node, vector<set<int>>& adj, vector<bool>& visited) {
    int total = 1;
    visited[node] = true;
    for (auto& connection : adj[node]) {
        if (!visited[connection])
            total += dfs(connection, adj, visited);
    }

    return total;
}

int main() {
    setIO("closing");

    int N, M;
    cin >> N >> M;
    vector<set<int>> adj(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        adj[a].insert(b);
        adj[b].insert(a);
    }

    vector<int> closing_order(N);
    int last_closed, barns_left = N;
    for (int i = 0; i < N; i++) {
        cin >> closing_order[i];
        closing_order[i]--;
        last_closed = closing_order[i];
    }

    for (int& barn : closing_order) {
        vector<bool> visited(N, false);
        cout << (dfs(last_closed, adj, visited) == barns_left ? "YES" : "NO") << '\n';

        for (int connection : adj[barn]) {
            adj[connection].erase(barn);
        }
        adj[barn].clear();
        barns_left--;
    }
}
