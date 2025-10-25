#include <cctype>
#include <cstdio>
#include <iostream>
#include <string>
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

bool is_lucky(int &a) {
    string s = to_string(a);

    for (auto &c : s) {
        if (c != '4' && c != '7') {
            return false;
        }
    }

    return true;
}

int main() {
    setIO();

    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        if (is_lucky(i)) {
            if (n % i == 0) {
                cout << "YES";
                return 0;
            }
        }
    }

    cout << "NO";
}
