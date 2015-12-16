#include<stdio.h>
#include<string.h>
long long dp[32770];
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i, j;
        memset(dp,0,sizeof(dp));
        dp[0] = 1;
        for(i=1;i<=3;i++)
        {
            for(j=i;j<=n;j++)
            {
                dp[j] += dp[j-i];
                //printf("dp[%d]=%d  ",j, dp[j]);
            }
            //printf("\n");
        }
        printf("%lld\n",dp[n]);
    }
    return 0;
}
