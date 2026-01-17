#include <bits/stdc++.h>
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
    setIO("revegetate");

    int N, M;
    cin >> N >> M;

    vector<vector<int>> adjacency(N);

    for (int i = 0; i < M; i++) {
        int u, v; // Why is this the convention? Integration by parts ahh
        cin >> u >> v;
        u--, v--;
        adjacency[u].push_back(v);
        adjacency[v].push_back(u);
    }

    vector<set<int>> avoid(N);

    for (int i = 0; i < N; i++) {
        int lowest;
        for (int j = 0; j <= 3; j++) {
            if (avoid[i].count(j) == 0) {
                lowest = j;
                break;
            }
        }

        cout << lowest + 1;

        for (int j = 0; j < adjacency[i].size(); j++) {
            avoid[adjacency[i][j]].insert(lowest);
        }
    }
}
