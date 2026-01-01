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

    ll N;
    cin >> N;

    ll even = 0;
    ll odd = 0;

    for (int i = 0; i < N; i++) {
        ll num;
        cin >> num;

        if (num % 2 == 0) {
            even++;
        } else {
            odd++;
        }
    }

    ll count = 0;
    ll goal = 0;

    while (even + odd >= 1) {
        if (goal == 0) {
            if (even >= 1) {
                even--;
            } else if (odd >= 2) {
                odd -= 2;
            } else {
                break;
            }
        } else {
            if (odd >= 1) {
                odd--;
            } else {
                break;
            }
        }

        goal ^= 1; // Very useful XOR application
        count++;
    }

    // Must merge two groups
    if (goal == 0 && odd == 1) {
        count--;
    }

    cout << count;
}
