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
#define LL long long
using namespace std;

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;

int g[maxn][maxn], dis[maxn];
bool vis[maxn];
int T, S, D, n;

void Dijkstra()
{
    clc(dis, INF);
    clc(vis, 0);
    dis[0] = 0;
    for(int i = 0; i <= n; i++)
    {
        int mark = -1, mindis = INF;
        for(int j = 0; j <= n; j++)
        {
            if(!vis[j] && dis[j] < mindis)
            {
                mindis = dis[j];
                mark = j;
            }
        }
        vis[mark] = 1;
        for(int j = 0; j <= n; j++)
        {
            if(!vis[j])
            {
                dis[j] = min(dis[j], dis[mark]+g[mark][j]);
            }
        }
    }
}

int main()
{
    int a, b, c;
    while(~scanf("%d %d %d", &T, &S, &D))
    {
        clc(g, INF);
        for(int i = 0; i < T; i++)
        {
            scanf("%d %d %d", &a, &b, &c);
            g[a][b] = g[b][a] = g[a][b] < c ? g[a][b] : c;
            n = max(a, n);
            n = max(b, n);
        }
        for(int i = 0; i < S; i++)
        {
            scanf("%d", &a);
            g[0][a] = g[a][0] = 0; //增加源点
        }
        n++;
        for(int i = 0; i < D; i++)
        {
            scanf("%d", &a);
            g[a][n] = g[n][a] = 0; //增加汇点
        }
        Dijkstra();
        printf("%d\n", dis[n]);
    }
    return 0;
}
