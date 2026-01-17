#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("teleport.in", "r", stdin);
    freopen("teleport.out", "w", stdout);

    int a, b, x, y;
    cin >> a >> b >> x >> y;

    int just_fucking_drive_there = abs(a - b);
    int forward_teleport = abs(a - x) + abs(y - b);
    int reverse_teleport = abs(a - y) + abs(x - b);

    cout << min(just_fucking_drive_there, min(forward_teleport, reverse_teleport));
}
