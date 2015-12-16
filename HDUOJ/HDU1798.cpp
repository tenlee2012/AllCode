#include <cstdio>
 
#include <iostream>
 
#include <cmath>
 
#include <cstdlib>
 
#include <cstring>
 
#include <vector>
 
#include <algorithm>
 
using namespace std;
 
#define PI  acos(-1)
 
const double eps = 1e-6;
 
struct Point
 
{
 
    double x, y;
 
    Point (double x = 0, double y = 0) : x(x), y(y) { } //构造函数， 方便代码书写
 
};
 
typedef Point myvector;
 
  
 
// 向量 + 向量 = 向量
 
myvector operator + (myvector A, myvector B) { return myvector(A.x + B.x, A.y + B.y); }
 
// 点 - 点 = 向量
 
myvector operator - (Point A, Point B) { return myvector(A.x - B.x, A.y - B.y); }
 
//向量 * 数 = 向量
 
myvector operator * (myvector A, double p) { return myvector(A.x * p, A.y * p); }
 
//向量/数 = 向量
 
myvector operator / (myvector A, double p) { return myvector(A.x / p, A.y / p); }
 
// 小于号
 
bool operator < (const Point & a, const Point & b)
 
{
 
  
 
    if (a.x == b.x) return a.y < b.y;
 
    return a.x < b.x;
 
}
 
//比较
 
int dcmp(double x)
 
{
 
    if(fabs (x) < eps) return 0;
 
    else return x < 0 ? -1 : 1;
 
}
 
// 恒等于号
 
bool operator ==  (const Point & a, const  Point  & b)
 
{
 
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
 
}
 
// 计算向量 A B 的点积， A*B = |A| * |B| * cos&#223;
 
double Dot (myvector A, myvector B) { return A.x*B.x + A.y*B.y; }
 
// 计算向量 A 的长度
 
double Length (myvector A) { return sqrt (Dot(A, A)); }
 
// 计算向量 A,B 的夹角，是cos 有公式
 
double Angle (myvector A, myvector B)
 
{ return acos(Dot(A, B) / Length(A) / Length(B)); }
 
  
 
// 计算叉积，AxB = |A| * |B| * sin&#223;， 得到的是与这两个向量垂直的向量
 
double Cross(myvector A, myvector B) { return A.x * B.y - A.y * B.x; }
 
double Area2(Point A, Point B, Point C) { return fabs(Cross(B - A, C - A)); }
 
//计算两点距离
 
double DistancePoint(Point A, Point B) { return sqrt((A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y)); }
 
// 计算向量旋转后变成的另一个向量， rad 是弧度
 
//公式 x1 = x * cos&#223; - y * sin&#223;， y1 = x * sin&#223; + y * cos&#223;;
 
myvector Rotate(myvector A, double rad)
 
{
 
    return myvector(A.x * cos(rad) - A.y * sin(rad),
 
                  A.x * sin(rad) + A.y * cos(rad));
 
}
 
//计算向量的单位法线， 在调用前确保 A 不是零向量
 
myvector Normal(myvector A)
 
{
 
    double L = Length(A);
 
    return myvector(-A.y / L,  A.x / L);
 
}
 
//直线可以用直线上一点p1, 和方向向量V表示， 即 向量P = 点p1 + V;
 
//计算两直线的 交点 ， 调用前确保两直线有交点
 
Point  GetLineInstersection(Point P, myvector v, Point Q, myvector w)
 
{
 
    myvector u = P - Q;
 
    double t = Cross(w, u) / Cross(v, w);
 
    return P + v * t;
 
}
 
//点到直线的距离
 
double DistanceToLine(Point P, Point A, Point B)
 
{
 
    myvector v1 = B - A, v2 = P - A;
 
    return fabs(Cross(v1, v2) / Length(v1));
 
}
 
// 点到线段的距离， 有两种可能， 一种点在线段上方， 这时候算垂直， 不在线段上方；
 
double DistanceToSegment(Point P, Point A, Point B)
 
{
 
    if( A == B) return Length(P-A); //如果线段是一个点
 
    myvector v1 = B - A, v2 = P - A, v3 = P - B;
 
    if(dcmp(Dot(v1, v2)) < 0)      return Length(v2);
 
    else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
 
    else return fabs(Cross(v1, v2)) / Length(v1);
 
}
 
//计算点在直线上投影的点
 
Point GetLineProjectoin(Point P, Point A, Point B)
 
