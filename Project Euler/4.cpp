#include <bits/stdc++.h>

using namespace std;

bool check_palindrome(int n) {
    string s = to_string(n);
    string r = s;
    reverse(r.begin(), r.end());

    return s == r;
}

int main() {
    int m;

    for (int i = 100; i < 1000; i++) {
        for (int j = 100; j < 1000; j++) {
            if (check_palindrome(i * j)) {
                m = max(m, i * j);
            }
        }
    }

    cout << m;
}
