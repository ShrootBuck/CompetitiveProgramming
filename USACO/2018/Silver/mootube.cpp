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

vector<vector<pair<ll, ll>>> graph;

void dfs(ll start, ll k, vector<bool>& visited, ll& counter) {
    visited[start] = true;

    for (auto& neighbor : graph[start]) {
        if (neighbor.second >= k && !visited[neighbor.first]) {
            dfs(neighbor.first, k, visited, ++counter);
        }
    }
}

int main() {
    setIO("mootube");

    ll N, Q;
    cin >> N >> Q;
    graph.resize(N);

    for (ll i = 0; i < N - 1; i++) {
        ll p, q, r;
        cin >> p >> q >> r;
        p--, q--;

        graph[p].emplace_back(q, r);
        graph[q].emplace_back(p, r);
    }

    for (ll i = 0; i < Q; i++) {
        ll k, v, counter = 0;
        cin >> k >> v;
        v--;

        vector<bool> visited(N, false);
        dfs(v, k, visited, counter);
        cout << counter << "\n";
    }
}
