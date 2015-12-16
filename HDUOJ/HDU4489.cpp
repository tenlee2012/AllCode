#include<cstdio>
#include<cstring>

using namespace std;

__int64 dp[21][2];
__int64 answer[21];

__int64 C(int x,int y)  //   xê&#199;μ×êy
{
    __int64 mother=1,son=1;
    for(int i=0;i<y;i++)
    {
        mother*=(y-i);
        son*=(x-i);
    }
    return son/mother;
}
int main()
{
    for(int i=0;i<=20;i++){
        for(int j=0;j<2;j++)
            dp[i][j]=1;
    }
    answer[1]=1;
    for(int i=2;i<=20;i++){
        for(int j=1;j<=i;j++){
            answer[i]+=C(i-1,j-1)*dp[j-1][0]*dp[i-j][1];

        }
        dp[i][0]=dp[i][1]=answer[i]/2;
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int k,n;
        scanf("%d%d",&k,&n);
        printf("%d",k);
        printf(" %I64d\n",answer[n]);
    }
    return 0;
}