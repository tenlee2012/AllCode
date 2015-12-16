#include <stdio.h>
#include <cstring>
#include <queue>
using namespace std;
#define N 105
struct Point
{
    int fx;
    int x, y;
    int step;
    int num;
    int px, py;
}point;
int move[9][2] = {0,0, 0,-1, 0,1, -1,0, 1,0, -1,-1, -1,1, 1,-1, 1,1};
char map[N][N];
int vis[N][N][9];
int n, max1;
queue<Point>q;

void bfs();
int main()
{
    while(scanf("%d", &n) ,n)
    {
        getchar();
        int i, j;
        for(i=0;i<n;i++)
        {
            gets(map[i]);
        }
        memset(vis, 0, sizeof(vis));
        max1 = 0;
        for(i=0; i<n; i++)
        {
            for(j=0; j<n; j++)
            {
                if(map[i][j] == '.')
                {
                    point.x = i;
                    point.y = j;
                    point.fx = 0;
                    point.step = 1;
                    point.num = -1;
                    point.px = 0;
                    point.py = 0;
                    bfs();
                }
            }
        }
        printf("%d\n", max1);
    }
    return 0;
}

void bfs()
{
    while(!q.empty()) q.pop();
    q.push(point);

    while(!q.empty())
    {
        Point now = q.front();
        q.pop();
        if(now.step > max1)
        {
            max1 = now.step;
        }
        //printf("i=%d, j=%d, num=%d, fx=%d, step=%d, px=%d, py=%d\n", now.x, now.y, now.num, now.fx, now.step, now.px, now.py);
        for(int i=1; i<=8; i++)
        {
            int xx = now.x, yy = now.y;
            Point next = now;
            next.px = now.x;
            next.py = now.y;

            xx += move[i][0];
            yy += move[i][1];
            if(map[xx][yy] == '#') continue;
            if(xx<0 || xx>=n || yy<0 || yy>=n) continue;
            //if(xx==point.x && yy==point.y) continue;
            //printf("%d %d\n", xx, yy);
            if(now.fx>4 && now.fx<=8 && i<=4) continue;
            if(now.fx<=4 && now.fx>0 && i>4) continue;
            if(now.fx != i) next.num++;
            if(next.num > 1) continue;

            next.x = xx;
            next.y = yy;
            next.step++;
            next.fx = i;

            if(next.x==now.px && next.y==now.py) continue;//printf("%d %d %d %d\n", next.x, next.y, next.px, next.py);
            if(!vis[xx][yy][i])
            {
                vis[xx][yy][i] = next.step;
                q.push(next);
                continue;
            }
            if(vis[xx][yy][i] < next.step)
            {
                vis[xx][yy][i] = next.step;
                q.push(next);
                continue;
            }
            /*
            if(now.fx>4 && now.fx<=8 && vis[xx][yy]<=4)
            {
                vis[xx][yy] = i;
                q.push(next);
                continue;
            }
            if(now.fx<=4 && now.fx>0 && vis[xx][yy]>4)
            {
                vis[xx][yy] = i;
                q.push(next);
                continue;
            }
            */
        }
    }
}
/*
6
.###.#
#.#.##
##.###
#.####
##.###
###.##
*/