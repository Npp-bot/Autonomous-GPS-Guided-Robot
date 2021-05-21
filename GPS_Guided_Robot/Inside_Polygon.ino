void InsidePolygon(Point *polygon, int N, Point p, int inc)
{
  int counter = 0;
  int i;
  double xinters;
  Point p1, p2;

  p1 = polygon[0];
  for (i = 1; i <= N; i++) {
    p2 = polygon[i % N];
    if (p.y > MIN(p1.y, p2.y)) {
      if (p.y <= MAX(p1.y, p2.y)) {
        if (p.x <= MAX(p1.x, p2.x)) {
          if (p1.y != p2.y) {
            xinters = (p.y - p1.y) * (p2.x - p1.x) / (p2.y - p1.y) + p1.x;
            if (p1.x == p2.x || p.x <= xinters)
              counter++;
          }
        }
      }
    }
    p1 = p2;
  }

  if (counter % 2 == 0) {

    printf("outside");
  }
  else {
  polygon_[inc].x=p.x;
  polygon_[inc].y=p.y;
    printf("inside");
  }
}
