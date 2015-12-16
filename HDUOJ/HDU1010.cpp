#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
char map[30][30];
int vis[30][30];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, m, t, a, b, flag;

struct point
{
    int x, y, step;
} st;

void dfs(point st);

int main()
{
    //freopen("1.txt", "w", stdout);

    while (~scanf("%d%d%d", &m, &n, &t) && (n + m + t != 0))
    {
        int wall = 0;
        flag = 0;
        memset(map, 0, sizeof(map));

        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf(" %c", &map[i][j]);

                if (map[i][j] == 'S')
                {
                    memset(vis, 0, sizeof(vis));
                    st.x = i;
                    st.y = j;
                    st.step = 0;
                }

                if (map[i][j] == 'D')
                {
                    a = i;
                    b = j;
                }

                if (map[i][j] == 'X')
                {
                    wall++;
                }
            }
        }

        dfs(st);

        if (flag)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}

void dfs(point st)
{
    int xx = abs(a - st.x), yy = abs(b - st.y), tt = t - st.step;;

    //printf("x=%d,y=%d,t=%d,%d\n", st.x, st.y, tt, (tt - xx - yy));
    if(flag == 1)
    {
        return;
    }

    if (tt < 0 || ((tt - xx - yy) % 2 != 0))
    {
        return;
    }
    else
    {
        if (tt == 0)
        {
            if (map[st.x][st.y] == 'D')
            {
                flag = 1;
                return;
            }
            else
            {
                return;
            }

        }
        else
            for (int i = 0; i < 4; i++)
            {
                point next = st;
                next.x = st.x + dx[i], next.y = st.y + dy[i];
                int nx = next.x, ny = next.y;

                if ((map[nx][ny] == '.' || map[nx][ny] == 'D') && nx > 0 && nx <= m && ny > 0 && ny <= n
                        &&    !vis[nx][ny])
                {
                    next.step++;
                    vis[nx][ny] = 1;
                    dfs(next);
                    vis[nx][ny] = 0;
                }
            }

    }
}
