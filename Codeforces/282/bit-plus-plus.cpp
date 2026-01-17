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

    int n;
    cin >> n;

    int val = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        if (s[1] == '+') {
            val++;
        } else {
            val--;
        }
    }

    cout << val;
}
