#include <algorithm>
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

int solve() {
    int N;
    cin >> N;

    vector<int> h(N + 1);
    int biggest_height = 0;
    for (int i = 0; i < N; i++) {
        int height;
        cin >> height;

        h[height]++;
        biggest_height = max(biggest_height, height);
    }

    int ans = 1;
    for (int i = 0; i < h.size(); i++) {
        if (i != biggest_height && h[i] > 1) {
            ans += 2;
        }
    }

    return ans;
}

int main() {
    setIO();

    int T;
    cin >> T;

    while (T--) {
        cout << solve() << "\n";
    }
}
