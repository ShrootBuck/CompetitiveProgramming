#include <bits/stdc++.h>
using namespace std;

int main() {
    size_t total = 0;
    size_t a = 0;
    size_t b = 1;
    size_t next = b;
    while (a + b < 4000000) {
        next = a + b;

        a = b;
        b = next;

        if (b % 2 == 0) {
            total += b;
        }
    }

    cout << total;
}
