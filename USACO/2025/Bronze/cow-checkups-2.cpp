#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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
    setIO();

    int N;
    cin >> N;

    vector<int> a;
    vector<int> b;
    vector<int> c(N + 1, 0);

    for (int i = 0; i < N; ++i) {
        int temp_a;
        cin >> temp_a;

        a.push_back(temp_a);
    }

    for (int i = 0; i < N; ++i) {
        int temp_b;
        cin >> temp_b;

        b.push_back(temp_b);
    }

    // After a and b are filled
    vector<int> prefix_ok(N + 1, 0);
    for (int i = 0; i < N; i++) {
        prefix_ok[i + 1] = prefix_ok[i] + (a[i] == b[i]);
    }

    vector<int> suffix_ok(N + 1, 0);
    for (int i = N - 1; i >= 0; i--) {
        suffix_ok[i] = suffix_ok[i + 1] + (a[i] == b[i]);
    }

    for (int s = 0; s <= 2 * N - 2; ++s) {
        vector<int> matching_indices;
        int i_start = max(0, s - N + 1);
        int i_end = min(s, N - 1);

        for (int i = i_start; i <= i_end; ++i) {
            if (a[s - i] == b[i]) {
                matching_indices.push_back(i);
            }
        }

        // Check how many indices in matching_incices are within (l, r)
        int l_start = max(0, s - (N - 1));
        int l_end = min(s / 2, N - 1);
        for (int l = l_start; l <= l_end; ++l) {
            int r = s - l;

            // Find the first matching index that is >= l
            auto start_iterator = lower_bound(matching_indices.begin(), matching_indices.end(), l);

            // Find the first matching index that is > r
            auto end_iterator = upper_bound(matching_indices.begin(), matching_indices.end(), r);

            // The distance between these two iterators should be the count(?)
            int internal_matches = distance(start_iterator, end_iterator);

            // Now we have the count for this specific (l, r) pair
            int outside_matches = prefix_ok[l] + suffix_ok[r + 1];
            int total_matches = internal_matches + outside_matches;
            c[total_matches]++;
        }
    }

    for (int count : c) {
        cout << count << "\n";
    }
}
