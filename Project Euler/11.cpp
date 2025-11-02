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

int main() {
    setIO();

    int numbers[20][20];
    ll maximum = 0;

    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++) {
            cin >> numbers[i][j];
        }
    }

    // Horizontal
    for (int r = 0; r < 20; r++) {
        for (int c = 0; c <= 20 - 4; c++) {
            ll local_max = 1;

            for (int i = 0; i < 4; i++) {
                local_max *= numbers[r][c + i];
            }

            maximum = max(maximum, local_max);
        }
    }

    // Vertical
    for (int c = 0; c < 20; c++) {
        for (int r = 0; r <= 20 - 4; r++) {
            ll local_max = 1;

            for (int i = 0; i < 4; i++) {
                local_max *= numbers[r + i][c];
            }

            maximum = max(maximum, local_max);
        }
    }

    // Diagonal down-right
    for (int r = 0; r <= 20 - 4; r++) {
        for (int c = 0; c <= 20 - 4; c++) {
            long long local_max = 1;

            for (int i = 0; i < 4; i++) {
                local_max *= numbers[r + i][c + i];
            }

            maximum = max(maximum, local_max);
        }
    }

    // Diagonal down-left
    for (int r = 0; r <= 20 - 4; r++) {
        for (int c = 3; c < 20; c++) {
            long long local_max = 1;

            for (int i = 0; i < 4; i++) {
                local_max *= numbers[r + i][c - i];
            }

            maximum = max(maximum, local_max);
        }
    }

    cout << maximum;
}
