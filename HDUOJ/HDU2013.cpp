#include<stdio.h>
int main()
{
    int f[35];
    int n;

    while(~scanf("%d",&n))
    {
        int i = 0;
        f[1] = 1;
        for(i=2;i<=n;i++)
        {
            f[i] = 2*(f[i-1] +1);
        }
        printf("%d\n",f[n]);
    }
    return 0;
}
