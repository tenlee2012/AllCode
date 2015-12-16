#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
int bfs(int m);
struct point
{
    int x, step;
} st;
queue <point> q;
int vis[1000005];
int n, m, t;
int main()
{
    while (~scanf("%d%d", &m, &n))
    {
        st.x = m;
        st.step = 0;
        printf("%d\n", bfs(m));
    }

    return 0;
}

int bfs(int m)
{
    while (!q.empty())
    {
        q.pop();
    }

    memset(vis, 0, sizeof(vis));
    vis[st.x] = 1;
    q.push(st);

    while (!q.empty())
    {
        point now = q.front();
        //printf("==%d==step %d\n", now.x,now.step);

        if (now.x == n)
        {
            return now.step;
        }

        q.pop();

        if (now.x > 0)
        {
            point next = now;
            next.x += -1;

            if (vis[next.x] == 0)
            {
                next.step++;
                vis[next.x] = 1;
                q.push(next);
            }
        }

        if (now.x < n)
        {
            point next = now;
            next.x += 1;

            if (vis[next.x] == 0)
            {
                vis[next.x] = 1;
                next.step++;
                q.push(next);
            }
        }

        if (now.x < 2 * n)
        {
            point next = now;
            next.x += next.x;

            if (vis[next.x] == 0)
            {
                next.step++;
                vis[next.x] = 1;
                q.push(next);
            }
        }

    }
}
