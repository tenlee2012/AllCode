#include<stdio.h>
#include<string.h>
#include<queue>
#define N 10100
using namespace std;
int pre[N],num[N],a[10];
int n,m,x;
void init()
{
    memset(pre,-1,sizeof(pre));
    memset(num,-1,sizeof(num));
    memset(a,0,sizeof(a));
}
void print(int u)
{
    if (pre[u]!=-1) print(pre[u]);
    //printf("pre[%d] = %d, num = %d\n",u, pre[u], num[u]); //其实就是一个数分解成单个数输出
    printf("%d",num[u]);
}
int bfs()
{
    int i,j,t;
    queue<int>q;
    for (i=1;i<10;++i)
    {
        if (!a[i])
        {
            t=i%n;
            if (t==0) { printf("%d",i);return 0;}
            q.push(t);
            num[t] = i;
        }
    }
    while (!q.empty())
    {
        int u=q.front();
        q.pop();
        //printf("u = %d\t", u);
        for (i=0;i<10;++i)
        {
            if (!a[i])
            {
                t=(10*u + i)%n;//这样做得到的数一定不含那m个数的任何一个,除模相当于剪枝,
                if (num[t]==-1)
                {
                    q.push(t);
                    pre[t]=u;
                    num[t]=i;
                }
                if (t==0)
                {
                    //printf("# %d #", 10*u*i);
                    print(t);
                    return 0;
                }
            }
        }
    }
    printf("-1");
    return 0;
}
int main ()
{
    //freopen("2.txt", "w", stdout);
    int i,j,k=0;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        init();
        while (--m>=0)
        {
            scanf("%d",&x);
            a[x]=1;
        }
        printf("Case %d: ",++k);
        bfs();
        printf("\n");
    }
    return 0;
}
