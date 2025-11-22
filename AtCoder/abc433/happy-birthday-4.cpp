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

int main() {
    setIO();

    int X, Y, Z;
    cin >> X >> Y >> Z;

    int numerator = X - Z * Y;
    int denominator = Z - 1;

    if (numerator >= 0 && numerator % denominator == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
