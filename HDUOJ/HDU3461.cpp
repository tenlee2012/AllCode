#include<stdio.h>
#define M 1000000007
int par[10000007];
int n,m;
void init()
{
    for (int i=0;i<=n;i++)
        par[i] = i;
}
int find(int x)
{
    int y = x;
    while (y != par[y])
    {
        y = par[y];
    }
    while ( x != par[x])
    {
        int px = par[x];
        par[x] = y;
        x = px;
    }
    return y;
}
void unite(int x, int y)
{
    x = find(x);
    y = find(y);
    par[x]  = y;
}
long long  mod(int y)
{
    long long  r=1, x = 26;
    while (y != 0)
    {
        if (y & 1)
            r = (r * x) % M;
        x = (x * x)%M;
        y >>= 1;
    }
    return r%M;
}
int main()
{
    int i, j,k,t,l,r;
    while (~scanf("%d %d",&n,&m))
    {
        init();
        t = 0;
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&l,&r);
            if(find(l-1)==find(r))
                continue;
            else 
            {
                unite(l-1,r);
                t++;
            }
        }
    //    printf("%d\n",t);
        printf("%lld\n",mod(n-t));
    }
    return 0;
}

