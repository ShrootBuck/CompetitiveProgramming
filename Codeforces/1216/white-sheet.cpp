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

struct Rectangle {
    long long x1, y1, x2, y2;

    Rectangle() : x1(0), y1(0), x2(0), y2(0) {}
    Rectangle(long long x1, long long y1, long long x2, long long y2)
        : x1(x1), y1(y1), x2(x2), y2(y2) {}

    long long area() { return (x2 - x1) * (y2 - y1); }
    long long perimeter() { return 2 * ((x2 - x1) + (y2 - y1)); }

    bool operator==(const Rectangle& other) const {
        return (x1 == other.x1 && y1 == other.y1 && x2 == other.x2 && y2 == other.y2);
    }
};

long long intersection_area(Rectangle r1, Rectangle r2) {
    long long inter_x1 = max(r1.x1, r2.x1);
    long long inter_y1 = max(r1.y1, r2.y1);
    long long inter_x2 = min(r1.x2, r2.x2);
    long long inter_y2 = min(r1.y2, r2.y2);

    long long width = inter_x2 - inter_x1;
    long long height = inter_y2 - inter_y1;

    return max(0LL, width) * max(0LL, height);
}

int main() {
    setIO();
    long long x1, y1, x2, y2;

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle white(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle black1(x1, y1, x2, y2);

    cin >> x1 >> y1 >> x2 >> y2;
    Rectangle black2(x1, y1, x2, y2);

    // find the rectangle representing the overlap of the two black sheets
    Rectangle black_overlap(max(black1.x1, black2.x1), max(black1.y1, black2.y1),
                            min(black1.x2, black2.x2), min(black1.y2, black2.y2));

    long long covered1 = intersection_area(white, black1);
    long long covered2 = intersection_area(white, black2);
    long long double_counted = intersection_area(white, black_overlap);

    long long total_covered_area = covered1 + covered2 - double_counted;

    if (white.area() > total_covered_area) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}
