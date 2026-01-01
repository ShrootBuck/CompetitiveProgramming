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

    int T;
    cin >> T;
    while (T--) {
        string S;
        cin >> S;
        cout << ((S.back() == '0') ? 'E' : 'B') << "\n";
    }
}
