#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("paint");

    int a;
    int b;
    int c;
    int d;

    cin >> a >> b >> c >> d;

    int lenA = b - a;
    int lenB = d - c;

    int overlap = max(0, min(b, d) - max(a, c));

    cout << lenA + lenB - overlap;
}
