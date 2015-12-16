#include "cstdio"
#include "iostream"
#include "queue"
#include "cstring"
using namespace std;
struct point
{
    int px, py;
    int x, y, step;
}st[105][105];
struct Mark
{
    int x, y;
}mark[300];

char map[105][105];
int vis[105][105];
int n, m, flag = 0, sum;
int move[4][2] = {0,-1,0,1,-1,0,1,0};
queue<point>q;

void bfs();
void find();
int main()
{
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    while(~scanf("%d %d",&n, &m))
    {
        int i, j;
        getchar();
        for(i=0;i<n;i++)
        {
            gets(map[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                vis[i][j] = 10000;
        }
        st[0][0].x = 0;
        st[0][0].y = 0;
        st[0][0].step = 0;
        st[0][0].px = 0;
        st[0][0].py = 0;
        vis[0][0] = 0;
        flag = 0;

        sum = 100000;
        bfs();

        if(flag)
        {
            printf("It takes %d seconds to reach the target position, let me show you the way.\n",sum);
            find();
        }
        else printf("God please help our poor hero.\n");
        printf("FINISH\n");
    }
    return 0;
}

void bfs()
{
    while(!q.empty()) q.pop();
    q.push(st[0][0]);
    while(!q.empty())
    {
        point now = q.front();
        q.pop();
        //printf("px = %d, py = %d, x = %d y = %d t = %d\n",now.px,now.py,now.x,now.y,now.step);
        if(now.x == n-1 && now.y == m-1)
        {
            flag = 1;
            if(sum > now.step)
                sum = now.step;
        }
        for(int i=0;i<4;i++)
        {
            int xx = now.x, yy = now.y, t = now.step;
            xx += move[i][0];
            yy += move[i][1];
            if(xx<0 || xx>=n || yy<0 || yy>=m) continue;
            if(map[xx][yy] == 'X')    continue;

            if(map[xx][yy] == '.')
            {
                t++;
            }
            else
            {
                int id = map[xx][yy] - '0';
                t += id+1;
            }

            if(vis[xx][yy] > t)
            {
                st[xx][yy].px = now.x;
                st[xx][yy].py = now.y;
                st[xx][yy].x = xx;
                st[xx][yy].y = yy;
                st[xx][yy].step = t;
                vis[xx][yy] = t;
                //printf("st[%d][%d], px = %d, py = %d, t = %d\n",xx,yy,st[xx][yy].px,st[xx][yy].py ,st[xx][yy].step);
                q.push(st[xx][yy]);
            }
        }
    }
    return;
}
void find()
{
    int t = 0, xx = n-1, yy = m-1;
    mark[t].x = n-1;
    mark[t].y = m-1;
    while(1)
    {
        if(xx==0 && yy==0) break;
        t++;
        mark[t].x = st[xx][yy].px;
        mark[t].y = st[xx][yy].py;
        xx = mark[t].x;
        yy = mark[t].y;
    }
    int k = 1;
    for(int i=t; i>0;i--)
    {
        int a = mark[i].x, b = mark[i].y, c = mark[i-1].x, d = mark[i-1].y;
        printf("%ds:(%d,%d)->(%d,%d)\n",k++,a, b, c, d);
        if(map[c][d] != '.')
        {
            int id = map[c][d] - '0';
            for(int j=0;j<id;j++)
            {
                printf("%ds:FIGHT AT (%d,%d)\n",k++, c, d);
            }
        }
    }
}
