struct Rectangle {
  long long x1, y1, x2, y2;

  Rectangle() : x1(0), y1(0), x2(0), y2(0) {}
  Rectangle(long long x1, long long y1, long long x2, long long y2)
      : x1(x1), y1(y1), x2(x2), y2(y2) {}

  long long area() { return (x2 - x1) * (y2 - y1); }
  long long perimeter() { return 2 * ((x2 - x1) + (y2 - y1)); }

  bool operator==(const Rectangle &other) const {
    return (x1 == other.x1 && y1 == other.y1 && x2 == other.x2 &&
            y2 == other.y2);
  }

  Rectangle intersection(const Rectangle &other) const {
    long long inter_x1 = max(x1, other.x1);
    long long inter_y1 = max(y1, other.y1);
    long long inter_x2 = min(x2, other.x2);
    long long inter_y2 = min(y2, other.y2);

    if (inter_x1 < inter_x2 && inter_y1 < inter_y2) {
      return Rectangle(inter_x1, inter_y1, inter_x2, inter_y2);
    } else {
      return Rectangle(0, 0, 0, 0);
    }
  }
};
