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
const int maxn = 510;
int n, m;
bool edge[maxn][maxn], visit[maxn];
int match[maxn];

bool dfs(int u)
{
    for(int v = 1; v <= n; v++)
    {
        if(edge[u][v] && !visit[v])
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

int hungary()
{
    int sum = 0;
    for(int i = 1; i <= n; i++)
    {
        memset(visit, 0, sizeof(visit));
        if(dfs(i)) sum++;
    }
    return sum;
}
int main()
{
    int x, y;
    while(~scanf("%d %d", &n, &m))
    {
        memset(edge, false, sizeof(edge));
        memset(match, -1 , sizeof(match));
        while(m--)
        {
            scanf("%d %d", &x, &y);
            edge[x][y] = 1;
        }
        printf("%d\n",  hungary());
    }   
    return 0;
}
