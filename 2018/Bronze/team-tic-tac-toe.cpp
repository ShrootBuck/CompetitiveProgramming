#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  if (!name.empty()) {
    freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
  }
}

array<unordered_map<char, bool>, 26> team_winners{};
array<bool, 26> solo_winners{};

void compute_solutions(char cow1, char cow2, char cow3) {
  //   cout << cow1 << " " << cow2 << " " << cow3 << "\n";
  if ((cow1 == cow2) && (cow2 == cow3)) {
    solo_winners[cow1 - 'A'] = true;
    return;
  }

  if ((cow1 == cow2) || (cow1 == cow3) || (cow2 == cow3)) {
    int smaller_char = min(min(cow1, cow2), cow3);
    int larger_char = max(max(cow1, cow2), cow3);
    team_winners[larger_char - 'A'][smaller_char] = true;
  }
}

int main() {
  setIO("tttt");

  array<array<char, 3>, 3> board; // Row[column]

  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> board[i][j];
    }

    // In this loop we can check the rows
    compute_solutions(board[i][0], board[i][1], board[i][2]);
  }

  // Check columns
  for (int i = 0; i < 3; i++) {
    compute_solutions(board[0][i], board[1][i], board[2][i]);
  }

  // Diagonals
  compute_solutions(board[0][0], board[1][1], board[2][2]);
  compute_solutions(board[0][2], board[1][1], board[2][0]);

  int solo = 0;
  int team = 0;
  for (bool winner : solo_winners) {
    if (winner) {
      solo++;
    }
  }

  for (auto larger_char : team_winners) {
    team += larger_char.size();
  }

  cout << solo << "\n" << team;
}
