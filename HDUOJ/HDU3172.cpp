#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <map>
using namespace std;
#define MAX 1000005
int par[MAX], num[MAX], n = 100005, f;
map<string ,int>mp;
void init()
{
    for(int i=0;i<=n;i++)
    {
        par[i] = i;
        num[i] = 1;
    }
}
int find(int x)
{
    int y = x;

    while (y != par[y])
    {
        y = par[y];
    }

    while (x != par[x])
    {
        int px = par[x];
        par[x] = y;
        x = px;
    }

    return y;
}
void Union(int x, int y)
{
    int ra = find(x), rb = find(y);
    //printf("find(%d) = %d,  find(%d) = %d\n", x, ra, y, rb);
    par[ra] = rb;
    int a = num[ra], b = num[rb];
    if(ra!=rb)
    {
        num[ra] = a+b;
        num[rb] = a+b;
    }
    printf("%d\n", num[ra]);
}
int main()
{
    //freopen("1.in","r",stdin);
    int  t, tt, k;
    char a[25], b[25];
    while(scanf("%d",&tt) != EOF){
    while(tt--)
    {
        scanf("%d",&t);
        k = 1;
        init();
        mp.clear();
        while(t--)
        {
            getchar();
            scanf("%s %s", a, b);
            if(!mp[a]) mp[a] = k++;
            if(!mp[b]) mp[b] = k++;
            Union(mp[a], mp[b]);
        }
    }
    }
    system("pause");
    return 0;
}
