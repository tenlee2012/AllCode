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

int a[maxn], d[maxn];
int n, d1, d2;
LL ans;

void inline slove()
{
    int i;
    LL j1 = 0, k2 = 0;
    //printf("%lld\n", ans);
    for(int i = 2; i <= n; i++)
    {
        j1 = 0;
        while(d[i] == d1 && i <= n) //j1计算有多少个符合d1的
        {
            j1++;
            i++;
        }
        k2 = 0;
        while(d[i] == d2 && i <= n)//k2计算有多少个符合d2的
        {
            k2++; 
            i++;
        }
        if(j1 || k2) i--;
        ans += (j1 + k2) * (j1 + k2 - 1) / 2 + (j1 + k2); //这个区间的至少两个数的组合数
        //printf("i = %d %d, %lld\n", i, d[i], ans);
    }
    printf("%lld\n", ans);
}

int main()
{
    while(~scanf("%d %d %d", &n, &d1, &d2))
    {
        ans = (LL)n;
        d[0] = 0;
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
                d[i] = a[i] - a[i-1]; //记录差
                //if(d[i] == d1 || d[i] == d2) ans++; 
        }
        slove();
    }
    return 0;
}
