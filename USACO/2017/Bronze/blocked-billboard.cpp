#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>
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
    int x1, y1, x2, y2;
};

int intersection_area(Rectangle r1, Rectangle r2) {
    int inter_x1 = max(r1.x1, r2.x1);
    int inter_y1 = max(r1.y1, r2.y1);
    int inter_x2 = min(r1.x2, r2.x2);
    int inter_y2 = min(r1.y2, r2.y2);

    int width = inter_x2 - inter_x1;
    int height = inter_y2 - inter_y1;

    return max(0, width) * max(0, height);
}

int main() {
    setIO("billboard");

    Rectangle b1;
    Rectangle b2;
    Rectangle truck;

    cin >> b1.x1 >> b1.y1 >> b1.x2 >> b1.y2;
    cin >> b2.x1 >> b2.y1 >> b2.x2 >> b2.y2;
    cin >> truck.x1 >> truck.y1 >> truck.x2 >> truck.y2;

    // Calculate total billboard area
    int total_billboard_area =
        (b1.y2 - b1.y1) * (b1.x2 - b1.x1) + (b2.y2 - b2.y1) * (b2.x2 - b2.x1);

    // truck intersection with b1
    int inter_b1 = intersection_area(b1, truck);
    int inter_b2 = intersection_area(b2, truck);

    cout << total_billboard_area - inter_b1 - inter_b2;
}
