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
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;
const double eps = 1e-6;

int n;
double a[maxn];

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++) 
        {
            scanf("%lf", &a[i]);
        }
        double ap = a[1] - a[0];
        double gp = a[1] / a[0];
        int len1 = 1, len2 = 1;
        int malen1 = 1, malen2 = 1;
        for(int i = 1; i < n; i++)
        {
            if(abs(a[i] - a[i-1] - ap) < eps) len1++;
            else
            {
                ap = a[i] - a[i-1];
                len1 = 2;
            }
            malen1 = (malen1 > len1 ? malen1 : len1);

            if(abs(a[i] / a[i-1] - gp) < eps) len2++;
            else
            {
                gp = a[i] / a[i-1];
                len2 = 2;
            }
            malen2 = (malen2 > len2 ? malen2 : len2);
        }
        printf("%d\n", malen1 > malen2 ? malen1 : malen2);
    }
    return 0;
}
