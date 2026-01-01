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
    setIO("herding");

    vector<ll> pos(3);
    cin >> pos[0] >> pos[1] >> pos[2];

    int minimum, maximum;

    sort(pos.begin(), pos.end());

    if (pos[0] == pos[2] - 2) {
        minimum = 0;
    } else if (pos[1] == pos[2] - 2 || pos[0] == pos[1] - 2) {
        minimum = 1;
    } else {
        minimum = 2;
    }

    maximum = max(pos[2] - pos[1], pos[1] - pos[0]) - 1;

    cout << minimum << "\n" << maximum;
}
