#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int map[10][10];
int vis[10][10];
int movex[4] = {0,0,-1,1};
int movey[4] = {-1,1,0,0};
int n, m, a, b, c, d;
int s, flag;
struct point
{
    int x, y, step, time;
} st;
queue<point>q;

void bfs(point st);
int main()
{
    //freopen("1.txt","w",stdout);
    int t;
    int i, j;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &n, &m);
        memset(map, 0, sizeof(map));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }

        flag = 0;
        memset(vis, 0, sizeof(vis));

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < m; j++)
            {
                if (map[i][j] == 2)
                {
                    a = i;
                    b = j;
                }

                if (map[i][j] == 3)
                {
                    c = i;
                    d = j;
                }
            }
        }

        st.x = a;
        st.y = b;
        st.step = 0;
        st.time = 6;
        bfs(st);

        if (flag)
        {
            printf("%d\n", s);
        }
        else
        {
            printf("-1\n");
        }
    }
}

void bfs(point st)
{
    while (!q.empty())
    {
        q.pop();
    }

    q.push(st);

    while (!q.empty())
    {
        point now  = q.front();
        q.pop();
        //printf("x = %d,y = %d,step = %d,time = %d,k = %d\n",now.x,now.y,now.step,now.time,now.k);
        for (int i = 0; i < 4; i++)
        {
            int xx = now.x, yy = now.y;
            xx += movex[i];
            yy += movey[i];

            if (now.time <= 0)
            {
                continue;
            }

            if (map[xx][yy] == 3&&now.time>0)
            {
                s = now.step + 1;
                flag = 1;
                return;
            }

            if (xx >= 0 && xx < n && yy >= 0 && yy < m && map[xx][yy] != 0)
            {
                point next = now;
                next.step += 1;
                next.time -= 1;

                if(map[xx][yy]==4)
                {
                    next.time = 6;
                }

                if(next.time>1 && vis[xx][yy]<next.time) 
                {
                    vis[xx][yy]=next.time;
                    next.x = xx;    next.y = yy;
                    q.push(next);
                }
            }
        }
    }
}
/*
5 8
1 2 1 1 1 1 1 4
1 0 0 0 1 0 0 1
1 4 1 0 1 1 0 1
1 0 0 0 0 3 0 1
1 1 4 1 1 1 1 1
*/
