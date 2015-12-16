#include <stdio.h>
#include <stdlib.h>
#define MAX 1000005
int par[MAX], arr[MAX], m, n = 100005, f;
void init()
{
    for(int i=0;i<=n;i++)
    {
        par[i] = i;
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
    par[ra] = rb;
}
int main()
{
    //freopen("1.in","r",stdin);
    int a, b, t, i, j;
    while(1)
    {
        f = 1; t = 0,j=1;
        init();
        while(1)
        {
            scanf("%d%d",&a,&b);
            if(a==-1 && b==-1)
            {
                exit(0);
            }
            if(a+b == 0)
            {
                break;
            }
            arr[t++] = a;
            arr[t++] = b;
            if (find(a)==find(b))
            {
                j=0;
            }
            else Union(a,b);
        }
        getchar();
        for(i=0;i<t;i++)
        {
            //printf("Find[%d] = %d, Find[%d] = %d\t",arr[i-1],find(arr[i-1]),arr[i],find(arr[i]));
            if(i>0&&find(arr[i])!=find(arr[i-1]))
            {  f=0;  break;}
        }
        if(f==1&&j==1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    system("pause");
    return 0;
}
