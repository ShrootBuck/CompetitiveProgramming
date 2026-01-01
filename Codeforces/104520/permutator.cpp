#include <bits/stdc++.h>

using namespace std;

void setIO(string name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("");

    long long n;
    cin >> n;

    vector<long long> a(n), b(n);

    for (long long i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (long long i = 0; i < n; i++) {
        cin >> b[i];
    }

    vector<long long> coefficients(n);
    for (long long k = 0; k < n; ++k) {
        coefficients[k] =
            a[k] * (k + 1LL) * (n - k); // Need that LL to keep all computation in 64bit integers
    }

    sort(coefficients.begin(), coefficients.end());
    sort(b.rbegin(), b.rend());

    long long min_sum = 0;

    for (int i = 0; i < n; ++i) {
        min_sum += coefficients[i] * b[i];
    }

    cout << min_sum;
}
