#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <map>
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
    setIO("");

    int T;
    cin >> T;

    vector<int> times(T);
    map<int, int> order;

    for (int i = 0; i < T; i++) {
        cin >> times[i];
    }

    vector<int> sorted_times = times;
    sort(sorted_times.begin(), sorted_times.end());

    int degree = 1;

    for (int i = 0; i < sorted_times.size(); i++) {
        int time = sorted_times[i];

        while (time > (int)pow(5, degree)) {
            degree++;
        }

        order[time] = degree;
    }

    for (int i : times) {
        int deg = order[i];

        if (deg == 1) {
            cout << "MIT time";
        } else {
            cout << "MIT^" + to_string(deg) + " time";
        }

        cout << "\n";
    }
}
