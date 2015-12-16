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

using namespace std;

const int INF=0x3f3f3f3f;
#define maxn 300
int edge[maxn][maxn], q, m;
bool visit[maxn], g[maxn][maxn];
int match[maxn];
struct Task
{
    int id, s, e;
}task[maxn];
void Floyd()
{
    for(int i = 1; i <= q; i++)
    {
        for(int j = 1; j <= q; j++)
        {
            for(int k = 1; k <= q; k++)
            {
                if (edge[j][i] + edge[i][k] < edge[j][k])
                    edge[j][k] = edge[j][i] + edge[i][k];
            }
        }
    }
}

bool dfs(int num)
{
    int u = task[num].id, t1 = task[num].s, d1 = task[num].e;
    for(int i = 0; i < m; i++)
    {
        int v = task[i].id, t2 = task[i].s, d2 = task[i].e;
        //printf("edge = %d m = %d d1 = %d t2 = %d\n", edge[u][v], m, d1, t2);
        if (edge[u][v]!=INF && !visit[i] && t1+d1+edge[u][v]<=t2)
        {
            //puts("hehe");
            visit[i] = true;
            if(match[i] == -1 || dfs(match[i]))
            {
                match[i] = num;
                return true;
            }
        }
    }
    return false;
}
int Hungary()
{
    int ans = 0;
    memset(match, -1, sizeof(match));
    for(int i = 0; i < m; i++)
    {
        memset(visit, false, sizeof(visit));
        if(dfs(i))
            ans++;
        //printf("ans = %d", ans);
    }
    return ans;
}
int main()
{
    int x, p, d, t;
    while(scanf("%d %d", &q, &m) && q+m)
    {
        for(int i = 1; i <= q; i++)
        {
            for(int j = 1; j <= q; j++)
            {
                scanf("%d", &x);
                if(x == -1)
                    edge[i][j] = INF;
                else edge[i][j] = x;
            }
        }
        Floyd();
        for(int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &p, &t, &d);
            task[i].id = p; task[i].s = t; task[i].e = d;
        }
        memset(g, 0, sizeof(g));
        for(int i = 0; i < m; i++)
            for(int j = 0; j < m; j++)
                if(task[j].s >= task[i].e+task[i].s+edge[task[i].id][task[j].id])
                    g[i][j] = 1;
        printf("%d\n", m - Hungary());
    }
}
