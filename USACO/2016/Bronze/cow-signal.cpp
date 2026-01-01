#include <bits/stdc++.h>

using namespace std;

int main() {

    freopen("cowsignal.in", "r", stdin);
    freopen("cowsignal.out", "w", stdout);

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N, K;
    cin >> M >> N >> K;

    for (int i = 0; i < M; i++) {
        // Create the new line
        string new_line = "";
        string smaller_line;
        cin >> smaller_line;

        for (int j = 0; j < K; j++) {
            for (char character : smaller_line) {
                for (int k = 0; k < K; k++) {
                    cout << character;
                }
            }

            cout << "\n";
        }
    }
}
