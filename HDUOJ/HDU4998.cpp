#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cmath>
typedef long long ll;
using namespace std;
const double pi = acos(-1.0);
const double eps = 1e-9;

int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
struct Point {
  double x, y;
  Point() {
  }
  Point(double _x, double _y) {
      x = _x;
      y = _y;
  }
  void out() {
      printf("%.10f %.10f", x, y);
  }
};
typedef Point Vector;
Vector operator + (Vector A, Vector B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (Point A, Point B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (Vector A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (Vector A, double p) { return Vector(A.x/p, A.y/p); }
bool operator < (const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}
double sqr(double x) {
    return x * x;
}
double Dot(Vector A, Vector B) { return A.x*B.x + A.y*B.y; }
double Length(Vector A) { return sqrt(Dot(A, A)); }
double Angle(Vector A, Vector B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double angle(Vector v) { return atan2(v.y, v.x); }
double Cross(Vector A, Vector B) { return A.x*B.y - A.y*B.x; }
Vector Normal(Vector x) { return Point(-x.y, x.x) / Length(x);} //垂直法向量
///////////////////////////////////////////////////
//求直线p+tv和q+tw的交点 Cross(v, w) == 0无交点
Point GetLineIntersection(Point p, Vector v, Point q, Vector w) {
    Vector u = p-q;
    double t = Cross(w, u) / Cross(v, w);
    return p + v*t;
}

void change(Point& a, double x, double y, double z) {
    a.x -= x;
    a.y -= y;
    if (fabs(a.x) < eps && fabs(a.y) < eps) {
    } else {
        double r = sqrt(sqr(a.x) + sqr(a.y));
        double cosa = a.x / r, sina = a.y / r;
        //printf("\n;;;;%.10f;;%.10f;;;;%.10f;;;;;%.10f;;;;;%.10f;;;;%.10f;;;;;%.10f)\n", a.x, a.y, r, cosa, sina, cos(z), sin(z));
        a.x = r * (cosa * cos(z) - sina * sin(z));
        a.y = r * (sina * cos(z) + cosa * sin(z));
    }
    a.x += x;
    a.y += y;

}

void work() {
    Point a = Point(0, 0), b = Point(1, 0), c = Point(0, 1);
    int n;
    double x, y, z, ans = 0;
    scanf("%d", &n);
    while (n -- > 0) {
        scanf("%lf%lf%lf", &x, &y, &z);
        ans += z;
        while (ans + eps > 2 * pi)
            ans -= 2 * pi;
        if (z < eps && z > -eps)
            continue;
        change(a, x, y, z);
        change(b, x, y, z);
        change(c, x, y, z);
    }

    Point g;
    Vector toa(a.x - 0, a.y - 0), tob(b.x - 1, b.y - 0), toc(c.x - 0, c.y - 1);
    toa = Normal(toa); tob = Normal(tob); toc = Normal(toc);
    a = Point((a.x + 0) / 2, (a.y + 0) / 2);
    b = Point((b.x + 1) / 2, (b.y + 0) / 2);
    c = Point((c.x + 0) / 2, (c.y + 1) / 2);

    if (Cross(toa, tob)) {
        g = GetLineIntersection(a, toa, b, tob);
    } else if (Cross(tob, toc)) {
        g = GetLineIntersection(b, tob, c, toc);
    } else {
        g = GetLineIntersection(a, toa, c, toc);
    }
    g.out();
    printf(" %.10f\n", ans);
}

int main() {
    int cas;
    scanf("%d", &cas);
    while (cas -- > 0)
        work();
    return 0;
}
