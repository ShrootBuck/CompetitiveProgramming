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
    setIO("sleepy");

    int N;
    cin >> N;

    vector<int> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    int sorted_caboose = 1;

    for (int i = N - 2; i >= 0; i--) {
        if (arr[i] < arr[i + 1]) {
            sorted_caboose++;
        } else {
            break;
        }
    }

    cout << N - sorted_caboose;
}
