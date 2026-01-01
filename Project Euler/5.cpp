#include <bits/stdc++.h>


using namespace std;

long long lcm(long long a, long long b) {
    if (a == 0 || b == 0)
        return 0;
    return a / gcd(a, b) * b;
}

int main() {
    long long n = 1;
    for (int i = 2; i <= 20; i++) {
        n = lcm(n, i);
    }
    std::cout << n << "\n";
}
