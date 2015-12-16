#include<stdio.h>
int f[1000001];
int main()
{
    int a,b,n;

    while(~scanf("%d %d %d",&a,&b,&n))
    {
        if(a==0&&b==0&&n==0)
            break;
        f[1]=1;
        f[2]=1;
        int xh=0;
        int i;
        for(i=3;i<=1001;i++)
        {
            f[i]=(a*f[i-1]+b*f[i-2])%7;
            if(f[i]==1&&f[i-1]==1)
            {
                break;
            }
        }
        xh=i-2;
        n=n%xh;
        if(n==0)n=xh;
        printf("%d\n",f[n]);
    }
    return 0;
}
