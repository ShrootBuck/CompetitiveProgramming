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

int N, M, K;

bool check_valid(vector<int> hierarchy, vector<int> fixed) {
    vector<int> c_to_p(N, -1);

    // Populate conversion chart
    for (int i = 0; i < N; i++) {
        if (fixed[i] != -1) {
            c_to_p[fixed[i]] = i;
        }
    }

    int h_i = 0;
    for (int i = 0; i < N && h_i < M; i++) {
        if (c_to_p[hierarchy[h_i]] != -1) {

            // VIP spot was filled! (by non-VIP)
            if (i > c_to_p[hierarchy[h_i]]) {
                return false;
            }

            i = c_to_p[hierarchy[h_i]];

        } else {
            while (i < N && fixed[i] != -1) {
                i++;
            }

            if (i == N) {
                return false;
            }

            fixed[i] = hierarchy[h_i];
            c_to_p[hierarchy[h_i]] = i;
        }

        h_i++;
    }

    return h_i == M;
}

int main() {
    setIO("milkorder");

    cin >> N >> M >> K;

    vector<int> hierarchy(M);
    vector<int> fixed(N, -1);

    for (int i = 0; i < M; i++) {
        cin >> hierarchy[i];
        hierarchy[i]--;
    }

    for (int i = 0; i < K; i++) {
        int c, p;
        cin >> c >> p;

        fixed[p - 1] = --c;

        if (c == 0) {
            cout << p;
            return 0;
        }
    }

    for (int i = 0; i < N; i++) {
        if (fixed[i] == -1) {
            // Place Cow 1
            fixed[i] = 0;

            if (check_valid(hierarchy, fixed)) {
                cout << i + 1;
                return 0;
            }

            // Unplace
            fixed[i] = -1;
        }
    }
}
