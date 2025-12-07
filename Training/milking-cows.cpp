/*
ID: zayd1
LANG: C++
TASK: milk2
*/

#include <algorithm>
#include <climits>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
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
    setIO("milk2");

    int N;
    cin >> N;

    int start_time = INT_MAX, end_time = 0;

    vector<int> events(1'000'000, 0);
    for (int i = 0; i < N; i++) {
        int start, end;
        cin >> start >> end;
        events[start]++;
        events[end]--;

        start_time = min(start_time, start);
        end_time = max(end_time, end);
    }

    int longest_milking = 0, longest_idle = 0, milking_run = 0, idle_run = 0;
    int smear = 0;
    for (int i = start_time; i <= end_time; i++) {
        smear += events[i];

        if (smear > 0) {
            milking_run++;
            longest_idle = max(longest_idle, idle_run);
            idle_run = 0;
        } else {
            idle_run++;
            longest_milking = max(longest_milking, milking_run);
            milking_run = 0;
        }
    }

    cout << longest_milking << " " << longest_idle << "\n";
}
