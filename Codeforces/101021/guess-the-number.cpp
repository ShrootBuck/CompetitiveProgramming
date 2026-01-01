#include <bits/stdc++.h>

using namespace std;

#define ll long long

// Just to flush out buffer
void print(const string& s) { cout << s << endl; }

int main() {
    int l, r;
    l = 1;
    r = 1000000;

    while (r != l) {
        int guess = (r + l + 1) / 2;

        print(to_string(guess));

        string result;
        cin >> result;

        if (result == "<") {
            r = guess - 1;
        } else if (result == ">=") {
            l = guess;
        }
    }

    print("! " + to_string(l));
}
