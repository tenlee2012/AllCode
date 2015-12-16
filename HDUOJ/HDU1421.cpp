#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include<cstdlib>
#include <algorithm>
using namespace std;
int dp[2005][1005];
int main()
{
    //freopen("1.in","r",stdin);
    int n, m, a[2005];
    while(~scanf("%d %d",&n,&m))
    {
        int i, j;
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        sort(a+1,a+n+1);

        dp[0][0] = 0;

        for(i=2;i<=n;i++)
        {
            for(j = 1; 2*j <= i; j++)
            {
                if(j*2 == i)
                {
                    dp[i][j] = dp[i-2][j-1] + (a[i]-a[i-1])*(a[i]-a[i-1]);
                    continue;
                }
                dp[i][j] = min(dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]),dp[i-1][j]);
                //printf("dp[%d][%d] = %d\n", i, j, dp[i][j]);
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}

