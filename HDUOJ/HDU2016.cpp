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
const int maxn = 1e3+5;

int main()
{
    int n, a[maxn];
    int ma, mi, i_ma, i_mi;
    while(~scanf("%d", &n))
    {
        if(n == 0) break;
        ma = -INF;
        mi = INF;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if(a[i] > ma)
            {
                i_ma = i;
                ma = a[i];
            }
            if(a[i] < mi)
            {
                i_mi = i;
                mi = a[i];
            }
        }
        a[i_mi] = a[0];
        a[0] = mi;
        for(int i = 0; i < n-1; i++)
        {
            printf("%d ", a[i]);
        }
        printf("%d\n", a[n-1]);
    }
    return 0;
}
