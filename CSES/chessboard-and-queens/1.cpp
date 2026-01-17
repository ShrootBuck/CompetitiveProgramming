#include <bits/stdc++.h>
using namespace std;

vector<int> current;

bool col_taken[8] = {false};
bool diag1_taken[15] = {false};
bool diag2_taken[15] = {false};
char board[8][8];
int mycount = 0;

void search(int r) { // r for row
    if (r == 8) {
        mycount++; // Found a valid placement
        return;
    }

    for (int c = 0; c < 8; ++c) {
        // THIS IS THE SPOT
        // 1. Check if board[r][c] is a '*'
        // 2. Check if col c is already taken
        // 3. Check if the two diagonals for (r, c) are taken
        if (board[r][c] == '.' && !diag1_taken[r + c] && !diag2_taken[r - c + 7] && !col_taken[c]) {
            col_taken[c] = true;
            diag1_taken[r + c] = true;
            diag2_taken[r - c + 7] = true;

            search(r + 1); // Recurse to the next row

            // BACKTRACK!
            col_taken[c] = false;
            diag1_taken[r + c] = false;
            diag2_taken[r - c + 7] = false;
        }
    }
}

int main() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cin >> board[i][j];
        }
    }

    search(0);

    cout << mycount;
}
