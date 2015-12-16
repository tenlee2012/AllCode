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

const int inf = 0x3f;
const int INF = 0x3f3f3f3f;
const int maxn = 200;

int match[maxn];
bool visit[maxn], edge[maxn][maxn];
int n, m;

bool dfs(int u)
{
    for(int v = 0; v < m; v++)
    {
        if(!visit[v] && edge[u][v])
        {
            visit[v] = 1;
            if(match[v] == -1 || dfs(match[v]))
            {
                match[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hungry()
{
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        memset(visit, 0, sizeof(visit));
        if(dfs(i)) ans++;
    }
    return ans;
}

int main()
{
    int q, i, x, y;
    while(scanf("%d", &n) && n)
    {
        scanf("%d %d", &m, &q);
        memset(edge, 0, sizeof(edge));
        memset(match, -1, sizeof(match));
        while(q--)
        {
            scanf("%d %d %d", &i, &x, &y);
            edge[x][y] = 1;
        }
        printf("%d\n", hungry());
    }
    return 0;
}
