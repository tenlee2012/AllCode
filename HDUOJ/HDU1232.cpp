#include <stdio.h>
#include <stdlib.h>
#define MAX 1005
int par[MAX], m, n;
void init()
{
    for(int i=0;i<=n;i++)
    {
        par[i] = i;
    }
}
int find(int x)
{
    if(par[x] == x)
    {
        return x;
    }
    else
    {
        return par[x] = find(par[x]);
    }
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    par[x] = y;
}
int main()
{
    int a, b;
    while(~scanf("%d%d",&n, &m) && n!=0)
    {
        init();
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a, &b);
            unite(a,b);
        }
        int sum = 0;
        for(int i=1;i<=n;i++)
        {
            if(par[i] == i)
                sum++;
        }
        printf("%d\n", sum-1);
    }
    system("pause");
    return 0;
}
