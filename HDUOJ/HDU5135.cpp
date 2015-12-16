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
const int maxn = 20;
const double eps = 1e-6;

int n, ha[maxn];
double ver[maxn];

inline double getArea(double a, double b, double c)
{
    //printf("a = %.0lf, b = %.0lf, c = %.0lf\n", a, b, c);
    double p = (a + b + c) / 2.0;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    return area;
}
bool cmp(double a, double b)
{
    return a > b;
}

int main()
{
    while(~scanf("%d", &n) && n)
    {
        clc(ha, 0);
        for(int i = 1; i <= n; i++)
        {
            scanf("%lf", &ver[i]);
        }
        sort(ver+1, ver+n+1, cmp);
        /*for(int i = 1; i <= n; i++)
            printf("%.0lf\n", ver[i]);*/
        int j = 2, k = 1;
        double sum = 0;
        while(j <= n)
        {
            if(ver[j] - ver[j-1]/2 > eps)
            {
                k++;
            }
            else
            {
                k = 1;
            }
            if(k == 3)
            {
                k = 0;
                sum += getArea(ver[j], ver[j-1], ver[j-2]);
            }
            j++;
        }
        printf("%.2lf\n", sum);
    }
    return 0;
}
