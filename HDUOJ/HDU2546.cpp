#include<stdio.h>
#include<algorithm>
using namespace std;
int dp[1005];
int main()
{
    int n,m,a[1005],i,j;
    while(~scanf("%d",&n) && n!=0)
    {
        for(i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
        }
        scanf("%d",&m);
        if(m<5)
        {
            printf("%d\n",m);
            continue;
        }
        sort(a,a+n);
        memset(dp,0,sizeof(dp));
        m=m-5;
        for(i=0;i<n-1;i++)
        {
            for(j=m;j>=a[i];j--)
            {
                dp[j]=max(dp[j],(dp[j-a[i]]+a[i]));
            }
        }
        printf("%d\n",m+5-dp[m]-a[n-1]);
    }
    return 0;
}