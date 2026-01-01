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
    int x1, y1, x2, y2;
    int area() { return (x2 - x1) * (y2 - y1); }
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

    Rectangle lm;
    Rectangle feed;

    cin >> lm.x1 >> lm.y1 >> lm.x2 >> lm.y2;
    cin >> feed.x1 >> feed.y1 >> feed.x2 >> feed.y2;

    int visible_area = lm.area();
    int inter_area = intersection_area(lm, feed);

    if (feed.x1 <= lm.x1 && feed.x2 >= lm.x2 && (feed.y1 <= lm.y1 || feed.y2 >= lm.y2)) {
        visible_area -= inter_area;
    } else if (feed.y1 <= lm.y1 && feed.y2 >= lm.y2 && (feed.x1 <= lm.x1 || feed.x2 >= lm.x2)) {
        visible_area -= inter_area;
    }

    cout << visible_area;
}
