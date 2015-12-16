#include<cstdio>
#include<cstring>
#include<queue>
#include<cstdlib>
using namespace std;
int lift[205];
int vis[205];
int n,a,b,flag,s;
struct point
{
    int x, step;
}st;
queue<point>q;
void bfs(point st);
int main()
{
    while(~scanf("%d",&n)&&n!=0)
    {
        scanf("%d %d",&a,&b);
        memset(lift,0,sizeof(lift));
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&lift[i]);
        }
        flag = 0;
        st.x = a;
        st.step = 0;
        vis[a]=1;
        bfs(st);
        if(flag) printf("%d\n",s);
        else printf("-1\n");
    }
}

void bfs(point st)
{
    while(!q.empty())
    {
        q.pop();
    }
    q.push(st);
    while(!q.empty())
    {
        point now = q.front();
        q.pop();
        //printf("x=%d,step=%d\n",now.x,now.step);
        int xx = now.x;
        if(xx == b)
        {
            flag = 1;
            s = now.step;
            return;
        }
        if((xx+lift[xx]) <=n && !vis[xx+lift[xx]])
        {
            point next = now;
            next.x = xx + lift[xx];
            vis[next.x] = 1;
            next.step++;
            q.push(next);
        }
        if((xx - lift[xx]) > 0 && !vis[xx-lift[xx]])
        {
            point next = now;
            next.x = xx - lift[xx];
            vis[next.x] = 1;
            next.step++;
            q.push(next);
        }
    }
}