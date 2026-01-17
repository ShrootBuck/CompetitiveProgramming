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

    int N;
    cin >> N;

    string s;
    cin >> s;

    int min_value = 0, max_value = 0;
    int i = 0;

    while (i < N) {

        // Advance b/c F
        if (s[i] == 'F') {
            i++;
            continue;
        }

        int next_i = i + 1;
        while (next_i < N && s[next_i] == 'F') {
            next_i++;
        }

        if (next_i == N) { // Overshot
            break;
        }

        int f_count = next_i - i - 1;

        if (s[next_i] == s[i]) {
            // Case: BFFF...FFFB / EFFF...FFFE

            if (f_count % 2 == 0) {
                min_value++;
            }

            max_value += f_count + 1;
        } else {
            // Case: BFFF...FFFE / EFFF...FFFB

            if (f_count % 2 != 0) {
                min_value++;
            }

            max_value += f_count;
        }

        i = next_i;
    }

    // Special Case: Prefix/Suffix F
    int prefix_f = 0;
    int suffix_f = 0;

    while (prefix_f < N && s[prefix_f] == 'F') {
        prefix_f++;
    }
    while (suffix_f < N && s[N - 1 - suffix_f] == 'F') {
        suffix_f++;
    }

    if (prefix_f == N) {
        // Special Case: Everything is an F
        min_value = 0;
        max_value = N - 1;
    } else {
        max_value += prefix_f + suffix_f;
    }

    vector<int> candidates;

    if (prefix_f == 0 && suffix_f == 0) {
        // Special Case: We can only change in increments of two
        for (int i = min_value; i <= max_value; i += 2) {
            candidates.push_back(i);
        }
    } else {
        for (int i = min_value; i <= max_value; i++) {
            candidates.push_back(i);
        }
    }

    cout << candidates.size() << "\n";

    for (int i : candidates) {
        cout << i << "\n";
    }
}
