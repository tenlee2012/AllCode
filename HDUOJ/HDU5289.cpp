#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e6+10;
long long a[maxn], n, k;

int main()
{
    //freopen("1002.in", "r", stdin);
    int T, x;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d %d", &n, &k);
        for(int i = 0; i < n; i++)
        {
            scanf("%lld", &a[i]);
        }

        __int64 ans = n;
        long long ma = a[0], mi = a[0], x, y;
        long long len = 1, i = 0, j;
        while(i < n-1)
        {
            x = y = i;
            mi = a[i];
            ma = a[i];
            len = 1;
            for(j = i+1; j < n; j++)
            {
                if(a[j] > ma)
                {
                    ma = a[j]; y = j;
                }
                if(a[j] < mi)
                {
                    mi = a[j]; x = j;
                }
                if(ma - mi < k)
                {
                    len++;
                }
                else
                {
                    break;
                }
            }
            //printf("j = %d, len = %d, ma = %d, mi = %d\n", j, len, ma, mi);
            ans += (len-1) * len / 2;
            if(j >= n) break;
            i = min(x, y) + 1;
            if(i < j)
            {
                ans -= (j-i) * (j-i-1) / 2;
            }
            //printf("i = %d\n", i);
        }
        printf("%I64d\n", ans);
    }
    return 0;
}
