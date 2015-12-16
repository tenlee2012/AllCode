#include<stdio.h>
#include<string.h>
int  dp[20010];
int main()
{
    int n, m ,t;
    scanf("%d",&t);
    while(t--)
    {
        int i, j, k = 0;
        int p[105], w[105], num[105],a, b, c;
        scanf("%d %d",&m, &n);
        for(i=0;i<n;i++)
        {
           /* scanf("%d %d %d", &a, &b, &c);
            for(j=1;j<=c;j++)
            {
                p[k] = a;
                w[k] = b;
                k++;
            }*/
            scanf("%d%d%d",&p[i],&w[i],&num[i]);

        }
        memset(dp,0,sizeof(dp));
        int sum = 0;
        for(i=0;i<n;i++)
        {
            //printf("p[%d] = %d, w[%d] = %d\n", i, p[i], i, w[i]);
            for (k=0;k<num[i];k++)
                 for(j=m;j>=p[i];j--)
                {
                    if(dp[j] < (dp[j-p[i]] + w[i]))
                        dp[j] = dp[j-p[i]] + w[i];
               // printf("dp[%d] = %d\n", j, dp[j]);
                }
        }
        printf("%d\n",dp[m]);
    }
    return 0;
}