{
 
    myvector v = B - A;
 
    return A + v * (Dot(v, P-A) / Dot(v, v));
 
}
 
  
 
struct Line
 
{
 
    Point v, p, e;
 
    Point point(double t)
 
    {
 
       return (p + v * t);
 
    }
 
};
 
struct Circle
 
{
 
    Point c;
 
    double r;
 
    Circle(Point _c=0,double _r=0):c(_c),r(_r){}
 
    Point point(double a)///根据圆心角算圆上的点
 
    {
 
        return Point(c.x+cos(a)*r,c.y+sin(a)*r);
 
    }
 
};
 
double angle(myvector V) {return atan2(V.y, V.x);}
 
//将直线AB沿法线方向平移d得到的直线EF,
 
myvector move_d(Point A, Point B, double d, Line& L)
 
{
 
    myvector C = B - A;
 
    C = C/Length(C);
 
    C = Rotate(C, PI/2);
 
    L.p = A + C * d;
 
    L.e = B + C * d;
 
    L.v = L.e - L.p;
 
    return (L.v);
 
}
 
//圆与直线的交点, 相离,没有交点, 相切一个交点, 相交两个交点
 
int getLineCircleInteresection(Line L, Circle C, double& t1, double& t2, vector<Point>& sol)
 
{
 
    //printf("##%f %f %f %f\n", L.p.x, L.p.y, L.e.x, L.e.y);
 
    double a = L.v.x, b = L.p.x - C.c.x, c = L.v.y, d = L.p.y - C.c.y;
 
    double e = a*a + c*c, f = 2 * (a*b + c*d), g = b*b + d*d - C.r*C.r;
 
    double delta = f*f - 4*e*g;
 
   // printf("delta = %.16f, esp = %.16f\n", delta, eps);
 
    if(dcmp(delta) < 0)
 
    {
 
       return 0;
 
       }
 
    if(dcmp(delta) == 0)
 
    {
 
        t1 = t2 = -f / (2 * e);
 
        sol.push_back(L.point(t1));
 
        return 1;
 
    }
 
    //相交
 
    t1 = (-f - sqrt(delta)) / (2 * e); sol.push_back(L.point(t1));
 
    t2 = (-f + sqrt(delta)) / (2 * e); sol.push_back(L.point(t2));
 
    return 2;
 
}
 
//计算两圆相交
 
int getCircleCircleIntersection(Circle C1, Circle C2, vector<Point> &sol)
 
{
 
    double d = Length(C1.c - C2.c);
 
    if(dcmp(d) == 0)
 
    {
 
        if(dcmp(C1.r - C2.r) == 0) return -1; //两圆重合
 
        return -2;//圆心一样,小圆在大圆内
 
    }
 
    if(dcmp(C1.r + C2.r - d) < 0) return 0; //相离
 
    if(dcmp(fabs(C1.r - C2.r) - d) > 0) return -3;//圆心不同,大圆在小圆内
 
  
 
    double a = angle(C2.c - C1.c);//计算向量C1C2的极角
 
    double da = acos((C1.r * C1.r + d * d - C2.r * C2.r) / (2 * C1.r * d));
 
    //C1C2到C1P1的角
 
    Point p1 = C1.point(a - da), p2 = C1.point(a + da);
 
    sol.push_back(p1);
 
    if(p1 == p2) return 1;
 
    sol.push_back(p2);
 
    return 2;
 
}
 
int getTangents(Point p, Circle C, myvector* v)
 
{
 
    myvector u = C.c - p;
 
    double dis = Length(u);
 
    if (dis < C.r)  return 0;
 
    else if (dcmp(dis - C.r) == 0)
 
    {
 
        v[0] = Rotate(u, PI / 2.0);
 
        return 1;
 
    }
 
    else
 
    {
 
        double ang = asin(C.r / dis);
 
        v[0] = Rotate(u, -ang);
 
        v[1] = Rotate(u, +ang);
 
        return 2;
 
    }
 
}
 
//两圆的切线条数, (1)重合,无数条,(2)两圆内含没有公共点没有切线,(3)两圆内切,有1条,
 
//(4)两圆相交有2条, (5)两圆外切,3条, (6)两圆相离,4条公切线
 
//返回切线条数, a[i],b[i]分别是第i条切线在圆A和B的切点
 
int getTangentsCircle(Circle A, Circle B, Point* a, Point* b)
 
