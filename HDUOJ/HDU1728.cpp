// hdu 1728
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int m, n, k, x1, y1, x2, y2, flag;
char map[105][105];
int vis[105][105];
int move[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
struct point
{
    int x, y, fx, zj;
} st;
queue<point>q;
void bfs();

int main()
{
    //freopen("1.in","r",stdin);
    int i, j, t;
    scanf("%d", &t);

    while (t--)
    {
        scanf("%d %d", &m, &n);

        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                scanf(" %c", &map[i][j]);
            }
        }

        scanf("%d %d %d %d %d",&k, &y1, &x1, &y2, &x2);

        for (int ii = 1; ii <= m; ii++)
            for (j = 1; j <= n; j++)
            {
                vis[ii][j] = 1000;
            }

        st.x = x1;
        st.y = y1;
        st.fx = -1;
        st.zj = 0;
        flag = 0;
        bfs();

        if (flag)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
}

void bfs()
{
    while (!q.empty())
    {
        q.pop();
    }

    q.push(st);

    while (!q.empty())
    {
        point now = q.front();
        q.pop();

        //printf("\nnow x %d,y %d, fx %d,zj %d\n", now.x, now.y, now.fx, now.zj);
        if (now.x == x2 && now.y == y2 )
        {
            flag = 1;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int xx = now.x, yy = now.y;
            xx += move[i][0];
            yy += move[i][1];

            point next = now;
            next.x = xx;
            next.y = yy;
            next.fx = i;

            if (next.fx != now.fx && now.fx != -1)
            {
                next.zj++;
            }

            if(next.zj>k) continue;

            if (xx > 0 && xx <= m && yy > 0 && yy <= n && map[xx][yy] == '.')
            {
                if (next.zj <= vis[xx][yy])
                {
                    vis[xx][yy] = next.zj;
                    q.push(next);
                }
            }
        }
    }
}
