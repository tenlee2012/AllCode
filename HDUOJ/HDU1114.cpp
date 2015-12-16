#include<stdio.h>
int dp[10005], p[505],w[505];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a, b, i, j, n, m;
        scanf("%d%d",&a,&b);
        m = b - a;
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            scanf("%d%d",&p[i], &w[i]);
        }
        for(i=0;i<=m;i++)
        {
            dp[i] = 999999;
        }
        dp[0] = 0;
        for(i=0;i<n;i++)
        {
            for(j=w[i];j<=m;j++)
            {
                if(dp[j] > (dp[j-w[i]] + p[i]))
                    dp[j] = dp[j-w[i]] + p[i];
                //printf("dp[%d]=%d  ", j, dp[j]);
            }
            //printf("\n\n");
        }
        if (dp[m] < 999999)
            printf("The minimum amount of money in the piggy-bank is %d.\n",dp[m]);
        else
            printf("This is impossible.\n");
    }
}
