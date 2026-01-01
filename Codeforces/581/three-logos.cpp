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

struct point {
    int x, y;
    char c;

    void print(void) {
        for (int i = 0; i < this->y; i++) {
            for (int j = 0; j < this->x; j++)
                cout << this->c;
            cout << '\n';
        }
    }
};

int main() {
    setIO();

    point a, b, c;

    cin >> a.x >> a.y >> b.x >> b.y >> c.x >> c.y;
    a.c = 'A';
    b.c = 'B';
    c.c = 'C';

    // Bigger side is x for easier implementation
    if (a.x < a.y) {
        swap(a.x, a.y);
    }
    if (b.x < b.y) {
        swap(b.x, b.y);
    }
    if (c.x < c.y) {
        swap(c.x, c.y);
    }

    if (a.x == b.x && a.x == c.x) {
        if (a.y + b.y + c.y == a.x) {
            cout << a.x << "\n";

            a.print();
            b.print();
            c.print();
        } else {
            cout << -1;
        }
        return 0;
    }

    // Let a be the logo with the largest x
    if (c.x > b.x) {
        swap(b, c);
    }
    if (b.x > a.x) {
        swap(a, b);
    }

    int vertical_remainder = a.x - a.y;

    // Ensure that x is the horizontal run
    if (b.x == vertical_remainder) {
        swap(b.x, b.y);
    }
    if (c.x == vertical_remainder) {
        swap(c.x, c.y);
    }

    // Check if we actually have good fit
    if (b.x + c.x == a.x && c.y == vertical_remainder && b.y == vertical_remainder) {
        cout << a.x << "\n";
        a.print();

        for (int i = 0; i < vertical_remainder; i++) {
            for (int j = 0; j < b.x; j++) {
                cout << b.c;
            }
            for (int j = 0; j < c.x; j++) {
                cout << c.c;
            }
            cout << '\n';
        }

        return 0;
    }

    cout << -1;
}
