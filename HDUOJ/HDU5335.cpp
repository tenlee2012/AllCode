//Author LJH
//www.cnblogs.com/tenlee
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#define clc(a, b) memset(a, b, sizeof(a))
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+10;
int MOVE[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
struct Point
{
    int x, y;
    int step;
}p[maxn];
int vis[maxn][maxn];
char g[maxn][maxn];
int n, m;
char ans[maxn*4];
queue<Point> q;
queue<Point> q1;

inline bool judge(int x, int y)
{
    if(x < 0 || x >= n || y < 0 || y >= m) return false;
    return true;
}

void BFS(int x, int y)
{
    while(!q.empty()) q.pop();
    int xx, yy;
    int dis = m+n-2;
    Point s, now, next;
    s.x = x; s.y = x; s.step = 0;
    q.push(s);

    while(!q.empty() && g[x][y] == '0') //开始一直走0
    {
        now = q.front(); q.pop();
        q1.push(now);
        if(n-1-now.x+m-1-now.y < dis) //寻找离终点最近的 0 点 的距离
        {
            dis = n-1-now.x+m-1-now.y;
        }
        for(int i = 0; i < 4; i++)
        {
            xx = now.x + MOVE[i][0];
            yy = now.y + MOVE[i][1];
            if(!judge(xx, yy)) continue;
            if(g[xx][yy] == '1') continue;
            if(vis[xx][yy]) continue;
            vis[xx][yy] = 1;
            next.x = xx; next.y = yy;
            next.step = now.step + 1;
            q.push(next);
        }
    }//q已空

    while(!q1.empty())
    {
        now = q1.front(); q1.pop();
        if(n-1-now.x+m-1-now.y == dis) //把到终点的距离等于dis的0点加入队列
        {
            q.push(now);
        }
    } //q1 已空
    if(dis == 0) //此时说明可以直接走0到终点
    {
        ans[0] = '0';
        ans[1] = '\0';
        return;
    }

    int t = 0; // 所走的路径
    char flag = '1';
    if(dis == n+m-2) ans[t++] = '1';

    while(!q.empty())
    {
        flag = '1';
        while(!q.empty()) //属于同一层的都找出来
        {
            now = q.front(); q.pop();
            //printf("x = %d, y = %d, step = %d\n", now.x, now.y, now.step);
            for(int i = 0; i < 2; i++)
            {
                xx = now.x + MOVE[i][0];
                yy = now.y + MOVE[i][1];
                if(!judge(xx, yy) || vis[xx][yy]) continue;
                vis[xx][yy] = 1;
                if(g[xx][yy] == '0') flag = '0'; //如果该层有0,则把0都挑出来作为下一步
                next.x = xx; next.y = yy; next.step = now.step + 1;
                q1.push(next);
            }
        }
        while(!q1.empty())
        {
            now = q1.front(); q1.pop();
            if(now.x == n-1 && now.y == m-1)
            {
                ans[t++] = g[n-1][m-1];
                ans[t] = '\0';
                return;
            }
            if(g[now.x][now.y] == flag)//如果该层有0,则把0都挑出来作为下一步
            {
                q.push(now);
            }
        }
        ans[t++] = flag;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        clc(vis, 0);
        scanf("%d %d", &n, &m);
        for(int i = 0; i < n; i++)
        {
            scanf("%s", g[i]);
        }
        if(n == 1 && m == 1)
        {
            puts(g[0]);
            continue;
        }
        BFS(0, 0);
        printf("%s\n", ans);
    }
    return 0;
}
