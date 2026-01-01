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

int main() {
    setIO("bcs");

    int N, K;
    cin >> N >> K;

    vector<vector<bool>> model;          // true means "activated" (this tile is glass)
    vector<vector<vector<bool>>> shards; // true means "activated" (this tile is glass)

    // Read in the model cow
    for (int i = 0; i < N; ++i) {
        model.push_back({});

        for (int j = 0; j < N; ++j) {
            char piece;
            cin >> piece;

            model[i].push_back(piece == '#');
        }
    }

    // Read in the shards
    for (int k = 0; k < K; k++) {
        shards.push_back({});

        for (int i = 0; i < N; ++i) {
            shards[k].push_back({});

            for (int j = 0; j < N; ++j) {
                char piece;
                cin >> piece;

                shards[k][i].push_back(piece == '#');
            }
        }
    }

    // We need a unique pair of (k1, k2) shards
    for (int i = 0; i < K - 1; i++) {
        for (int j = i + 1; j < K; j++) {
            for (int dy1 = -N + 1; dy1 < N; dy1++) {
                for (int dx1 = -N + 1; dx1 < N; dx1++) {
                    for (int dy2 = -N + 1; dy2 < N; dy2++) {
                        for (int dx2 = -N + 1; dx2 < N; dx2++) {
                            // Paint the new canvas
                            vector<vector<bool>> canvas(N, vector<bool>(N, false));

                            for (int r = 0; r < N; r++) {
                                for (int c = 0; c < N; c++) {
                                    int new_r, new_c;
                                    new_r = r + dy1;
                                    new_c = c + dx1;

                                    if (shards[i][r][c]) {
                                        if ((new_r < 0 || new_r >= N) ||
                                            (new_c < 0 || new_c >= N)) {
                                            goto next_scenario;
                                        }
                                        canvas[new_r][new_c] = true;
                                    }
                                }
                            }

                            for (int r = 0; r < N; r++) {
                                for (int c = 0; c < N; c++) {
                                    int new_r, new_c;
                                    new_r = r + dy2;
                                    new_c = c + dx2;

                                    if (shards[j][r][c]) {
                                        if ((new_r < 0 || new_r >= N) ||
                                            (new_c < 0 || new_c >= N)) {
                                            goto next_scenario;
                                        }

                                        if (canvas[new_r][new_c]) {
                                            goto next_scenario;
                                        } else {
                                            canvas[new_r][new_c] = true;
                                        }
                                    }
                                }
                            }

                            if (canvas == model) {
                                cout << i + 1 << " " << j + 1 << endl;
                                return 0;
                            }

                        next_scenario:;
                        }
                    }
                }
            }
        }
    }
}
