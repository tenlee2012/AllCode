#include <stdio.h>  
#include <string.h>  
#define MAXN 10002  
  
int main()  
{  
    int n,m,i,j;  
    int ai[MAXN];  
    double pi[MAXN],dp[MAXN];  
    while(scanf("%d %d",&n,&m))  
    {  
        if(n+m==0)  
            break;  
        for(i=0;i<m;++i)  
        {  
            scanf("%d %lf",&ai[i],&pi[i]);  
            pi[i]=1.0-pi[i];  
        }  
        for(i=0;i<=n;++i)  
            dp[i]=1;  
        //memset(dp,1,sizeof(dp));memset()不能用于浮点型  
        for(i=0;i<m;++i)  
        {  
            for(j=n;j>=ai[i];--j)  
                if(dp[j]>dp[j-ai[i]]*pi[i])  
                    dp[j]=dp[j-ai[i]]*pi[i];  
        }  
        printf("%.1lf%%\n",(1-dp[n])*100);  
    }  
    return 0;  
}  