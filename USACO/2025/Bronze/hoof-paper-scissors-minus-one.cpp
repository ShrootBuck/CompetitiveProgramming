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
    setIO();

    int N, M;
    cin >> N >> M;

    vector<string> information(N);
    for (int i = 0; i < N; i++) {
        cin >> information[i];
    }

    vector<vector<bool>> beats(N, vector<bool>(N));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < i; j++) {
            if (information[i][j] == 'W') {
                beats[i][j] = true;
            } else if (information[i][j] == 'L') {
                beats[j][i] = true;
            }
        }
    }

    for (int i = 0; i < M; i++) {
        int n1, n2;
        cin >> n1 >> n2;

        // Numbers are given 1-indexed
        n1--;
        n2--;

        int right_hand_winners = 0;
        int answers = 0;

        for (int second = 0; second < N; second++) {
            right_hand_winners += (beats[second][n1] && beats[second][n2]);
        }

        for (int first = 0; first < N; first++) {
            if (beats[first][n1] && beats[first][n2]) {
                // case 1 is first hand beats both elsie hands
                answers += N;
            } else {
                // case 2 means right hand has to beat both
                answers += right_hand_winners;
            }
        }

        cout << answers << "\n";
    }
}
