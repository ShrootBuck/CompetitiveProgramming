#include <cstdio>
#include <iostream>
#include <string>
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

int grid[2002][2002], ones_prefix[2002][2002];

int main() {
    setIO();

    int N;
    cin >> N;

    const int MAX_N = 2e5;
    int U[MAX_N], D[MAX_N], L[MAX_N], R[MAX_N];

    for (int i = 0; i < N; i++) {
        cin >> U[i] >> D[i] >> L[i] >> R[i];
        grid[U[i]][L[i]]++;
        grid[U[i]][R[i] + 1]--;
        grid[D[i] + 1][L[i]]--;
        grid[D[i] + 1][R[i] + 1]++;
    }

    // Squeegee across
    for (int r = 0; r < 2002; r++) {
        for (int c = 1; c < 2002; c++) {
            grid[r][c] += grid[r][c - 1];
        }
    }

    // Squeegee down
    for (int c = 0; c < 2002; c++) {
        for (int r = 1; r < 2002; r++) {
            grid[r][c] += grid[r - 1][c];
        }
    }

    int empty_cells = 0;
    for (int r = 1; r <= 2000; r++) {
        for (int c = 1; c <= 2000; c++) {
            empty_cells += grid[r][c] == 0;

            int current = (grid[r][c] == 1 ? 1 : 0);

            ones_prefix[r][c] =
                current + ones_prefix[r - 1][c] + ones_prefix[r][c - 1] - ones_prefix[r - 1][c - 1];
        }
    }

    for (int i = 0; i < N; i++) {
        // Boundaries of the current cloud
        int u = U[i], d = D[i], l = L[i], r = R[i];

        int freed_up = ones_prefix[d][r] - ones_prefix[d][l - 1] - ones_prefix[u - 1][r] +
                       ones_prefix[u - 1][l - 1];
        cout << empty_cells + freed_up << "\n";
    }
}
