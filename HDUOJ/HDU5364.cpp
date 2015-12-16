//Author LJH
//www.cnblogs.com/tenlee
#include <bits/stdc++.h>
#define clc(a, b) memset(a, b, sizeof(a))
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e6+5;

int ha[maxn], nu[maxn];

int main()
{
    int n, ans, x, k;
    while(~scanf("%d", &n))
    {
        clc(ha, 0);
        ans = -1;
        k = 0;
        for(int i = 0; i < n; i++)
        {
            scanf("%d", &x);
            if(!ha[x]) nu[k++] = x;
            ha[x]++;
        }
        for(int i = 0; i < k; i++)
        {
            if(ha[nu[i]] > (n-ha[nu[i]]))
                ans = nu[i];
        }
        printf("%d\n", ans);
    }
    return 0;
}

