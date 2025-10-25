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
    setIO();

    int n, k;
    cin >> n >> k;
    k--;

    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int total = 0;

    for (int i = 0; i < n; i++) {
        total += (a[i] > 0 && a[i] >= a[k]);
    }

    cout << total;
}