{
 
    int cnt = 0;
 
    if(A.r < B.r)  //swap
 
    {
 
        Circle temp; Point *temp1 = NULL;
 
        A = temp; A = B; B = temp;
 
        a = temp1; a = b; b = temp1;
 
    }
 
    int d2 = (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y - B.c.y);
 
    int rdiff = A.r - B.r;
 
    int rsum = A.r + B.r;
 
    if(d2 < rdiff * rdiff) return 0; // 内含
 
  
 
    double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
 
    if(d2 == 0 && A.r == B.r) return -1; //无限多条
 
  
 
    if(d2 == rdiff * rdiff)
 
    {
 
        a[cnt] = A.point(base);
 
        b[cnt] = B.point(base);
 
        cnt++;
 
    }
 
    //有外共切线
 
    double ang = acos((A.r - B.r) / sqrt(d2));
 
    a[cnt] = A.point(base + ang); b[cnt] = B.point(base + ang); cnt++;
 
    a[cnt] = A.point(base - ang); b[cnt] = B.point(base - ang); cnt++;
 
    if(d2 == rsum * rsum) //一条内公切线
 
    {
 
        a[cnt] = A.point(base); b[cnt] = B.point(PI + base); cnt++;
 
    }
 
    else if(d2 > rsum * rsum)
 
    {
 
        double ang = acos(A.r + B.r) / sqrt(d2);
 
        a[cnt] = A.point(base + ang); b[cnt] = B.point(PI + base + ang); cnt++;
 
        a[cnt] = A.point(base - ang); b[cnt] = B.point(PI + base - ang); cnt++;
 
    }
 
    return cnt;
 
}

double CircleInterSectionArea(Circle A, Circle B, vector<Point>&sol)
{
    sol.clear();
    int f = getCircleCircleIntersection(A, B, sol);
    if(f == 0 || f == 1) return 0;//相离, 相切
    if(f < 0) return (min(A.r,B.r)*min(A.r,B.r)*PI);//内含
    Point p3 = sol[0];
    double areatri = Area2(A.c, B.c, p3);
    double ang1 = Angle(sol[0]-A.c, B.c-A.c);
    double ang2 = Angle(sol[0]-B.c, A.c-B.c);
    double areacir1 = A.r * A.r * ang1;
    double areacir2 = B.r * B.r * ang2;
    return (areacir1+areacir2-areatri);
    
}
 
bool cmp(Point A, Point B)
 
{
 
    if(A.x == B.x) return A.y < B.y;
 
    return A.x < B.x;
 
}
 
//三角形外接圆
 
void FUN1(double x1, double y1, double x2, double y2, double x3, double y3);
 
//三角形内切圆
 
void FUN2(double x1, double y1, double x2, double y2, double x3, double y3);
 
//过圆外某点切线的角度
 
void FUN3(double xc, double yc, double r, double xp, double yp);
 
//过某条直线外一点半径为r的圆
 
void FUN4(double xp, double yp, double x1, double y1, double x2, double y2, double r);
 
//和两条相交直线相切的半径为r的圆
 
void FUN5(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double r);
 
//和两个相离的圆相切的圆
 
void FUN6(double x1, double y1, double r1, double x2, double y2, double r2, double r);
 
  
 
int main()
 
