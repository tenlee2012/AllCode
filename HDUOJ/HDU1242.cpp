#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
char map[205][205];
int vis[205][205];
int move[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int m, n, k, flag;
struct point
{
    int x, y, step;
}st;
queue<point>q;
void bfs(point st);
int main()
{
    //freopen("1.txt", "w", stdout);
    while (~scanf("%d%d", &m, &n))
    {
        int i, j;
        k = 0;    flag = 0;
        getchar();

        for (i = 0; i < m; i++)
        {
            gets(map[i]);
        }

        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (map[i][j] == 'r')
                {
                    break;
                }
            }
            if(map[i][j] == 'r') break;
        }
        st.x = i;
        st.y = j;
        st.step = 0;
        bfs(st);
        if(flag) printf("%d\n",k);
        else printf("Poor ANGEL has to stay in the prison all his life.\n");
    }
}
void bfs(point st)
{
    while(!q.empty())
    {
        q.pop();
    }

    memset(vis,0,sizeof(vis));
    vis[st.x][st.y] = 1;
    q.push(st);

    while(!q.empty())
    {
        point now = q.front();
        q.pop();
     //   printf("x = %d, y =  %d, step =  %d\n",now.x,now.y,now.step);
        for(int i=0;i<4;i++)
        {
            point next = now;
            next.x += move[i][0];
            next.y += move[i][1];
            int xx=next.x, yy = next.y;
            if(map[xx][yy] == 'a')
            {
                k = next.step+1;
                flag = 1;
                return;
            }
            if(xx>=0 && xx<m && yy >= 0 && yy <n && !vis[xx][yy] && (map[xx][yy] == '.' || map[xx][yy] == 'x'))
            {
                next.step++;
                if(map[xx][yy] == 'x') next.step++;
                vis[xx][yy] = 1;
                //printf("x = %d, y =  %d, step =  %d\n",next.x,next.y,next.step);
                q.push(next);
            }
        }
    }
}
/*
7 8
#.#####.
#.a#..r.
#..#x...
..#..#.#
#...##..
.#......
........
*/