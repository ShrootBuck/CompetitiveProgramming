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
    setIO("race");

    int K, N;
    cin >> K >> N;

    vector<ll> X(N);

    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }

    for (ll& x : X) {
        int t = 0;
        int accelerate_distance = 0, decelerate_distance = 0;
        int speed = 1;

        while (true) {
            accelerate_distance += speed;
            t++;

            if (accelerate_distance + decelerate_distance >= K) {
                cout << t << "\n";
                break;
            }

            if (speed >= x) {
                decelerate_distance += speed;
                t++; // Double-count time to account for the descent
                if (accelerate_distance + decelerate_distance >= K) {
                    cout << t << "\n";
                    break;
                }
            }

            speed++;
        }
    }
}
