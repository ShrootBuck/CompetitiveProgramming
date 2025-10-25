/*
ID: zayd1
LANG: C++
TASK: beads
*/

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
    setIO("beads");

    int N;
    cin >> N;

    string s;
    cin >> s;

    // Double trick
    s += s;

    int max_total = 0;

    for (int i = 0; i <= N - 1; i++) {
        // Count right
        int right_count = 0;
        char anchor = 'w';

        for (int k = 0; k < N; k++) {
            char current = s[i + k];

            if (anchor == 'w' && current != 'w') {
                anchor = current;
            }
            if (current == anchor || current == 'w') {
                right_count++;
            } else {
                break;
            }
        }

        // Count left
        int left_count = 0;
        anchor = 'w';

        for (int k = 0; k < N; k++) {
            char current = s[i + N - k - 1];

            if (anchor == 'w' && current != 'w') {
                anchor = current;
            }
            if (current == anchor || current == 'w') {
                left_count++;
            } else {
                break;
            }
        }

        max_total = max(max_total, min(N, right_count + left_count));
    }

    cout << max_total << endl;
}
