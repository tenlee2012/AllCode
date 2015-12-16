#include<stdio.h>
#include<string.h>
int m, n,dp[1050],v[1050],w[1050];
int main()
{
    int t,i,j;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++) 
            scanf("%d",&v[i]);
        for(i=0;i<n;i++)
            scanf("%d",&w[i]);
        memset(dp,0,sizeof (dp));
        for (i=0;i<n;i++)
        {
            for (j=m;j>=w[i];j--)
            {
                if (dp[j]<(dp[j-w[i]]+v[i]))
                    dp[j] = dp[j-w[i]]+v[i];
            }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}