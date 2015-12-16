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
const int maxn = 1e5+5;
long long a[maxn];
int main()
{
    //freopen("1.txt", "r", stdin);
    int T, t, n;
    long long fig, k;
    scanf("%d", &T);
    for(t = 1; t <= T; t++)
    {
        scanf("%d %lld %lld", &n, &fig, &k);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }
        sort(a, a+n);
        int i, j;
        printf("Case #%d:\n", t);
        if(a[0] > fig)
        {
            puts("madan!");continue;
        }
        for(i = 0; i < n; i++)
        {
            if(a[i] > fig) break; 
        }
        fig = a[i-1];
        for(i = i-1; i < n-1;i++)
        {
            if(fig+k >= a[i] && fig+k < a[i+1])
            {
                fig = a[i]; k--;
            }
        }
        fig+k >= a[n-1] ? puts("why am I so diao?") : puts("madan!");
    }
    return 0;
}
