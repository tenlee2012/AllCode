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
const int maxn = 1e6+5;

int a[maxn], b[maxn], n, m;

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
       scanf("%d %d", &n, &m);
       for(int i = 0; i < n; i++)
       {
           scanf("%d", &a[i]);
       }
       for(int i = 0; i < n; i++)
       {
           scanf("%d", &b[i]);
       }
       sort(a, a+n);
       sort(b, b+n);
       int sum1 = 0, sum2 = 0;
       for(int i = 0; i < m; i++)
       {
           sum1 += a[i];
       }
       for(int i = 1; i <= m; i++)
       {
           sum2 += b[n-i];
       }
       sum1 > sum2 ? puts("YES") : puts("NO");
    }
    return 0;
}