{
 
    //freopen("1.txt", "r", stdin);
    double a1, b1, r1, a2, b2, r2;
    vector<Point> sol;
    while(~scanf("%lf %lf %lf %lf %lf %lf", &a1, &b1, &r1, &a2, &b2, &r2))
    {
        Circle a, b;
        Point p1, p2;
        p1.x = a1; p1.y = b1; a.c = p1; a.r = r1;
        p2.x = a2; p2.y = b2; b.c = p2; b.r = r2;
        printf("%.3f\n", CircleInterSectionArea(a, b, sol));
    }
    
    /*char s[50], s1[50] = "CircumscribedCircle", s2[50] = "InscribedCircle", s3[50] = "TangentLineThroughPoint",
 
    s4[50] = "CircleThroughAPointAndTangentToALineWithRadius", s5[50] = "CircleTangentToTwoLinesWithRadius",
 
    s6[50] = "CircleTangentToTwoDisjointCirclesWithRadius";
 
    while(~scanf("%s", s))
 
    {
 
       if(!strcmp(s,s1))
 
       {
 
           double x1, y1, x2, y2, x3, y3;
 
           cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 
           FUN1(x1, y1, x2, y2, x3, y3);
 
       }
 
       else if(!strcmp(s, s2))
 
       {
 
           double x1, y1, x2, y2, x3, y3;
 
           cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
 
           FUN2(x1, y1, x2, y2, x3, y3);
 
       }
 
       else if(!strcmp(s,s3))
 
       {
 
           double xc, yc, r, xp, yp;
 
           cin >> xc >> yc >> r >> xp >> yp;
 
           FUN3(xc, yc, r, xp, yp);
 
       }
 
       else if(!strcmp(s,s4))
 
       {
 
           double xp, yp, x1, y1, x2, y2, r;
 
           cin >> xp >> yp >> x1 >> y1 >> x2 >> y2 >> r;
 
           FUN4( xp, yp, x1, y1, x2, y2, r);
 
       }
 
       else if(!strcmp(s,s5))
 
       {
 
           double x1, y1, x2, y2, x3, y3, x4, y4, r;
 
           cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4 >> r;
 
           FUN5(x1, y1, x2, y2, x3, y3, x4, y4, r);
 
       }
 
       else if(!strcmp(s,s6))
 
       {
 
           double x1, y1, r1, x2, y2, r2, r;
 
           cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2 >> r;
 
           FUN6(x1, y1, r1, x2, y2, r2, r);
 
       }
 
       getchar();
 
    }*/
 
    return 0;
 
}
 
void FUN1(double x1, double y1, double x2, double y2, double x3, double y3)
 
{//三角形外接圆
 
    Point A, B, C, D, E, F;
 
    myvector AB, BC, DE, DF;
 
    A.x = x1; A.y = y1; B.x = x2; B.y = y2; C.x = x3; C.y = y3;
 
E.x = (A.x + B.x)/2.0; E.y = (A.y + B.y)/2.0;
 
F.x = (B.x + C.x)/2.0; F.y = (B.y + C.y)/2.0;
 
    AB = B - A;       BC = C - B;
 
    DE = Normal(AB);  DF = Normal(BC);
 
    D = GetLineInstersection(E, DE, F, DF);
 
    double r = DistancePoint(B, D);
 
    printf("(%f,%f,%f)\n", D.x, D.y, r);
 
    return;
 
}
 
void FUN2(double x1, double y1, double x2, double y2, double x3, double y3)
 
{//三角形内切圆
 
    Point A, B, C;
 
    A.x = x1; A.y = y1; B.x = x2; B.y = y2; C.x = x3; C.y = y3;
 
    myvector v11 = B - A;
 
    myvector v12 = C - A;
 
    myvector v21 = A - B;
 
    myvector v22 = C - B;
 
    double ang1 = (angle(v11) + angle(v12)) / 2.0;
 
    double ang2 = (angle(v21) + angle(v22)) / 2.0;
 
    myvector vec1 = myvector(cos(ang1), sin(ang1));
 
    myvector vec2 = myvector(cos(ang2), sin(ang2));
 
    Point O = GetLineInstersection(A, vec1, B, vec2);
 
    double r = DistanceToLine(O, A, B);
 
    printf("(%f,%f,%f)\n", O.x, O.y, r);
 
}
 
  
 
void FUN3(double xc, double yc, double r, double xp, double yp)
 
{//过圆外某点切线的角度
 
    myvector vc[5];
 
    int len = getTangents(Point(xp, yp), Circle(Point(xc, yc), r), vc);
 
    double tmp[5];
 
    for (int i = 0; i < len; ++i)
 
    {
 
        double ang = angle(vc[i]);
 
        if (ang < 0) ang += PI;
 
        ang = fmod(ang, PI);
 
        tmp[i] = ang * 180 / PI;
 
    }
 
    sort(tmp, tmp + len);
 
    printf("[");
 
    for (int i = 0; i < len; ++i)
 
    {
 
        printf("%.6lf", tmp[i]);
 
        if (i != len - 1) printf(",");
 
    }
 
    printf("]\n");
 
    return;
 
}
 
void FUN4(double xp, double yp, double x1, double y1, double x2, double y2, double r)
 
