#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int par[10005], n, m;
struct edge
{
    int x, y, cost;
}cz[10005];
bool cmp (edge a, edge b)
{
    return a.cost < b.cost;
}
void init()
{
    for(int i=0;i<=(n*(n-1))/2;i++)
        par[i] = i;
}
int find(int x)
{
    int y = x;
    while(y != par[y])
    {
        y = par[y]; //find the root
    }
    while(x != par[x])
    {
        int px = par[x];
        par[x] = y; //let them union
        x = px;
    }
    return y;
}
void unite(int x, int y)
{
    x = par[x];
    y = par[y];
    par[x] = y;
}
void kruskal(int k)
{
    sort(cz, cz+k,cmp);
    int sum = 0;
    for(int i=0;i<k;i++)
    {
        int a = cz[i].x, b = cz[i].y, c = cz[i].cost;
        if(find(a) != find(b))
        {
            sum += c;
            unite(a,b);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(i>1 &&find(i) != find(i-1))
        {
            printf("?\n");
            return;
        }
    }
    printf("%d\n", sum);
}
int main()
{
    while(scanf("%d%d",&m,&n) && m != 0)
    {
        init();
        int a, b, c, i;
        for(i=0;i<m;i++)
        {
            scanf("%d %d %d",&a, &b, &c);
            cz[i].x = a; cz[i].y = b; cz[i].cost = c;
        }
        kruskal(i);
    }
}
