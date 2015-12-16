//  hdu 1175 连连看
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
using namespace std;
int m, n, x1, y1, x2, y2, flag;
int map[1005][1005];
int vis[1005][1005];
int move[4][2] = {0, -1, 0, 1, -1, 0, 1, 0};
struct point
{
    int x, y, fx, zj;
} st;
queue<point>q;
void bfs();

int main()
{
    int i, j,  t;

    //freopen("1.txt","w",stdout);
    while (~scanf("%d %d", &n, &m) && m + n != 0)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= m; j++)
            {
                scanf("%d", &map[i][j]);
            }
        }

        scanf("%d", &t);

        for (i = 0; i < t; i++)
        {
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            if ((map[x1][y1] == map[x2][y2]) && map[x1][y1] != 0)
            {
                for(int ii=1;ii<=n;ii++)
                    for(j=1;j<=m;j++)
                        vis[ii][j] = 1000;
                st.x = x1; st.y = y1; st.fx = -1; st.zj = 0;
                flag = 0;
                bfs();

                if (flag)
                {
                    printf("YES\n");
                }
                else
                {
                    printf("NO\n");
                }
            }
            else
            {
                printf("NO\n");
            }
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
        //printf("x=%d,y=%d,fx=%d,zj=%d\n",now.x,now.y,now.fx,now.zj);
        if (now.x == x2 && now.y == y2)
        {
            flag = 1;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            //printf("haha");
            point next = now;
            next.x = now.x + move[i][0];
            next.y = now.y + move[i][1];
            next.fx = i;
            //printf("next %d %d %d %d\n",next.x,next.y,next.fx,next.zj);
            if (now.fx != next.fx && now.fx != -1)
            {
                next.zj++;
            }

            if (next.x < 1 || next.y < 1 || next.x > n || next.y > m || next.zj > 2)
            {
                continue;
            }
            if (map[next.x][next.y]!=0 && !(next.x == x2 && next.y == y2))
            {
                continue;
            }

            if (next.zj <= vis[next.x][next.y])
            {
                vis[next.x][next.y] = next.zj;
                q.push(next);
            }
        }
    }
}


