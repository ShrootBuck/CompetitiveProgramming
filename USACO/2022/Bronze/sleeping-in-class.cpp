#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        vector<int> a;
        int sum = 0; // for final list [K, K, K, ..., K], sum = KN
                     // we must minimize K such that we maximize N

        for (int n = 0; n < N; n++) {
            int hours;
            cin >> hours;

            sum += hours;
            a.push_back(hours);
        }

        if (sum == 0) {
            cout << 0;
            continue;
        }

        for (int k = 1; k <= sum; k++) {
            if (sum % k != 0) {
                continue;
            }

            int running = 0;
            bool found = true;

            for (int i : a) {
                running += i;
                if (running == k) {
                    running = 0;
                } else if (running > k) {
                    found = false;
                    break;
                }
            }

            if (found) {
                cout << N - sum / k << "\n";
                break;
            }
        }
    }
}
