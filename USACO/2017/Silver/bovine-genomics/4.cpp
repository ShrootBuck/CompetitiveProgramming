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

int char_to_int(char c) {
    if (c == 'A')
        return 0;
    if (c == 'C')
        return 1;
    if (c == 'G')
        return 2;
    return 3; // 'T'
}

int main() {
    setIO("cownomics");

    int N, M;
    cin >> N >> M;

    vector<string> spotted;
    vector<string> plain;

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;

        spotted.push_back(genome);
    }

    for (int i = 0; i < N; i++) {
        string genome;
        cin >> genome;

        plain.push_back(genome);
    }

    int sets = 0;
    bool spotty_combos[64];

    for (int p1 = 0; p1 < M - 2; p1++) {
        for (int p2 = p1 + 1; p2 < M - 1; p2++) {
            for (int p3 = p2 + 1; p3 < M; p3++) {
                // Pre-compute the set of spotted_characters at this (p1, p2, p3)
                fill(spotty_combos, spotty_combos + 64, false);

                for (int i = 0; i < N; i++) {
                    char c1 = spotted[i][p1];
                    char c2 = spotted[i][p2];
                    char c3 = spotted[i][p3];

                    int hash = char_to_int(c1) * 16 + char_to_int(c2) * 4 + char_to_int(c3);
                    spotty_combos[hash] = true;
                }

                bool valid = true;

                for (int i = 0; i < N; i++) {
                    char c1 = plain[i][p1];
                    char c2 = plain[i][p2];
                    char c3 = plain[i][p3];

                    int hash = char_to_int(c1) * 16 + char_to_int(c2) * 4 + char_to_int(c3);
                    if (spotty_combos[hash]) {
                        valid = false;
                        break;
                    }
                }

                if (valid) {
                    sets++;
                }
            }
        }
    }

    cout << sets;
}
