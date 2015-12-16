//Author LJH
//www.cnblogs.com/tenlee
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define clc(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e4+5;
const double eps = 1e-8;

struct Point
{
    double x, y;
}point[maxn];
double dis[maxn][maxn], dd[maxn];
int n, m;

bool cmp(Point A, Point B)
{
    if(fabs(A.x - B.x) < eps) return A.y < B.y;
    return A.x < B.x;
}

void slove()
{
    double d1;
    for(int i = 0; i < n; i++)
    {
        dis[i][i] = 0.0;
        for(int j = i+1; j < n; j++)
        {
            d1 = (point[i].x - point[j].x) * (point[i].x - point[j].x) + (point[i].y - point[j].y)*(point[i].y-point[j].y);
            dis[i][j] = dis[j][i] = sqrt(d1);
        }
    }
    int ans = INF;
    double k;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dd[j] = dis[i][j];
        }
        sort(dd, dd+n);
        k = ceil(dd[m-1]);
        //printf("%d %f %f\n", i, k, dd[m-1]);
        if(fabs((k-dd[m-1])) < eps) k += 1.0;
        if(m < n && dd[m] - k > eps)
        {
            //printf("i = %d, k = %lf\n", i, k);
            ans = min(ans, (int)k);
        }
        else if (m >= n)
        {
            ans = min(ans, (int)k);
        }
    }
    if(ans == INF) printf("-1\n");
    else printf("%d\n", ans);
}
int main()
{
    //freopen("1.txt", "r", stdin);
    //freopen("1.out", "w", stdout);
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%lf %lf", &point[i].x, &point[i].y);
        }
        if(m > n)
        {
            printf("-1\n");
            continue;
        }
        //sort(point, point+n, cmp);
        slove();
    }
    return 0;
}
