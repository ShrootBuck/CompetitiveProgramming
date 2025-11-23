#include <cstdio>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>
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

double solve() {
    int n, d, h;
    cin >> n >> d >> h;

    vector<int> y(n);
    for (int i = 0; i < n; i++) {
        cin >> y[i];
    }

    double area = 0;

    for (int i = 0; i < n - 1; i++) {
        int dh = y[i + 1] - y[i];

        if (dh < h) {
            double weird_base = (double)d * (h - dh) / h;
            area += (d + weird_base) * dh / 2.0;
        } else {
            area += (double)d * h / 2.0;
        }
    }

    // The final triangle
    area += (double)d * h / 2.0;

    return area;
}

int main() {
    setIO();

    int t;
    cin >> t;

    cout << fixed << setprecision(7);

    while (t--) {
        cout << solve() << "\n";
    }
}
