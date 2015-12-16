#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdlib>
#include <algorithm>
using namespace std;
struct DP
{
    int px;
    int sum;
}dp[105];
int path[105][105];
int main()
{
    //freopen("1.in","r",stdin);
    int tt, t, k = 1;
    scanf("%d",&t);
    tt = t;
    while(tt--)
    {
        int n, val[105], lu, aa, bb;
        int i, j;
        scanf("%d",&n);
        memset(path,0,sizeof(path));
        for(i=1;i<=n;i++)
            scanf("%d",&val[i]);
        scanf("%d",&lu);
        for(i=0; i<lu; i++)
        {
            scanf("%d %d",&aa, &bb);
            path[aa][bb] = 1;
        }

        int max, y, c[105];
        dp[1].sum = 0;
        dp[1].px = 1;
        for(i=2;i<=n;i++)
        {
            max = 0;
            if(path[1][i] != 0) y = 1;
            else y = 0;

            for(j=1;j<i;j++)
            {
                if(dp[j].sum > max && dp[j].px!=0 && path[j][i]!=0)
                {
                    y = j;
                    max = dp[j].sum;
                }
            }
            dp[i].sum = max + val[i];
            dp[i].px = y;
            //printf("dp[%d].sum =  %d, px = %d\n", i, dp[i].sum, dp[i].px);
        }
        max = 0;
        for(i=2;i<=n;i++)
        {
            if(dp[i].sum > max && path[i][n+1] == 1)
            {
                y = i;
                max = dp[i].sum;
            }
        }
        i = 1;
        c[0] = 1;
        c[i++] = y;
        while(1)
        {
            c[i] = dp[c[i-1]].px;
            if(c[i] == 1) break;
            i++;
        }
        printf("CASE %d#\npoints : %d\n",k++, max);
        printf("circuit : 1");
        for(j=i-1;j>=0;j--)
        {
            printf("->%d",c[j]);
        }
        printf("\n");
        if(k<=t) printf("\n");
    }
}