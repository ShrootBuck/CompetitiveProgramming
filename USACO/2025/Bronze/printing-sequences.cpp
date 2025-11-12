#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

void newcase();

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

vector<vector<int>> cache(100, vector<int>(100, -1));

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        newcase();
        cout << "\n";

        // "zero" out the array
        cache = vector<vector<int>>(100, vector<int>(100, -1));
    }
}

int solve(int start, int end, const vector<int>& nums) {
    if (cache[start][end] != -1) {
        return cache[start][end];
    }
    int min_cost_so_far = INT_MAX;

    if (start == end) {
        return 1;
    }

    for (int i = start; i < end; ++i) {
        // Calculate the cost if we split after index i
        int current_cost = solve(start, i, nums) + solve(i + 1, end, nums);

        // Is this split better than the best one found so far??
        if (current_cost < min_cost_so_far) {
            min_cost_so_far = current_cost;
        }
    }

    int len = end - start + 1;

    for (int period = 1; period <= len / 2; period++) {
        if (len % period == 0) {
            bool is_a_match = true;
            for (int j = start + period; j <= end; ++j) {
                if (nums[j] != nums[j - period]) {
                    is_a_match = false;
                    break;
                }
            }

            if (is_a_match) {
                int rep_cost = solve(start, start + period - 1, nums);

                // Now, see if this is better than the best cost you've found so far
                min_cost_so_far = min(min_cost_so_far, rep_cost);
            }
        }
    }

    cache[start][end] = min_cost_so_far;
    return min_cost_so_far;
}

void newcase() {
    int N, K;
    cin >> N >> K;

    vector<int> nums(N);

    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }

    // If K is 1 then all numbers are 1 and its a single REP
    if (K == 1) {
        cout << "YES";
        return;
    }

    if (solve(0, N - 1, nums) <= K) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}