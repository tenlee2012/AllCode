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
const double eps = 1e-10;

double a[maxn];

void init()
{
    a[0] = 0.0;
    double x = 1 / 4;
    for(int i = 1; i < 50; i++)
    {
        a[i] = a[i-1] + pow(0.5, i+1);
        //printf("%.15f\n", a[i]);
    }
}

void slove()
{
    double x;
    int ans;
    scanf("%lf", &x);
    for(int i = 0; i < 49; i++)
    {
        if(x - a[i]> eps && a[i+1] - x > eps)
        {
            ans = 4 * (i+1);
            break;
        }
        if((fabs(x - a[i]) < eps))
        {
            ans = -1; 
            break;
        }
    }
    printf("%d\n", ans);
}
int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        slove();   
    }
    return 0; 
}
