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

    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // Yes yes holy hell unoptimized
    vector<int> res(N);
    for (int i = N - 1; i >= 0; i--) {
        int tallest = -1;
        for (int j = i - 1; j >= 0; j--) {
            if (A[j] > A[i]) {
                tallest = j + 1;
                break;
            }
        }

        res[i] = tallest;
    }

    for (int& r : res) {
        cout << r << "\n";
    }
}
