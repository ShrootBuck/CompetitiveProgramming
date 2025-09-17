struct Rectangle {
  long long x1, y1, x2, y2;

  Rectangle() : x1(0), y1(0), x2(0), y2(0) {}
  Rectangle(long long x1, long long y1, long long x2, long long y2)
      : x1(x1), y1(y1), x2(x2), y2(y2) {}

  long long area() { return (x2 - x1) * (y2 - y1); }
  long long perimeter() { return 2 * ((x2 - x1) + (y2 - y1)); }
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
