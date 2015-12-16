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
const int maxn = 1e5+5;
const int M = 2e9+5;

int fac[maxn], pri[maxn];
int n, a[maxn];

void init()
{
    clc(pri, 0); 
    pri[0] = pri[1] = 1;
    for(int i = 2; i <= (int)sqrt(M); i++)
    {
        if(pri[i]) continue;
        for(int j = 2, k = i*j; k <= (int)sqrt(M); j++)
        {
            pri[k] = 1;
            k = i * j;
        }
    }
}

void slove()
{
    int k = 2, num = 0, f, t, j;
    for(int i = 0; i < n; i++)
    {
        t = 0;
        if(a[i] == 1) continue;
        f = a[i];
        for(int j = 2; j*j <= f; j++)
        {
            while(f % j == 0)
            {
                t = 1;
                f = f / j;
                if(pri[j] == 0) fac[num++] = j;
            }
        }
        if(f > 1 && t) fac[num++] = f;
        if(!t) fac[num++] = a[i];
        //printf("num = %d\n", num);
    }
    if(num < 2) printf("-1\n");
    else
    {
        sort(fac, fac+num);
        printf("%lld\n", (LL)fac[0] * fac[1]);
    }
}

int main()
{
    init();
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
        }
        slove();
    }
    return 0;
}
