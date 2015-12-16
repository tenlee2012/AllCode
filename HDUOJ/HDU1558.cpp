#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int n, par[1005], num[1005];
struct point
{
    double x1, y1, x2, y2;
} p[1005];
struct Point
{
    double x, y;
    Point(double x = 0, double y = 0) : x(x), y(y) {};
};
typedef Point myvector;
// 向量 + 向量 = 向量
myvector operator + (myvector A, myvector B)
{
    return myvector(A.x + B.x, A.y + B.y);
}
// 点 - 点 = 向量
myvector operator - (Point A, Point B)
{
    return myvector(A.x - B.x, A.y - B.y);
}
//向量 * 数 = 向量
myvector operator * (myvector A, double p)
{
    return myvector(A.x * p, A.y * p);
}
//向量/数 = 向量
myvector operator / (myvector A, double p)
{
    return myvector(A.x / p, A.y / p);
}
//比较
const double eps = 1e-10;
int dcmp(double x)
{
    if (fabs(x) < eps)    return 0;
    else    return x < 0 ? -1 : 1;
}
// 恒等于号
bool operator == (const Point & a, const  Point  & b)
{
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}
//叉积
double Cross(myvector A, myvector B)
{
    return A.x * B.y - A.y * B.x;
}
bool SegmentProperIntersection(Point a1, Point a2, Point b1, Point b2)
{
    double c1 = Cross(a2 - a1, b1 - a1), c2 = Cross(a2 - a1, b2 - a1),
           c3 = Cross(b2 - b1, a1 - b1), c4 = Cross(b2 - b1, a2 - b1);
    //printf("%lf %lf %lf %lf\n", c1, c2, c3, c4);
    if(!c1 || !c2 || !c3 || !c4) return 1;
    return dcmp(c1) * dcmp(c2) < 0 && dcmp(c3) * dcmp(c4) < 0;
}
//判断一个点是否在一条线段上， 不含端点

int find(int x)
{
    int y = x;

    while (y != par[y])
    {
        y = par[y];
    }

    while (x != par[x])
    {
        int px = par[x];
        par[x] = y;
        x = px;
    }

    return y;
}

void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y)
    {
        num[x] += num[y];
        par[y] = x;
    }
}

int main()
{
    char c;
    int T, x, k, i, j;
    Point A, B, C, D;
    cin >> T;
    while (T--)
    {
        k = 1;
        cin >> n;
        getchar();
        for (i = 0; i <= n; i++)
        {
            num[i] = 1;
            par[i] = i;
        }
        while (n--)
        {
            scanf("%c", &c);
            if (c == 'P')
            {
                scanf("%lf%lf%lf%lf", &p[k].x1, &p[k].y1, &p[k].x2, &p[k].y2);
                A.x = p[k].x1;    A.y = p[k].y1;
                B.x = p[k].x2;    B.y = p[k].y2;
                for (j = 1; j < k; j++)
                {
                    C.x = p[j].x1;    C.y = p[j].y1;
                    D.x = p[j].x2;    D.y = p[j].y2;
                    if (par[j] != par[k] && SegmentProperIntersection(A, B, C, D))
                    {
                        //cout <<"##"<< j << " " << k <<endl;
                        unite(j, k);
                    }
                }
                k++;
            }
            else if (c == 'Q')
            {
                cin >> x;
                cout << num[find(x)] << endl;
            }
            else    continue;
            getchar();
        }
        if(T) printf("\n");
    }
    return 0;
}