{//过某条直线外一点半径为r的圆
 
    Line L1, L2;
 
    Point X, Y, P, Q, pp[10];
 
    double t1, t2;
 
    int k = 0;
 
    vector<Point>sol, sol2;
 
    X.x = x1; X.y = y1; Y.x = x2; Y.y = y2; P.x = xp; P.y = yp;
 
    Circle C(P, r);
 
  
 
    move_d(X, Y, -r, L1);
 
    move_d(X, Y, r, L2);
 
    int f = getLineCircleInteresection(L1, C, t1, t2, sol),
 
       f1 = getLineCircleInteresection(L2, C, t1, t2, sol2);
 
    printf("[");
 
    if(f == 1)
 
    {
 
       pp[k++] = sol[0];
 
    //  printf("(%f,%f)", sol[0].x, sol[0].y);
 
    }
 
    if(f == 2)
 
    {
 
       pp[k++] = sol[0]; pp[k++] = sol[1];
 
    //  printf("(%f,%f),(%f,%f)", sol[0].x, sol[0].y, sol[1].x, sol[1].y);
 
    }
 
  
 
    if(f1 == 1)
 
    {
 
       pp[k++] = sol2[0];
 
    //  if(f != 0) printf(",");
 
    //  printf("(%f,%f)", sol2[0].x, sol2[0].y);
 
    }
 
    if(f1 == 2)
 
    {
 
       pp[k++] = sol2[0];
 
       pp[k++] = sol2[1];
 
       //if(f != 0) printf(",");
 
       //printf("(%f,%f),(%f,%f)", sol2[0].x, sol2[0].y, sol2[1].x, sol2[1].y);
 
    }
 
    sort(pp,pp+k);
 
    for(int i=0;i<k;i++)
 
    {
 
       printf("(%f,%f)", pp[i].x, pp[i].y);
 
       if(i != k-1) printf(",");
 
    }
 
    printf("]\n");
 
    return;
 
}
 
void FUN5(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, double r)
 
{//和两条相交直线相切的半径为r的圆
 
    Line L1, L2;
 
    Point A, B, C, D, P, pp[10];
 
    int k = 0;
 
    A.x = x1; A.y = y1; B.x = x2; B.y = y2; C.x = x3; C.y = y3; D.x = x4; D.y = y4;
 
    move_d(A, B, r, L1); move_d(C, D, r, L2); P = GetLineInstersection(L1.p, L1.v, L2.p, L2.v);
 
    pp[k++] = P;
 
//  printf("[(%f,%f),", P.x, P.y);
 
    move_d(A, B, r, L1); move_d(C, D, -r, L2); P = GetLineInstersection(L1.p, L1.v, L2.p, L2.v);
 
    pp[k++] = P;
 
//  printf("(%f,%f),", P.x, P.y);
 
    move_d(A, B, -r, L1); move_d(C, D, r, L2); P = GetLineInstersection(L1.p, L1.v, L2.p, L2.v);
 
    pp[k++] = P;
 
//  printf("(%f,%f),", P.x, P.y);
 
    move_d(A, B, -r, L1); move_d(C, D, -r, L2); P = GetLineInstersection(L1.p, L1.v, L2.p, L2.v);
 
    pp[k++] = P;
 
//  printf("(%f,%f)]\n", P.x, P.y);
 
    sort(pp, pp+k);
 
    printf("[");
 
    for(int i=0;i<k;i++)
 
    {
 
       printf("(%f,%f)", pp[i].x, pp[i].y);
 
       if(i != k-1) printf(",");
 
    }
 
    printf("]\n");
 
    return;
 
}
 
void FUN6(double x1, double y1, double r1, double x2, double y2, double r2, double r)
 
{//和两个相离的圆相切的圆
 
    Point a, b, c, pp[10];
 
    int k = 0;
 
    a.x = x1; a.y = y1;b.x = x2; b.y = y2;
 
    Circle A(a,r1), B(b,r2);
 
    Circle C(a,r1+r), D(b,r2+r);
 
    vector<Point>sol;
 
    int t = getCircleCircleIntersection(C, D, sol);
 
    if(t == 1) pp[k++] = sol[0]; //printf("[(%f,%f)]\n", sol[0].x, sol[0].y);
 
    else if(t == 2)
 
    {
 
pp[k++] = sol[0]; pp[k++] = sol[1]; //printf("[(%f,%f),(%f,%f)]\n", sol[0].x, sol[0].y,sol[1].x, sol[1].y);
 
    }
 
    sort(pp, pp+k);
 
    printf("[");
 
    for(int i=0;i<k;i++)
 
    {
 
       printf("(%f,%f)", pp[i].x, pp[i].y);
 
       if(i != k-1) printf(",");
 
    }
 
    printf("]\n");    return;
 
}
 
 //Power by LJH
