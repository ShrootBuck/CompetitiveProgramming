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
    setIO("div7");

    int N;
    cin >> N;

    int range = 0;
    vector<int> first(7, -1);
    first[0] = 0;

    int remainder = 0;
    for (int i = 1; i <= N; i++) {
        int cow;
        cin >> cow;

        remainder = (remainder + cow) % 7;
        if (first[remainder] == -1) {
            first[remainder] = i;
        } else {
            range = max(range, i - first[remainder]);
        }
    }
    cout << range;
}
