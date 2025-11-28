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

    ll n, m;
    cin >> n >> m;

    ll max_n = n - (m - 1);
    ll balanced_n_min = (n / m);

    ll max_k = (max_n * (max_n - 1)) / 2;
    ll min_k = (m - (n % m)) * ((balanced_n_min * (balanced_n_min - 1)) / 2) +
               (((balanced_n_min + 1) * balanced_n_min) / 2) * (n % m);

    cout << min_k << " " << max_k;
}
