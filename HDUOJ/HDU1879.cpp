#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
int par[10005], n;
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
    printf("%d\n", sum);
}
int main()
{
    while(scanf("%d",&n) && n != 0)
    {
        init();
        int a, b, c, d, k = 0, i;
        for(i=0;i<(n*(n-1))/2;i++)
        {
            scanf("%d %d %d %d",&a, &b, &c, &d);
            if(!d)
            {
                cz[k].x = a; cz[k].y = b; cz[k].cost = c;
                k++;
            }
            else
            {
                unite(a,b);
            }
        }
        if(k == 0) printf("0\n");
        else kruskal(k);
    }
}
