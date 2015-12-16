#include<stdio.h>
int main()
{
    int f[35];
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int a, i;
        scanf("%d",&a);
        f[0] = 3;
        for(i=1;i<=a;i++)
        {
            f[i] = 2*(f[i-1] -1);
        }
        printf("%d\n",f[a]);
    }
    return 0;
}
