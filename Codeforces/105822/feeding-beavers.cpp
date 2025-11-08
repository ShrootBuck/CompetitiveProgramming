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

void solve() {
    int N;
    cin >> N;

    string c;
    cin >> c;

    int e = 0, o = 0;

    for (int i = 0; i < N; i++) {
        o += c[i] == 'O';
    }

    e = N - o;

    if (o % 2 == N % 2) {
        cout << "YES\n";

        int next_odd = 1;
        int next_even = 2;
        int extra_evens = 0;

        for (int i = 0; i < N; i++) {
            if (c[i] == 'O') {
                // give one odd and one even
                cout << next_odd << " " << next_even << "\n";
                next_odd += 2;
                next_even += 2;
            } else {
                if (extra_evens == 0) {
                    // use two odds
                    cout << next_odd << " " << next_odd + 2 << "\n";
                    next_odd += 4;
                    extra_evens = 2;
                } else {
                    // use two evens
                    cout << next_even << " " << next_even + 2 << "\n";
                    next_even += 4;
                    extra_evens = 0;
                }
            }
        }
    } else {
        cout << "NO" << "\n";
    }
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        solve();
    }
}
