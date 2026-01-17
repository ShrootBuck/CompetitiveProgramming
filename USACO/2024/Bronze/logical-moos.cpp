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

    int N, Q;
    cin >> N >> Q;

    vector<string> statement(N);
    vector<int> group_id(N), first_false_in_group(N, INT_MAX), last_false_in_group(N, -1);
    int first_true_group = INT_MAX, last_true_group = -1;
    int current_group = 0;

    for (int i = 0, running_eval = true; i < N; i++) {
        cin >> statement[i];

        group_id[i] = current_group;

        if (statement[i] == "or") {
            running_eval = true;
            current_group++;
        } else if (statement[i] == "false") {
            running_eval = false;
            first_false_in_group[current_group] = min(first_false_in_group[current_group], i);
            last_false_in_group[current_group] = i;
        }
    }
    for (int i = 0; i <= current_group; i++) {
        if (first_false_in_group[i] == INT_MAX) {
            first_true_group = min(first_true_group, i);
            last_true_group = i;
        }
    }

    for (int q = 0; q < Q; q++) {
        int l, r;
        string s;

        cin >> l >> r >> s;
        l--, r--;

        int g_start = group_id[l];
        int g_end = group_id[r];

        if (last_true_group > g_end || first_true_group < g_start) {
            cout << (s == "true" ? "Y" : "N");
        } else {
            if (s == "false") {
                cout << "Y";
                continue;
            } else {
                if (first_false_in_group[g_start] < l || last_false_in_group[g_end] > r) {
                    cout << "N";
                    continue;
                } else {
                    cout << "Y";
                    continue;
                }
            }
        }
    }
}
