#include <bits/stdc++.h>
using namespace std;

int main() {
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int max_correct = 0;
  size_t N;

  cin >> N;

  // Reading the input in
  vector<array<size_t, 3>> guesses(N);

  for (size_t i = 0; i < N; i++) {
    cin >> guesses[i][0];
    cin >> guesses[i][1];
    cin >> guesses[i][2];
  }

  for (size_t possible_index = 0; possible_index < 3; possible_index++) {
    array<size_t, 3> shells{0, 0, 0};

    shells[possible_index] = 1;
    int correct_guesses = 0;

    for (size_t i = 0; i < N; i++) {
      size_t swap1 = guesses[i][0];
      size_t swap2 = guesses[i][1];
      size_t guess = guesses[i][2];

      size_t temp = shells[swap1 - 1];

      shells[swap1 - 1] = shells[swap2 - 1];
      shells[swap2 - 1] = temp;

      if (shells[guess - 1] == 1) {
        correct_guesses++;
      }
    }

    max_correct = max(max_correct, correct_guesses);
  }

  cout << max_correct;
}
