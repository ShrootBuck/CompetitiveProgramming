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
    setIO("lineup");

    int N;
    cin >> N;

    vector<string> cows{"Buttercup", "Sue",    "Beatrice", "Bella",
                        "Blue",      "Bessie", "Belinda",  "Betsy"};
    sort(cows.begin(), cows.end());

    unordered_map<string, int> id;
    for (int i = 0; i < cows.size(); i++) {
        id[cows[i]] = i;
    }

    vector<vector<int>> adjacency(8);

    for (int i = 0; i < N; i++) {
        string c1, c2, temp;
        cin >> c1 >> temp >> temp >> temp >> temp >> c2;
        adjacency[id[c1]].push_back(id[c2]);
        adjacency[id[c2]].push_back(id[c1]);
    }

    vector<int> order;
    vector<bool> visited(8);

    for (int i = 0; i < 8; i++) {
        if (visited[i]) {
            continue;
        }

        int degree = adjacency[i].size();

        if (degree == 0) {
            // Completely unconstrained cow, alone component
            order.push_back(i);
            visited[i] = true;
        } else if (degree == 1) {
            // Endpoint of a path, walk this whole component
            int current = i;
            int previous = -1;

            while (current != -1) {
                order.push_back(current);
                visited[current] = true;

                int next = -1;
                for (int neighbor : adjacency[current]) {
                    if (neighbor != previous && !visited[neighbor]) {
                        next = neighbor;
                        break;
                    }
                }

                previous = current;
                current = next;
            }
        }
    }

    for (int i : order) {
        cout << cows[i] << "\n";
    }
}
