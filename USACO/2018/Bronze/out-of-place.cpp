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

int main() {
    setIO("outofplace");

    int N;
    cin >> N;

    vector<int> height(N);

    for (int i = 0; i < N; i++) {
        cin >> height[i];
    }

    auto sorted_height = height;
    sort(sorted_height.begin(), sorted_height.end());

    int bad = 0;

    for (int i = 0; i < N; i++) {
        bad += sorted_height[i] != height[i];
    }

    cout << bad - 1;
}
