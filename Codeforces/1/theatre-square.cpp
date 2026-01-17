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

    ll n, m, a;
    cin >> n >> m >> a;

    ll tiles1 = 0, tiles2 = 0;

    tiles1 += n / a;
    tiles1 += (n % a != 0);
    tiles2 += m / a;
    tiles2 += (m % a != 0);

    cout << tiles1 * tiles2;
}
