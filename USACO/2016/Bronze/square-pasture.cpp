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
    setIO("square");

    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    int greatest_x = max(x2, x4);
    int greatest_y = max(y2, y4);
    int smallest_x = min(x1, x3);
    int smallest_y = min(y1, y3);

    cout << pow(max(greatest_x - smallest_x, greatest_y - smallest_y), 2);
}
