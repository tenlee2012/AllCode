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
const int maxn = 305;

int match[maxn];
bool visit[maxn], edge[maxn][85];
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
                //printf("v = %d\n", v);
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
        if(dfs(i)) { ans++;}
    }
    return ans;
}

int main()
{
    int t, p, q;
    while(~scanf("%d", &n))
    {
        m = 7 * 12 + 1;
        memset(edge, 0, sizeof(edge));
        memset(match, -1, sizeof(match));
        
        for(int i = 0; i < n; i++)
        {
            scanf("%d",&t);
            while(t--)
            {
                scanf("%d %d", &p, &q);
                int x = (p-1)*12+q;
                //printf("x = %d\n", x);
                edge[i][x] = 1;
            }
        }
        for(int i = 0; i <= m; i++)
            for(int j = 0; j < n; j++)
                if(edge[j][i]) printf(" %d %d\n", j, i);
        printf("%d\n", hungry());
    }
    return 0;
}
