/*
ID: zayd1
LANG: C++
TASK: friday
*/

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
    setIO("friday");

    int N;
    cin >> N;

    vector<int> counts(7);
    vector<int> thirty_day_months = {4, 6, 9, 11};

    int day = 1;

    for (int year = 1900; year < 1900 + N; year++) {
        for (int month = 1; month <= 12; month++) {
            int days;
            int monthday = 1; // Great naming scheme here

            // Feb
            if (month == 2) {
                days = 28;

                if (year % 100 == 0) {
                    if (year % 400 == 0) {
                        days = 29; // Leap year
                    }
                } else {
                    if (year % 4 == 0) {
                        days = 29;
                    }
                }
            } else if (find(thirty_day_months.begin(), thirty_day_months.end(), month) !=
                       thirty_day_months.end()) {
                days = 30;
            } else {
                days = 31;
            }

            for (int i = 1; i <= days; i++, day = (day + 1) % 7, monthday++) {
                if (monthday == 13) {
                    counts[day]++;
                }
            }
        }
    }

    rotate(counts.begin(), counts.begin() + (counts.size() - 1), counts.end());

    for (int i = 0; i < 7; i++) {
        cout << counts[i];
        if (i < 6) {
            cout << " "; // Or we could just not make the grader be stupid!
        }
    }

    cout << "\n"; // Or we could just not make the grader be stupid!
}
